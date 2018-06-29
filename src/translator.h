#ifndef TRANSLATOR_H
#define TRANSLATOR_H

//Qt
#include <QtCore/QObject>

//QNetworkTranslator
#include "translator_global.h"
#include "translatorrequest.h"
#include "translatorreply.h"

class QUrl;
class TranslatorPrivate;
class Translator : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Translator)

public:
    Translator(QObject *parent = 0);
    ~Translator();

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

    bool translator(const QString &source);
    bool translator(const QStringList &source);
    bool translator(const TranslatorRequest &request);

signals:
    void finished(TranslatorReply);

private:
    TranslatorPrivate *d_ptr;
    Q_DECLARE_PRIVATE(Translator)
    Q_PRIVATE_SLOT(d_func(),void _q_finished(QNetworkReply *))
};

#endif // TRANSLATOR_H
