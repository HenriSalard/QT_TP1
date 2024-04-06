QT       += core gui
QT += xml
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    db_manager.cpp \
    dblist.cpp \
    dbview.cpp \
    gestxml.cpp \
    accueil.cpp \
    login.cpp \
    main.cpp \
    newuser.cpp \
    profil.cpp \
    profils_manager.cpp \
    session.cpp \
    user.cpp \
    userslist.cpp

HEADERS += \
    accueil.h \
    db_manager.h \
    dblist.h \
    dbview.h \
    droits.h \
    gestxml.h \
    login.h \
    newuser.h \
    profil.h \
    profils_manager.h \
    session.h \
    user.h \
    userslist.h

FORMS += \
    accueil.ui \
    dblist.ui \
    dbview.ui \
    login.ui \
    newuser.ui \
    profils_manager.ui \
    userslist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
