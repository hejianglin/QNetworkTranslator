#ifndef PROTOCOLGENERTORFACTORY_H
#define PROTOCOLGENERTORFACTORY_H

//QNetworkTranslator
#include "networktranslator_global.h"
#include "protocolgenertor.h"
#include "protocolgenertor_baidu.h"

class ProtocolGenertorFactory
{
public:
    ProtocolGenertorFactory()
    {

    }

    virtual ~ProtocolGenertorFactory()
    {

    }

    ProtocolGenertor *create(TranslatorClient client)
    {
        switch (client) {
        case TranslatorClient_eBaidu: return new ProtocolGenertor_Baidu;

            break;
        default:
            break;
        }
        return new ProtocolGenertor;
    }
};


#endif // PROTOCOLGENERTORFACTORY_H
