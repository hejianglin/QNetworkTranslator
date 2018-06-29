#ifndef TRANSLATORREQUEST_H
#define TRANSLATORREQUEST_H

//Qt
#include <QtCore/QString>
#include <QtCore/QSharedDataPointer>

//QNetworkTranslator
#include "networktranslator_global.h"

class QNetworkTranslatorRequestPrivate;
class QNetworkTranslatorRequest
{
public:
    explicit QNetworkTranslatorRequest();
    QNetworkTranslatorRequest(const QNetworkTranslatorRequest &other);
    ~QNetworkTranslatorRequest();

    QNetworkTranslatorRequest &operator=(const QNetworkTranslatorRequest &other);

    bool operator==(const QNetworkTranslatorRequest &other) const;
    inline bool operator!=(const QNetworkTranslatorRequest &other) const
    { return !operator==(other); }

    void setSourceLanguage(LanguageType);
    LanguageType sourceLanguage() const ;

    void setTargetLanguage(LanguageType);
    LanguageType targetLanguage() const;

    void setSource(const QStringList &);
    QStringList source() const;

    bool isValid();
    QString errorString() const;

private:
    QSharedDataPointer<QNetworkTranslatorRequestPrivate> d;
    friend class QNetworkTranslatorRequestPrivate;
};

#endif // TRANSLATORREQUEST_H
