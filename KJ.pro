#-------------------------------------------------
#
# Project created by QtCreator 2019-09-09T17:23:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

TARGET = KJ
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
    calculator.cpp \
        main.cpp \
        mainwindow.cpp \
    schemedialog.cpp \
    schemeparams.cpp \
    inputelements.cpp \
    matrix.cpp \
    editionelements.cpp \
    frequencyresponse.cpp \
    calculationparams.cpp \
    elemnetsparams.cpp \
    nodedialog.cpp \
    mybrouser.cpp

HEADERS += \
    calculator.h \
        mainwindow.h \
    schemedialog.h \
    schemeparams.h \
    inputelements.h \
    elementsparams.h \
    matrix.h \
    editionelements.h \
    frequencyresponse.h \
    calculationparams.h \
    nodedialog.h \
    mybrouser.h \
    complex.h

FORMS += \
        mainwindow.ui \
    schemedialog.ui \
    inputelements.ui \
    editionelements.ui \
    frequencyresponse.ui \
    nodedialog.ui \
    mybrouser.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
