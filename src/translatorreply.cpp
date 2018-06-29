//Qt
#include <QtCore/QSharedData>

//QNetworkTranslator
#include "translatorreply.h"

class TranslatorReplyPrivate : public QSharedData
{
public:
    inline TranslatorReplyPrivate()
        : m_eSourceLanguageType(LanguageType_eNone)
        , m_eTargetLanguageType(LanguageType_eNone)
        , m_eError(TranslatorReply::TranslatorError_eNone)
    {

    }

    TranslatorReplyPrivate(const TranslatorReplyPrivate &other)
        : QSharedData(other)
    {
        m_eSourceLanguageType = other.m_eSourceLanguageType;
        m_eTargetLanguageType = other.m_eTargetLanguageType;
        m_sSource = other.m_sSource;
        m_sTarget = other.m_sTarget;
        m_eError = other.m_eError;
        m_sErrorString = other.m_sErrorString;

    }

    inline bool operator==(const TranslatorReplyPrivate &other) const
    {
        return m_eSourceLanguageType == other.m_eSourceLanguageType &&
                m_eTargetLanguageType == other.m_eTargetLanguageType &&
                m_sSource == other.m_sSource &&
                m_sTarget == other.m_sTarget &&
                m_eError == other.m_eError &&
                m_sErrorString == other.m_sErrorString;
    }

    LanguageType m_eSourceLanguageType;
    LanguageType m_eTargetLanguageType;
    QString m_sSource;
    QString m_sTarget;
    TranslatorReply::TranslatorError m_eError;
    QString m_sErrorString;
};


TranslatorReply::TranslatorReply()
    : d(new TranslatorReplyPrivate)
{

}

TranslatorReply::TranslatorReply(const TranslatorReply &other)
    :d(other.d)
{

}

TranslatorReply::~TranslatorReply()
{
    d = 0;
}

TranslatorReply & TranslatorReply::operator=(const TranslatorReply &other)
{
    d = other.d;
    return *this;
}

bool TranslatorReply::operator==(const TranslatorReply &other) const
{
    return d == other.d || *d == *other.d;
}

void TranslatorReply::setSourceLanguage(LanguageType type)
{
    d->m_eSourceLanguageType = type;
}

LanguageType TranslatorReply::sourceLanguage() const
{
    return d->m_eSourceLanguageType;
}

void TranslatorReply::setTargetLanguage(LanguageType type)
{
    d->m_eTargetLanguageType = type;
}

LanguageType TranslatorReply::targetLanguage() const
{
    return d->m_eTargetLanguageType;
}

void TranslatorReply::setSource(const QString &source)
{
    d->m_sSource = source;
}

QString TranslatorReply::source() const
{
    return d->m_sSource;
}

void TranslatorReply::setTarget(const QString &target)
{
    d->m_sTarget = target;
}

QString TranslatorReply::target() const
{
    return d->m_sTarget;
}

void TranslatorReply::setError(TranslatorError error)
{
    d->m_eError = error;
}

TranslatorReply::TranslatorError TranslatorReply::error() const
{
    return d->m_eError;
}

void TranslatorReply::setErrorString(const QString &error)
{
    d->m_sErrorString = error;
}

QString TranslatorReply::errorString() const
{
    return d->m_sErrorString;
}
