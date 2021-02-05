#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    // open QT main UI
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoadButton_clicked()
{
    qDebug() << "#debug: Load button pressed";
}

void MainWindow::on_SaveButton_clicked()
{
    qDebug() << "#debug: Save button pressed";

}

void MainWindow::on_SearchButton_clicked()
{
    qDebug() << "#debug: Search button pressed";

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
    qDebug() << "#debug: Exit button pressed";

}
