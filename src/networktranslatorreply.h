#ifndef NETWORKTRANSLATORREPLY_H
#define NETWORKTRANSLATORREPLY_H

//Qt
#include <QtCore/QString>
#include <QtCore/QSharedDataPointer>

//QNetworkTranslaotr
#include "networktranslator_global.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class NetworkTranslatorReplyPrivate;
class NetworkTranslatorReply
{
public:
    enum TranslationError
    {
        TranslationError_eNone,
        TranslationError_eRequestError = 10000,
        TranslationError_eConfigError,
        TranslationError_eProtocolGenerteError
    };

    explicit NetworkTranslatorReply();
    NetworkTranslatorReply(const NetworkTranslatorReply &other);
    ~NetworkTranslatorReply();

    NetworkTranslatorReply &operator =(const NetworkTranslatorReply &other);
    bool operator==(const NetworkTranslatorReply &other) const;
    inline bool operator!=(const NetworkTranslatorReply &other) const
    { return !operator==(other); }

    LanguageType sourceLanguage() const;
    LanguageType targetLanguage() const;
    QString source() const;
    QString target() const;
    NetworkTranslatorReply::TranslationError error() const;
    QString errorString() const;

protected:
    void setSourceLanguage(LanguageType);
    void setTargetLanguage(LanguageType);
    void setSource(const QString &);
    void setTarget(const QString &);
    void setError(TranslationError);
    void setErrorString(const QString &);

private:
    QSharedDataPointer<NetworkTranslatorReplyPrivate> d;
    friend class NetworkTranslatorReplyPrivate;
    friend class NetworkTranslatorPrivate;
    friend class NetworkTranslator;
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif // NETWORKTRANSLATORREPLY_H
