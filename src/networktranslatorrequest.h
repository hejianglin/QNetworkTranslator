#ifndef TRANSLATORREQUEST_H
#define TRANSLATORREQUEST_H

//Qt
#include <QtCore/QString>
#include <QtCore/QSharedDataPointer>

//QNetworkTranslator
#include "networktranslator_global.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class NetworkTranslatorRequestPrivate;
class NetworkTranslatorRequest
{
public:
    explicit NetworkTranslatorRequest();
    NetworkTranslatorRequest(const NetworkTranslatorRequest &other);
    ~NetworkTranslatorRequest();

    NetworkTranslatorRequest &operator=(const NetworkTranslatorRequest &other);

    bool operator==(const NetworkTranslatorRequest &other) const;
    inline bool operator!=(const NetworkTranslatorRequest &other) const
    { return !operator==(other); }

    void setSourceLanguage(LanguageType);
    LanguageType sourceLanguage() const ;

    void setTargetLanguage(LanguageType);
    LanguageType targetLanguage() const;

    void setSource(const QString &);
    QString source() const;

    bool isValid();
    QString errorString() const;

private:
    QSharedDataPointer<NetworkTranslatorRequestPrivate> d;
    friend class NetworkTranslatorRequestPrivate;
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif // TRANSLATORREQUEST_H
