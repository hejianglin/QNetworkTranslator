QT += network

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/protocolreader.h \
    $$PWD/protocolgenertor.h \
    $$PWD/protocolgenertor_baidu.h \
    $$PWD/networkrequestfactory.h \
    $$PWD/languagemap.h \
    $$PWD/protocolreader_baidu.h \
    $$PWD/protocolgenertorfactory.h \
    $$PWD/protocolreaderfactory.h \
    $$PWD/languagemap_baidu.h \
    $$PWD/languagemapfactory.h \
    $$PWD/networktranslator.h \
    $$PWD/languagemap_sougou.h \
    $$PWD/protocolgenertor_sougou.h \
    $$PWD/protocolreader_sougou.h \
    $$PWD/networktranslatorreply.h \
    $$PWD/networktranslator_global.h \
    $$PWD/networktranslator_p.h \
    $$PWD/networktranslatorrequest.h

SOURCES += \
    $$PWD/protocolreader.cpp \
    $$PWD/protocolgenertor_baidu.cpp \
    $$PWD/protocolgenertor.cpp \
    $$PWD/languagemap.cpp \
    $$PWD/protocolreader_baidu.cpp \
    $$PWD/languagemap_baidu.cpp \
    $$PWD/networktranslator.cpp \
    $$PWD/languagemap_sougou.cpp \
    $$PWD/protocolgenertor_sougou.cpp \
    $$PWD/protocolreader_sougou.cpp \
    $$PWD/networktranslatorreply.cpp \
    $$PWD/networktranslatorrequest.cpp
