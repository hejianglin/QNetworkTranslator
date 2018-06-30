//Qt
#include <QtCore/QSharedData>

//QNetworkTranslator
#include "networktranslatorreply.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class NetworkTranslatorReplyPrivate : public QSharedData
{
public:
    inline NetworkTranslatorReplyPrivate()
        : m_eSourceLanguageType(LanguageType_eNone)
        , m_eTargetLanguageType(LanguageType_eNone)
        , m_eError(NetworkTranslatorReply::TranslatorError_eNone)
    {

    }

    ~NetworkTranslatorReplyPrivate()
    {

    }

    NetworkTranslatorReplyPrivate(const NetworkTranslatorReplyPrivate &other)
        : QSharedData(other)
    {
        m_eSourceLanguageType = other.m_eSourceLanguageType;
        m_eTargetLanguageType = other.m_eTargetLanguageType;
        m_sSource = other.m_sSource;
        m_sTarget = other.m_sTarget;
        m_eError = other.m_eError;
        m_sErrorString = other.m_sErrorString;

    }

    inline bool operator==(const NetworkTranslatorReplyPrivate &other) const
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
    NetworkTranslatorReply::TranslatorError m_eError;
    QString m_sErrorString;
};


NetworkTranslatorReply::NetworkTranslatorReply()
    : d(new NetworkTranslatorReplyPrivate)
{

}

NetworkTranslatorReply::NetworkTranslatorReply(const NetworkTranslatorReply &other)
    :d(other.d)
{

}

NetworkTranslatorReply::~NetworkTranslatorReply()
{
   d = 0;

}

NetworkTranslatorReply & NetworkTranslatorReply::operator=(const NetworkTranslatorReply &other)
{
    d = other.d;
    return *this;
}

bool NetworkTranslatorReply::operator==(const NetworkTranslatorReply &other) const
{
    return d == other.d || *d == *other.d;
}

void NetworkTranslatorReply::setSourceLanguage(LanguageType type)
{
    d->m_eSourceLanguageType = type;
}

LanguageType NetworkTranslatorReply::sourceLanguage() const
{
    return d->m_eSourceLanguageType;
}

void NetworkTranslatorReply::setTargetLanguage(LanguageType type)
{
    d->m_eTargetLanguageType = type;
}

LanguageType NetworkTranslatorReply::targetLanguage() const
{
    return d->m_eTargetLanguageType;
}

void NetworkTranslatorReply::setSource(const QString &source)
{
    d->m_sSource = source;
}

QString NetworkTranslatorReply::source() const
{
    return d->m_sSource;
}

void NetworkTranslatorReply::setTarget(const QString &target)
{
    d->m_sTarget = target;
}

QString NetworkTranslatorReply::target() const
{
    return d->m_sTarget;
}

void NetworkTranslatorReply::setError(TranslatorError error)
{
    d->m_eError = error;
}

NetworkTranslatorReply::TranslatorError NetworkTranslatorReply::error() const
{
    return d->m_eError;
}

void NetworkTranslatorReply::setErrorString(const QString &error)
{
    d->m_sErrorString = error;
}

QString NetworkTranslatorReply::errorString() const
{
    return d->m_sErrorString;
}

NETWORKTRANSLATOR_NAMESPACE_END
