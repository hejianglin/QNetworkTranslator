#ifndef TRANSLATORREPLY_H
#define TRANSLATORREPLY_H

//Qt
#include <QtCore/QString>
#include <QtCore/QSharedDataPointer>

//QNetworkTranslaotr
#include "translator_global.h"

class TranslatorReplyPrivate;
class TranslatorReply
{
public:
    enum TranslatorError
    {
        TranslatorError_eNone
    };

    explicit TranslatorReply();
    TranslatorReply(const TranslatorReply &other);
    ~TranslatorReply();

    TranslatorReply &operator =(const TranslatorReply &other);
    bool operator==(const TranslatorReply &other) const;
    inline bool operator!=(const TranslatorReply &other) const
    { return !operator==(other); }

    LanguageType sourceLanguage() const;
    LanguageType targetLanguage() const;
    QString source() const;
    QString target() const;
    TranslatorReply::TranslatorError error() const;
    QString errorString() const;

protected:
    void setSourceLanguage(LanguageType);
    void setTargetLanguage(LanguageType);
    void setSource(const QString &);
    void setTarget(const QString &);
    void setError(TranslatorError);
    void setErrorString(const QString &);

private:
    QSharedDataPointer<TranslatorReplyPrivate> d;
    friend class TranslatorReplyPrivate;
    friend class Translator;
};

#endif // TRANSLATORREPLY_H
