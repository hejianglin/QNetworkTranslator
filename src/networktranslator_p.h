#ifndef TRANSLATOR_P_H
#define TRANSLATOR_P_H

//Qt
#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>

//QNetworkTranslator
#include "languagemap.h"
#include "protocolgenertor.h"
#include "protocolreader.h"
#include "networktranslator_global.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class NetworkTranslator;
class NetworkTranslatorPrivate
{
    Q_DECLARE_PUBLIC(NetworkTranslator)
public:
    NetworkTranslatorPrivate(NetworkTranslator *q);
    ~NetworkTranslatorPrivate();

    void init();
    bool isValid();

    TranslationClient m_eClient;
    LanguageType m_eSourceLanguage_Default;
    LanguageType m_eTargetLanguage_Default;
    QString m_sClientUrl;
    QString m_sAppID;
    QString m_sAppKey;
    QString m_sErrorString;
    QNetworkAccessManager m_cNetworkAccessManager;

    QNetworkRequest m_cRequestHead;
    LanguageMap *m_cLanguageMap;
    ProtocolGenertor *m_cProtocolGenertor;
    ProtocolReader *m_cProtocolRead;

    //slot
    void _q_finished(QNetworkReply *);

    NetworkTranslator *q_ptr;
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif // TRANSLATOR_P_H
