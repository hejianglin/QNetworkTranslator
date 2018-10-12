#ifndef QNETWORKTRANSLATOR_H
#define QNETWORKTRANSLATOR_H

//Qt
#include <QtCore/QObject>

//QNetworkTranslator
#include "networktranslator_global.h"
#include "networktranslatorrequest.h"
#include "networktranslatorreply.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class QUrl;
class NetworkTranslatorPrivate;
class NetworkTranslator : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(NetworkTranslator)

public:
    NetworkTranslator(QObject *parent = 0);
    ~NetworkTranslator();

    void setTranslatorEngine(TranslationEngine);
    TranslationEngine translatorEngine() const;

    void setTranslatorEngineUrl(const QString &url);
    QString translatorEngineUrl() const;

    void setAppID(const QString &);
    QString appID() const;

    void setAppKey(const QString &);
    QString appKey() const;

    void setDefaultSourceLanguage(LanguageType);
    LanguageType defaultSourceLanguage() const;

    void setDefaultTargetLanguage(LanguageType);
    LanguageType defaultTargetLanguage() const;

    bool isValid();
    QString errorString() const;

    bool translator(const QString &source);
    bool translator(NetworkTranslatorRequest &request);

signals:
    void finished(NetworkTranslatorReply);

private:
    Q_DECLARE_PRIVATE(NetworkTranslator)
    Q_PRIVATE_SLOT(d_func(),void _q_finished(QNetworkReply *))
    NetworkTranslatorPrivate *d_ptr;
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif // QNETWORKTRANSLATOR_H
