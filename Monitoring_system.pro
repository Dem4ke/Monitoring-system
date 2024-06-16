QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
TARGET = Monitoring_system
TEMPLATE = app
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choosetheproject.cpp \
    createaccount.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    server.cpp \
    signin.cpp \
    workwindow.cpp

HEADERS += \
    choosetheproject.h \
    createaccount.h \
    mainwindow.h \
    qcustomplot.h \
    server.h \
    signin.h \
    workwindow.h

FORMS += \
    choosetheproject.ui \
    createaccount.ui \
    mainwindow.ui \
    signin.ui \
    workwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
