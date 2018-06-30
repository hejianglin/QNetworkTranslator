#ifndef LANGUAGEMAPFACTORY_H
#define LANGUAGEMAPFACTORY_H

//QNetworkTranslator
#include "languagemap.h"
#include "languagemap_baidu.h"
#include "languagemap_sougou.h"


NETWORKTRANSLATOR_NAMESPACE_BEGIN

class LanguageMapFactory
{
public:
    explicit LanguageMapFactory()
    {

    }

    virtual ~LanguageMapFactory()
    {

    }

    LanguageMap *create(TranslatorClient client)
    {
        switch (client)
        {
        case TranslatorClient_eBaidu: return new LanguageMap_Baidu;
        case TranslatorClient_eSougou: return new LanguageMap_Sougou;
        default:   break;
        }
        return new LanguageMap;
    }
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif // LANGUAGEMAPFACTORY_H
