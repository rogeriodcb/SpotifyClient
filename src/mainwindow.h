#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoadButton_clicked();

    void on_SaveButton_clicked();

    void on_SearchButton_clicked();

    void on_PlayButton_clicked();

    void on_StopButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H