QT       += core gui
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gestxml.cpp \
    accueil.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    newuser.cpp \
    profil.cpp \
    session.cpp \
    user.cpp

HEADERS += \
    accueil.h \
    droits.h \
    gestxml.h \
    login.h \
    mainwindow.h \
    newuser.h \
    profil.h \
    session.h \
    user.h

FORMS += \
    accueil.ui \
    login.ui \
    mainwindow.ui \
    newuser.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
