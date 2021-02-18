QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DESTDIR =$$PWD/../../bin

SOURCES += \
    AngleRectView.cpp \
    drawtext.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AngleRectView.h \
    drawtext.h \
    form.h \
    mainwindow.h

FORMS += \
    AngleRectView.ui \
    drawtext.ui \
    form.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/binDDD
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DEFINES +=Qt_NO_CAST_FROM_ASCII
