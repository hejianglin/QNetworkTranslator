//Qt
#include <QtCore/QSharedData>

//QNetworkTranslator
#include "translatorrequest.h"

class TranslatorRequestPrivate : public QSharedData
{
public:
    inline TranslatorRequestPrivate()
        : m_eSourceLanguage(LanguageType_eAuto)
        , m_eTargetLanguage(LanguageType_eNone)
    {}

    TranslatorRequestPrivate(const TranslatorRequestPrivate &other)
        : QSharedData(other)
    {
        m_eSourceLanguage = other.m_eSourceLanguage;
        m_eTargetLanguage = other.m_eTargetLanguage;
        m_sSource = other.m_sSource;
    }

    inline bool operator==(const TranslatorRequestPrivate &other) const
    {
        return m_eSourceLanguage == other.m_eSourceLanguage &&
                m_eTargetLanguage == other.m_eTargetLanguage &&
                m_sSource == other.m_sSource;
    }

    bool isValid() const
    {
        if(m_eSourceLanguage < LanguageType_eAuto){
            return false;
        }

        if(m_eTargetLanguage <= LanguageType_eAuto){
            return false;
        }

        if(m_sSource.isEmpty()){
            return false;
        }
        return true;
    }

    LanguageType m_eSourceLanguage;
    LanguageType m_eTargetLanguage;
    QString m_sSource;
};

TranslatorRequest::TranslatorRequest()
    : d(new TranslatorRequestPrivate)
{

}

TranslatorRequest::TranslatorRequest(const TranslatorRequest &other)
    :d(other.d)
{

}

TranslatorRequest::~TranslatorRequest()
{
    d = 0;
}

TranslatorRequest & TranslatorRequest::operator=(const TranslatorRequest &other)
{
    d = other.d;
    return *this;
}

bool TranslatorRequest::operator==(const TranslatorRequest &other) const
{
    return d == other.d || *d == *other.d;
}

void TranslatorRequest::setSourceLanguage(LanguageType source)
{
    d->m_eSourceLanguage = source;
}

LanguageType TranslatorRequest::sourceLanguage() const
{
    return d->m_eSourceLanguage;
}

void TranslatorRequest::setTargetLanguage(LanguageType target)
{
    d->m_eTargetLanguage = target;
}

LanguageType TranslatorRequest::targetLanguage() const
{
    return d->m_eTargetLanguage;
}

void TranslatorRequest::setSource(const QString &source)
{
    d->m_sSource = source;
}

QString TranslatorRequest::source() const
{
    return d->m_sSource;
}

bool TranslatorRequest::isValid() const
{
    return d->isValid();
}
TRANSLATOR_NAMESPACE_END
