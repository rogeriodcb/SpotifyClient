#ifndef SPOTIFYCONNECTION_H
#define SPOTIFYCONNECTION_H

#include "../Settings/appsetup.h"
#include <QDialog>
#include <QDesktopServices>
#include <QtDebug>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class SpotifyConnection;
}

class SpotifyConnection : public QDialog
{
    Q_OBJECT

public:
    explicit SpotifyConnection(AppSetup *appSetup, QWidget *parent = nullptr);
    ~SpotifyConnection();

    QNetworkAccessManager *networkManager;

    QString auth(const QString &code, const QString &redirect, const QString &id, const QString &secret);


private slots:

    void on_authenticateButton_clicked();
    void on_dashboardButton_clicked();

private:
    Ui::SpotifyConnection *ui;
    AppSetup *appSetup=nullptr;
    QTcpServer *server=nullptr;
    QString redirect="";
    QString error;
};

#endif // SPOTIFYCONNECTION_H
