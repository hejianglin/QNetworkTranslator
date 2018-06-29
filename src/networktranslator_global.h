#ifndef TRANSLATORGLOBAL_H
#define TRANSLATORGLOBAL_H

#include <QtCore/QtGlobal>

#if defined(QNETWORKTRANSLATOR_LIBRARY)
#  define TRANSLATOR_EXPORT Q_DECL_EXPORT
#else
#  define TRANSLATOR_EXPORT Q_DECL_IMPORT
#endif

#define QNETWORKTRANSLATOR_NAMESPACE_BEGIN
#define QNETWORKTRANSLATOR_NAMESPACE_END
#define USE_QNETWORKTRANSLATOR_NAMESPACE

QNETWORKTRANSLATOR_NAMESPACE_BEGIN
enum LanguageType{
    LanguageType_eNone = -1,
    LanguageType_eAuto,
    LanguageType_eZh,
    LanguageType_eEn,
    LanguageType_eYue,
    LanguageType_eWyW,
    LanguageType_eJp
};

enum TranslatorClient{
    TranslatorClient_eNone,
    TranslatorClient_eBaidu,
    TranslatorClient_eSougou
};
QNETWORKTRANSLATOR_NAMESPACE_END

#endif // TRANSLATORGLOBAL_H
