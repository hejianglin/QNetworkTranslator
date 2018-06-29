#ifndef NETWORKREQUESTFACTORY_H
#define NETWORKREQUESTFACTORY_H

//Qt
#include <QtNetwork/QNetworkRequest>

//QNetworkTranslator
#include "networktranslator_global.h"

///////////////////////////////////////
/// \brief The NetworkRequestFactory class
///
class NetworkRequestFactory
{
public:
    NetworkRequestFactory()
    {

    }

    virtual ~NetworkRequestFactory()
    {

    }

    QNetworkRequest create(TranslatorClient client)
    {
        QNetworkRequest head;
        switch (client)
        {
        case TranslatorClient_eBaidu:
            head.setUrl(QUrl("http://api.fanyi.baidu.com/api/trans/vip/translate"));
            head.setRawHeader("content-type","application/x-www-form-urlencoded");
            head.setRawHeader("accept","application/json");
            break;

        case TranslatorClient_eSougou:
            head.setUrl(QUrl("http://fanyi.sogou.com/reventondc/api/sogouTranslate"));
            head.setRawHeader("content-type","application/x-www-form-urlencoded");
            head.setRawHeader("accept","application/json");
            break;

        default:
            break;
        }
        return head;
    }
};
#endif // NETWORKREQUESTFACTORY_H
