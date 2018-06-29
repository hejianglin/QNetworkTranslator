//QNetworkTranslator
#include "protocolgenertor.h"

ProtocolGenertor::ProtocolGenertor(LanguageMap *)
{}

ProtocolGenertor::~ProtocolGenertor()
{}

void ProtocolGenertor::setAppID(const QString &)
{}

QString ProtocolGenertor::appID() const
{
    return QString();
}

void ProtocolGenertor::setAppKey(const QString &)
{}

QString ProtocolGenertor::appKey() const
{
    return QString();
}

void ProtocolGenertor::setSourceLanguage(LanguageType)
{}

LanguageType ProtocolGenertor::sourceLanguage() const
{
    return LanguageType_eAuto;
}

void ProtocolGenertor::setTargetLanguage(LanguageType)
{}

LanguageType ProtocolGenertor::targetLanguage() const
{
    return LanguageType_eNone;
}

void ProtocolGenertor::setSource(const QString &)
{}

QString ProtocolGenertor::source() const
{
    return QString();
}

QByteArray ProtocolGenertor::generate()
{
    return QByteArray();
}
