#ifndef TRANSLATORREQUEST_H
#define TRANSLATORREQUEST_H

//Qt
#include <QtCore/QString>
#include <QtCore/QSharedDataPointer>

//QNetworkTranslator
#include "translator_global.h"

class TranslatorRequestPrivate;
class TranslatorRequest
{
public:
    explicit TranslatorRequest();
    TranslatorRequest(const TranslatorRequest &other);
    ~TranslatorRequest();

    TranslatorRequest &operator=(const TranslatorRequest &other);

    bool operator==(const TranslatorRequest &other) const;
    inline bool operator!=(const TranslatorRequest &other) const
    { return !operator==(other); }

    void setSourceLanguage(LanguageType);
    LanguageType sourceLanguage() const ;

    void setTargetLanguage(LanguageType);
    LanguageType targetLanguage() const;

    void setSource(const QString &);
    QString source() const;

    bool isValid() const;

private:
    QSharedDataPointer<TranslatorRequestPrivate> d;
    friend class TranslatorRequestPrivate;
};

#endif // TRANSLATORREQUEST_H
