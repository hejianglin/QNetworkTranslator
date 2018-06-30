#ifndef PROTOCOLREADERFACTORY_H
#define PROTOCOLREADERFACTORY_H

//QNetworkTranslator
#include "networktranslator_global.h"
#include "protocolreader_baidu.h"
#include "protocolreader_sougou.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class ProtocolReaderFactory
{
public:
    ProtocolReaderFactory()
    {

    }

    virtual ~ProtocolReaderFactory()
    {

    }

    ProtocolReader *create(TranslatorClient client)
    {
        switch (client) {
        case TranslatorClient_eBaidu: return new ProtocolReader_Baidu;
        case TranslatorClient_eSougou : return new ProtocolReader_Sougou;
        default:
            break;
        }
        return new ProtocolReader;
    }
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif // PROTOCOLREADERFACTORY_H
