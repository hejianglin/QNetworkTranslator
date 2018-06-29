#ifndef TRANSLATOR_H
#define TRANSLATOR_H

//Qt
#include <QtCore/QObject>

//QNetworkTranslator
#include "networktranslator_global.h"
#include "networktranslatorrequest.h"
#include "networktranslatorreply.h"

class QUrl;
class QNetworkTranslatorPrivate;
class QNetworkTranslator : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QNetworkTranslator)

public:
    QNetworkTranslator(QObject *parent = 0);
    ~QNetworkTranslator();

    void setTranslatorClient(TranslatorClient);
    TranslatorClient translatorClient() const;

    void setTranslatorClientUrl(const QString &url);
    QString translatorClientUrl() const;

    void setAppID(const QString &);
    QString appID() const;

    void setAppKey(const QString &);
    QString appKey() const;

    void setDefaultSourceLanguage(LanguageType);
    LanguageType defaultSourceLanguage() const;

    void setDefaultTargetLanguage(LanguageType);
    LanguageType defaultTargetLanguage() const;

    QString errorString() const;

    bool translator(const QString &source);
    bool translator(const QStringList &source);
    bool translator(QNetworkTranslatorRequest &request);

signals:
    void finished(QNetworkTranslatorReply);

private:
    Q_DECLARE_PRIVATE(QNetworkTranslator)
    Q_PRIVATE_SLOT(d_func(),void _q_finished(QNetworkReply *))
    QNetworkTranslatorPrivate *d_ptr;
};

#endif // TRANSLATOR_H
