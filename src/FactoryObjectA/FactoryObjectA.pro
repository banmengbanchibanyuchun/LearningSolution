QT -= gui

TEMPLATE = lib
DEFINES += OBJECTA_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DESTDIR = $$PWD/../../bin
DEPENDPATH +=$$PWD/../../bin

INCLUDEPATH +=$$PWD/../FactoryObject

SOURCES += \
    CMyDLLIFsWrap.cpp \
    FactoryObjectA.cpp \
    LoaddllA.cpp

HEADERS += \
    CMyDLLIFsWrap.h \
    FactoryObjectA_global.h \
    FactoryObjectA.h \
    LoaddllA.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bin/ -lFactoryObject
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bin/ -lFactoryObjectd
else:unix:!macx: LIBS += -L$$PWD/../../bin/ -lFactoryObject

INCLUDEPATH += $$PWD/../../src/FactoryObject
DEPENDPATH += $$PWD/../../src/FactoryObject
