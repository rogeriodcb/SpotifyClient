#include "spotifyconnection.h"
#include "ui_spotifyconnection.h"

SpotifyConnection::SpotifyConnection(AppSetup *appSetup, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpotifyConnection)
{
    ui->setupUi(this);

    // initialize private attributes
    networkManager = new QNetworkAccessManager();
    this->appSetup=appSetup;
    server = nullptr;
    redirect = QString("http://localhost:8888");
    error="";
    json = new JsonUtils();

}

SpotifyConnection::~SpotifyConnection()
{
    delete networkManager;
    delete json;
    delete ui;
}

void SpotifyConnection::on_dashboardButton_clicked()
{
    QString url("https://developer.spotify.com/dashboard/applications");
    if (!QDesktopServices::openUrl(QUrl(url)))
            qDebug()<<"Cannot open dashboard spotify." << endl << "Try yourself: https://developer.spotify.com/dashboard/applications" << endl;
}

void SpotifyConnection::on_authenticateButton_clicked()
{
   getSpotifyConnectionCode(ui->clientIDText->toPlainText(),ui->clientSecretIdText->toPlainText());

}

QString SpotifyConnection::getSpotifyConnectionCode(QString clientId,QString clientSecretId)
{
    qDebug() << "Initialize connection. Please wait..." << endl;
    //networkManager = new QNetworkAccessManager();
    QString url;
    QStringList scopes = {
            "playlist-read-collaborative",
            "playlist-read-private",
            "playlist-modify-private",
            "playlist-modify-public",
            "user-follow-read",
            "user-follow-modify",
            "user-library-modify",
            "user-library-read",
            "user-modify-playback-state",
            "user-read-currently-playing",
            "user-read-playback-state",
            "user-read-private",
            "user-read-recently-played",
            "streaming",
            "user-read-email",
            "user-top-read"
        };

    QUrl redirectUrl(redirect);
    url = QString("https://accounts.spotify.com/authorize?client_id=%1&response_type=code&redirect_uri=%2&scope=%3")
            .arg(clientId)
            .arg(QString(redirectUrl.toEncoded()))
            .arg(scopes.join("%20"));

    qDebug() << "1) Openning Url..." << endl;
    QDesktopServices::openUrl(QUrl(url));

    qDebug() << "2) Creating server" << endl;


    server = new QTcpServer(this);
    if (!server->listen(QHostAddress::LocalHost, 8888))
    {
        QMessageBox::warning(this,
                             "server error",
                             QString("failed to start a temporary server on port 8888: %1")
                             .arg(server->errorString()));
        return "failed to start a temporaray server on port 8888";
    }


    qDebug() << "3) Try to connect" << endl;

    QTcpServer::connect(server, &QTcpServer::newConnection, [this,clientId,clientSecretId]()
    {
        // Read
        auto socket = server->nextPendingConnection();
        socket->waitForReadyRead();
        auto response = QString(socket->readAll());

        qDebug() << "4) Verifying code" << endl;

        // Client might want to request favicon or something
        if (!response.contains("?code="))
        {
            socket->close();
            //error = "Client Id or Client Secrete was incorrect.";
            return;
        }
        qDebug() << "5) Code extraction" << endl;

        // GET /?code=<code> HTTP...
        auto left = response.left(response.indexOf(" HTTP"));
        auto code = left.right(left.length() - left.indexOf("?code=") - 6);
        auto status = auth(code, redirect,clientId,clientSecretId);

        qDebug() << "6) Write message in browser" << endl;

        // Write message in the browser
        socket->write(QString("HTTP/1.1 200 OK\r\n\r\n%1")
                      .arg(status.isEmpty()
                           ? "Success ! Now you can return to Spotify Client app."
                           : QString("failed to authenticate: %1").arg(status)).toUtf8());


        socket->flush();
        socket->waitForBytesWritten(3000);
        socket->close();
        // Close it all down if ok
        if (status.isEmpty())

        {
            qDebug() << "7) Finalizing..." << endl;
            if(appSetup!=nullptr)
            {
                qDebug() << "   7.1) set app variables" << endl;

                appSetup->setClientId(clientId);
                appSetup->setClientSecretId(clientSecretId);
                json->writeAppConfig(appSetup);
            }
            else
            {
                qDebug() << "   7.1) Error: application setup attributes were note stored." << endl;
                //error = "Error: application setup attributes were note stored.";
            }

            qDebug() << "8) close server" << endl;

            server->close();
            delete server;
            //delete networkManager;
            //networkManager=nullptr;

            qDebug() << "#debug Token: " << appSetup->getClientToken();

            accept();

        }
        else
        {
            qDebug() << "ERROR: an error ocurr while getting code";
            //error = "an error ocurr while getting code";
        }

    });
    return error;
}


QString SpotifyConnection::auth(const QString &code, const QString &redirect, const QString &id, const QString &secret)
{
    if (code.isEmpty())
        return QString("no code specified");
    QUrl redirectUrl(redirect);

    // Prepare form to send
    auto postData = QString("grant_type=authorization_code&code=%1&redirect_uri=%2")
            .arg(code)
            .arg(QString(redirectUrl.toEncoded()))
            .toUtf8();

    // Prepare request
    QNetworkRequest request(QUrl("https://accounts.spotify.com/api/token"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization",
                         "Basic " + QString("%1:%2").arg(id).arg(secret).toUtf8().toBase64());

    // Send request
    auto reply = networkManager->post(request, postData);

    // Wait for response
    while (!reply->isFinished())
        QCoreApplication::processEvents();
    auto jsonData = QJsonDocument::fromJson(reply->readAll()).object();
    reply->deleteLater();
    if (jsonData.contains("error_description"))
        return jsonData["error_description"].toString();

    // keep access into private attributes in AppSetup class
    appSetup->setClientToken(jsonData["access_token"].toString());
    appSetup->setClientRefreshToken(jsonData["refresh_token"].toString());

    // Everything hopefully went fine
    return QString();
}
