#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>

#include "Spotify/spotify.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // open QT main UI
    ui->setupUi(this);

    // initialize attributes
    spotify = nullptr;
    this->installEventFilter(this);


}

MainWindow::~MainWindow()
{

    if(spotify !=nullptr)
        delete spotify;
    delete ui;
    qDebug() << "Thank you for using the Spotify Client application.";
}

bool MainWindow::eventFilter(QObject * obj, QEvent * event)
{
    if(obj == this && event->type() == QEvent::Show)
    {
        QTimer::singleShot(50, this, SLOT(initialize()));
    }

    return false;
}

void MainWindow::initialize()
{
    // try to connect to Spotify
    spotify = new Spotify(this);
    ui->PlayList->addItems(spotify->loadPlayList());

}

void MainWindow::on_LoadButton_clicked()
{
    ui->PlayList->clear();
    ui->PlayList->addItems(spotify->loadPlayList());
}

void MainWindow::on_SaveButton_clicked()
{
    qDebug() << "#debug: Save button pressed";
}

void MainWindow::on_SearchButton_clicked()
{
   qDebug() << "Start searching...";
   QJsonDocument json=spotify->spotifySearch(ui->SearchText->toPlainText(),"track");


   if (json ==QJsonDocument::fromJson(""))
   {
       ui->SearchList->addItem("no search result");
       qDebug() << "No search results.";
       return;
   }
   qDebug()<<"Json read: " << endl << json;

   // TODO: implement the json parser for the search

   /*
   auto jsonObject = json.object();
   JsonUtils *jutils = new JsonUtils();
   ui->SearchList->addItems(jutils->getTrackInfo(jsonObject));
   delete jutils;
   */

   qDebug() << "Search done.";
}

void MainWindow::on_PlayButton_clicked()
{
    qDebug() << "#debug: Play button pressed";

}

void MainWindow::on_StopButton_clicked()
{
    qDebug() << "#debug: Stop button pressed";

}

void MainWindow::on_ExitButton_clicked()
{
    QApplication::exit();
}
