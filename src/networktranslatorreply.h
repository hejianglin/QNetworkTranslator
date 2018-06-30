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
    enum TranslatorError
    {
        TranslatorError_eNone
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
    NetworkTranslatorReply::TranslatorError error() const;
    QString errorString() const;

protected:
    void setSourceLanguage(LanguageType);
    void setTargetLanguage(LanguageType);
    void setSource(const QString &);
    void setTarget(const QString &);
    void setError(TranslatorError);
    void setErrorString(const QString &);

private:
    QSharedDataPointer<NetworkTranslatorReplyPrivate> d;
    friend class NetworkTranslatorReplyPrivate;
    friend class NetworkTranslatorPrivate;
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif // NETWORKTRANSLATORREPLY_H
