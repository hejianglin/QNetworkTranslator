#ifndef TRANSLATORGLOBAL_H
#define TRANSLATORGLOBAL_H

#include <QtCore/QtGlobal>

#if defined(TRANSLATOR_LIBRARY)
#  define TRANSLATOR_EXPORT Q_DECL_EXPORT
#else
#  define TRANSLATOR_EXPORT Q_DECL_IMPORT
#endif

#define TRANSLATOR_NAMESPACE_BEGIN
#define TRANSLATOR_NAMESPACE_END
#define USE_TRANSLATOR_NAMESPACE

TRANSLATOR_NAMESPACE_BEGIN
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
TRANSLATOR_NAMESPACE_END

//debug
#if defined (PRINT_DEBUG_INFO)
#include <QDebug>
#define DEBUG(x) do{qDebug()<<"file: "<<__FILE__<<" [ line:"<< __LINE__<<"]"<<x;}while(0);
#else
#define DEBUG(x) do{}while(0);
#endif

#endif // TRANSLATORGLOBAL_H
