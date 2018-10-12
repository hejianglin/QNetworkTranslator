#ifndef PROTOCOLGENERTORFACTORY_H
#define PROTOCOLGENERTORFACTORY_H

//QNetworkTranslator
#include "networktranslator_global.h"
#include "protocolgenertor.h"
#include "protocolgenertor_baidu.h"
#include "protocolgenertor_sougou.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class ProtocolGenertorFactory
{
public:
    ProtocolGenertorFactory()
    {

    }

    virtual ~ProtocolGenertorFactory()
    {

    }

    ProtocolGenertor *create(TranslationEngine engine)
    {
        switch (engine) {
        case TranslationEngine_eBaidu: return new ProtocolGenertor_Baidu;
        case TranslationEngine_eSougou: return new ProtocolGenertor_Sougou;
        default:
            break;
        }
        return new ProtocolGenertor;
    }
};

NETWORKTRANSLATOR_NAMESPACE_END


#endif // PROTOCOLGENERTORFACTORY_H
