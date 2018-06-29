//Qt
#include <QtCore/QObject>
#include <QtCore/QSharedData>

//QNetworkTranslator
#include "networktranslatorrequest.h"

class QNetworkTranslatorRequestPrivate : public QSharedData
{
public:
    inline QNetworkTranslatorRequestPrivate()
        : m_eSourceLanguage(LanguageType_eAuto)
        , m_eTargetLanguage(LanguageType_eNone)
    {}

    QNetworkTranslatorRequestPrivate(const QNetworkTranslatorRequestPrivate &other)
        : QSharedData(other)
    {
        m_eSourceLanguage = other.m_eSourceLanguage;
        m_eTargetLanguage = other.m_eTargetLanguage;
        m_slSource = other.m_slSource;
    }

    inline bool operator==(const QNetworkTranslatorRequestPrivate &other) const
    {
        return m_eSourceLanguage == other.m_eSourceLanguage &&
                m_eTargetLanguage == other.m_eTargetLanguage &&
                m_slSource == other.m_slSource;
    }

    bool isValid()
    {
        if(m_eSourceLanguage < LanguageType_eAuto){
            m_sErrorString = QObject::tr("source language type unset");
            return false;
        }

        if(m_eTargetLanguage <= LanguageType_eAuto){
            m_sErrorString = QObject::tr("target language type unset");
            return false;
        }

        if(m_slSource.isEmpty()){
            m_sErrorString = QObject::tr("source unset");
            return false;
        }
        return true;
    }

    LanguageType m_eSourceLanguage;
    LanguageType m_eTargetLanguage;
    QString m_sErrorString;
    QStringList m_slSource;
};

QNetworkTranslatorRequest::QNetworkTranslatorRequest()
    : d(new QNetworkTranslatorRequestPrivate)
{

}

QNetworkTranslatorRequest::QNetworkTranslatorRequest(const QNetworkTranslatorRequest &other)
    :d(other.d)
{

}

QNetworkTranslatorRequest::~QNetworkTranslatorRequest()
{
    d = 0;
}

QNetworkTranslatorRequest & QNetworkTranslatorRequest::operator=(const QNetworkTranslatorRequest &other)
{
    d = other.d;
    return *this;
}

bool QNetworkTranslatorRequest::operator==(const QNetworkTranslatorRequest &other) const
{
    return d == other.d || *d == *other.d;
}

void QNetworkTranslatorRequest::setSourceLanguage(LanguageType source)
{
    d->m_eSourceLanguage = source;
}

LanguageType QNetworkTranslatorRequest::sourceLanguage() const
{
    return d->m_eSourceLanguage;
}

void QNetworkTranslatorRequest::setTargetLanguage(LanguageType target)
{
    d->m_eTargetLanguage = target;
}

LanguageType QNetworkTranslatorRequest::targetLanguage() const
{
    return d->m_eTargetLanguage;
}

void QNetworkTranslatorRequest::setSource(const QStringList &source)
{
    d->m_slSource = source;
}

QStringList QNetworkTranslatorRequest::source() const
{
    return d->m_slSource;
}

bool QNetworkTranslatorRequest::isValid()
{
    return d->isValid();
}

QString QNetworkTranslatorRequest::errorString() const
{
    return d->m_sErrorString;
}

QNETWORKTRANSLATOR_NAMESPACE_END
