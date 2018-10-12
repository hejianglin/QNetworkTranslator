#ifndef NETWORKREQUESTFACTORY_H
#define NETWORKREQUESTFACTORY_H

//Qt
#include <QtCore/QUrl>
#include <QtNetwork/QNetworkRequest>

//QNetworkTranslator
#include "networktranslator_global.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class NetworkRequestFactory
{
public:
    NetworkRequestFactory()
    {

    }

    virtual ~NetworkRequestFactory()
    {

    }

    QNetworkRequest create(TranslationEngine engine)
    {
        QNetworkRequest head;
        switch (engine)
        {
        case TranslationEngine_eBaidu:
            head.setUrl(QUrl("http://api.fanyi.baidu.com/api/trans/vip/translate"));
            head.setRawHeader("content-type","application/x-www-form-urlencoded");
            head.setRawHeader("accept","application/json");
            break;

        case TranslationEngine_eSougou:
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

NETWORKTRANSLATOR_NAMESPACE_END
#endif // NETWORKREQUESTFACTORY_H
