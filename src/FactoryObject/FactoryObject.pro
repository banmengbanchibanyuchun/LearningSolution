QT -= gui

TEMPLATE = lib
DEFINES += FACTORYOBJECT_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG( release, debug|release):TARGET =FactoryObject
CONFIG( debug, debug|release):TARGET =FactoryObjectd


DESTDIR = $$PWD/../../bin
DEPENDPATH +=$$PWD/../../bin

SOURCES += \
    IDLLIFsWrap.cpp \
    LoadDllFactory.cpp \
    LoadIDll.cpp \
    classinfo.cpp \
    factoryobject.cpp \
    object.cpp

HEADERS += \
    FactoryObject_global.h \
    IDLLIFsWrap.h \
    LoadDllFactory.h \
    LoadIDll.h \
    classinfo.h \
    factoryobject.h \
 \   # stdafx.h
    object.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
