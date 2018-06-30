//Qt
#include <QtCore/QObject>
#include <QtCore/QSharedData>

//QNetworkTranslator
#include "networktranslatorrequest.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class NetworkTranslatorRequestPrivate : public QSharedData
{
public:
    inline NetworkTranslatorRequestPrivate()
        : m_eSourceLanguage(LanguageType_eAuto)
        , m_eTargetLanguage(LanguageType_eNone)
    {

    }

    NetworkTranslatorRequestPrivate(const NetworkTranslatorRequestPrivate &other)
        : QSharedData(other)
    {
        m_eSourceLanguage = other.m_eSourceLanguage;
        m_eTargetLanguage = other.m_eTargetLanguage;
        m_sSource = other.m_sSource;
    }

    ~NetworkTranslatorRequestPrivate()
    {

    }

    inline bool operator==(const NetworkTranslatorRequestPrivate &other) const
    {
        return m_eSourceLanguage == other.m_eSourceLanguage &&
                m_eTargetLanguage == other.m_eTargetLanguage &&
                m_sSource == other.m_sSource;
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

        if(m_sSource.isEmpty()){
            m_sErrorString = QObject::tr("source unset");
            return false;
        }
        return true;
    }

    LanguageType m_eSourceLanguage;
    LanguageType m_eTargetLanguage;
    QString m_sErrorString;
    QString m_sSource;
};

NetworkTranslatorRequest::NetworkTranslatorRequest()
    : d(new NetworkTranslatorRequestPrivate)
{

}

NetworkTranslatorRequest::NetworkTranslatorRequest(const NetworkTranslatorRequest &other)
    :d(other.d)
{

}

NetworkTranslatorRequest::~NetworkTranslatorRequest()
{
    d = 0;

}

NetworkTranslatorRequest & NetworkTranslatorRequest::operator=(const NetworkTranslatorRequest &other)
{
    d = other.d;
    return *this;
}

bool NetworkTranslatorRequest::operator==(const NetworkTranslatorRequest &other) const
{
    return d == other.d || *d == *other.d;
}

void NetworkTranslatorRequest::setSourceLanguage(LanguageType source)
{
    d->m_eSourceLanguage = source;
}

LanguageType NetworkTranslatorRequest::sourceLanguage() const
{
    return d->m_eSourceLanguage;
}

void NetworkTranslatorRequest::setTargetLanguage(LanguageType target)
{
    d->m_eTargetLanguage = target;
}

LanguageType NetworkTranslatorRequest::targetLanguage() const
{
    return d->m_eTargetLanguage;
}

void NetworkTranslatorRequest::setSource(const QString &source)
{
    d->m_sSource = source;
}

QString NetworkTranslatorRequest::source() const
{
    return d->m_sSource;
}

bool NetworkTranslatorRequest::isValid()
{
    return d->isValid();
}

QString NetworkTranslatorRequest::errorString() const
{
    return d->m_sErrorString;
}

NETWORKTRANSLATOR_NAMESPACE_END
