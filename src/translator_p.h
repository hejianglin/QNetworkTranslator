#ifndef TRANSLATOR_P_H
#define TRANSLATOR_P_H

//Qt
#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>

//QNetworkTranslator
#include "translator_global.h"

class Translator;
class TranslatorPrivate
{
    Q_DECLARE_PUBLIC(Translator)
public:
    TranslatorPrivate(Translator *q);
    ~TranslatorPrivate();

    bool isValid() const;

    TranslatorClient m_eClient;
    LanguageType m_eSourceLanguage_Default;
    LanguageType m_eTargetLanguage_Default;
    QString m_sClientUrl;
    QString m_sAppID;
    QString m_sAppKey;
    QNetworkAccessManager networkAccessManager;

    //slot
    void _q_finished(QNetworkReply *);

    Translator *q_ptr;
};


#endif // TRANSLATOR_P_H
