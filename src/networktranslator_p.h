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

class QNetworkTranslator;
class QNetworkTranslatorPrivate
{
    Q_DECLARE_PUBLIC(QNetworkTranslator)
public:
    QNetworkTranslatorPrivate(QNetworkTranslator *q);
    ~QNetworkTranslatorPrivate();

    void init();
    bool isValid();

    TranslatorClient m_eClient;
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

    QNetworkTranslator *q_ptr;
};


#endif // TRANSLATOR_P_H
