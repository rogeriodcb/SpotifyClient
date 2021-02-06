QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Dialogs/spotifyconnection.cpp \
    Settings/appsetup.cpp \
    Spotify/spotify.cpp \
    Utils/jsonutils.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Dialogs/spotifyconnection.h \
    Settings/appsetup.h \
    Spotify/spotify.h \
    Utils/jsonutils.h \
    mainwindow.h \
    version.hpp

FORMS += \
    Dialogs/spotifyconnection.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
