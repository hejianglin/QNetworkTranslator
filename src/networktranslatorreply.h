#ifndef TRANSLATORREPLY_H
#define TRANSLATORREPLY_H

//Qt
#include <QtCore/QString>
#include <QtCore/QSharedDataPointer>

//QNetworkTranslaotr
#include "networktranslator_global.h"

class QNetworkTranslatorReplyPrivate;
class QNetworkTranslatorReply
{
public:
    enum TranslatorError
    {
        TranslatorError_eNone
    };

    explicit QNetworkTranslatorReply();
    QNetworkTranslatorReply(const QNetworkTranslatorReply &other);
    ~QNetworkTranslatorReply();

    QNetworkTranslatorReply &operator =(const QNetworkTranslatorReply &other);
    bool operator==(const QNetworkTranslatorReply &other) const;
    inline bool operator!=(const QNetworkTranslatorReply &other) const
    { return !operator==(other); }

    LanguageType sourceLanguage() const;
    LanguageType targetLanguage() const;
    QStringList source() const;
    QStringList target() const;
    QNetworkTranslatorReply::TranslatorError error() const;
    QString errorString() const;

protected:
    void setSourceLanguage(LanguageType);
    void setTargetLanguage(LanguageType);
    void setSource(const QStringList &);
    void setTarget(const QStringList &);
    void setError(TranslatorError);
    void setErrorString(const QString &);

private:
    QSharedDataPointer<QNetworkTranslatorReplyPrivate> d;
    friend class QNetworkTranslatorReplyPrivate;
    friend class QNetworkTranslatorPrivate;
};

#endif // TRANSLATORREPLY_H
