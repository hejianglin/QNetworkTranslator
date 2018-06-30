#ifndef NETWORKTRANSLATORGLOBAL_H
#define NETWORKTRANSLATORGLOBAL_H

#include <QtCore/QtGlobal>

#if defined(NETWORKTRANSLATOR_LIBRARY)
#  define TRANSLATOR_EXPORT Q_DECL_EXPORT
#else
#  define TRANSLATOR_EXPORT Q_DECL_IMPORT
#endif

#define NETWORKTRANSLATOR_NAMESPACE_BEGIN
#define NETWORKTRANSLATOR_NAMESPACE_END
#define USE_NETWORKTRANSLATOR_NAMESPACE

NETWORKTRANSLATOR_NAMESPACE_BEGIN
enum LanguageType{
    LanguageType_eNone = -1,
    LanguageType_eAuto,
    LanguageType_eZh_Simplified,
    LanguageType_eZh_Traditional,
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
NETWORKTRANSLATOR_NAMESPACE_END

#endif // NETWORKTRANSLATORGLOBAL_H
