QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH +=$$PWD/../FremlessWidget

DESTDIR =$$PWD/../../bin

SOURCES += \
    fremless.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    fremless.h \
    mainwindow.h

FORMS += \
    fremless.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

LIBS+= -L$$PWD/../../bin/ -lFremlessWidget
