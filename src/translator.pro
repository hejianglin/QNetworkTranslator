QT += core network
QT -= gui

CONFIG += c++11

TARGET = translator
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
#DEFINES += TRANSLATOR_LIBRARY //lib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += PRINT_DEBUG_INFO

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    protocolreader.h \
    protocolgenertor.h \
    protocolgenertor_baidu.h \
    translator.h \
    networkrequestfactory.h \
    languagemap.h \
    translatorrequest.h \
    translatorreply.h \
    translator_p.h \
    translator_global.h \
    protocolreader_baidu.h

SOURCES += main.cpp \
    protocolreader.cpp \
    protocolgenertor_baidu.cpp \
    protocolgenertor.cpp \
    translator.cpp \
    languagemap.cpp \
    translatorrequest.cpp \
    translatorreply.cpp \
    protocolreader_baidu.cpp
