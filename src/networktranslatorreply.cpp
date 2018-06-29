//Qt
#include <QtCore/QSharedData>

//QNetworkTranslator
#include "networktranslatorreply.h"

class QNetworkTranslatorReplyPrivate : public QSharedData
{
public:
    inline QNetworkTranslatorReplyPrivate()
        : m_eSourceLanguageType(LanguageType_eNone)
        , m_eTargetLanguageType(LanguageType_eNone)
        , m_eError(QNetworkTranslatorReply::TranslatorError_eNone)
    {

    }

    QNetworkTranslatorReplyPrivate(const QNetworkTranslatorReplyPrivate &other)
        : QSharedData(other)
    {
        m_eSourceLanguageType = other.m_eSourceLanguageType;
        m_eTargetLanguageType = other.m_eTargetLanguageType;
        m_slSource = other.m_slSource;
        m_slTarget = other.m_slTarget;
        m_eError = other.m_eError;
        m_sErrorString = other.m_sErrorString;

    }

    inline bool operator==(const QNetworkTranslatorReplyPrivate &other) const
    {
        return m_eSourceLanguageType == other.m_eSourceLanguageType &&
                m_eTargetLanguageType == other.m_eTargetLanguageType &&
                m_slSource == other.m_slSource &&
                m_slTarget == other.m_slTarget &&
                m_eError == other.m_eError &&
                m_sErrorString == other.m_sErrorString;
    }

    LanguageType m_eSourceLanguageType;
    LanguageType m_eTargetLanguageType;
    QStringList m_slSource;
    QStringList m_slTarget;
    QNetworkTranslatorReply::TranslatorError m_eError;
    QString m_sErrorString;
};


QNetworkTranslatorReply::QNetworkTranslatorReply()
    : d(new QNetworkTranslatorReplyPrivate)
{

}

QNetworkTranslatorReply::QNetworkTranslatorReply(const QNetworkTranslatorReply &other)
    :d(other.d)
{

}

QNetworkTranslatorReply::~QNetworkTranslatorReply()
{
    d = 0;
}

QNetworkTranslatorReply & QNetworkTranslatorReply::operator=(const QNetworkTranslatorReply &other)
{
    d = other.d;
    return *this;
}

bool QNetworkTranslatorReply::operator==(const QNetworkTranslatorReply &other) const
{
    return d == other.d || *d == *other.d;
}

void QNetworkTranslatorReply::setSourceLanguage(LanguageType type)
{
    d->m_eSourceLanguageType = type;
}

LanguageType QNetworkTranslatorReply::sourceLanguage() const
{
    return d->m_eSourceLanguageType;
}

void QNetworkTranslatorReply::setTargetLanguage(LanguageType type)
{
    d->m_eTargetLanguageType = type;
}

LanguageType QNetworkTranslatorReply::targetLanguage() const
{
    return d->m_eTargetLanguageType;
}

void QNetworkTranslatorReply::setSource(const QStringList &source)
{
    d->m_slSource = source;
}

QStringList QNetworkTranslatorReply::source() const
{
    return d->m_slSource;
}

void QNetworkTranslatorReply::setTarget(const QStringList &target)
{
    d->m_slTarget = target;
}

QStringList QNetworkTranslatorReply::target() const
{
    return d->m_slTarget;
}

void QNetworkTranslatorReply::setError(TranslatorError error)
{
    d->m_eError = error;
}

QNetworkTranslatorReply::TranslatorError QNetworkTranslatorReply::error() const
{
    return d->m_eError;
}

void QNetworkTranslatorReply::setErrorString(const QString &error)
{
    d->m_sErrorString = error;
}

QString QNetworkTranslatorReply::errorString() const
{
    return d->m_sErrorString;
}
