//QNetworkTranslator
#include "protocolgenertor.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

ProtocolGenertor::ProtocolGenertor()
{

}

ProtocolGenertor::~ProtocolGenertor()
{

}

void ProtocolGenertor::setAppID(const QString &)
{

}

QString ProtocolGenertor::appID() const
{
    return QString();
}

void ProtocolGenertor::setAppKey(const QString &)
{

}

QString ProtocolGenertor::appKey() const
{
    return QString();
}

void ProtocolGenertor::setSourceLanguage(LanguageType)
{

}

LanguageType ProtocolGenertor::sourceLanguage() const
{
    return LanguageType_eAuto;
}

void ProtocolGenertor::setTargetLanguage(LanguageType)
{

}

LanguageType ProtocolGenertor::targetLanguage() const
{
    return LanguageType_eNone;
}

void ProtocolGenertor::setSource(const QString &)
{

}

QString ProtocolGenertor::source() const
{
    return QString();
}

bool ProtocolGenertor::isValid()
{
    return false;
}

QString ProtocolGenertor::errorString() const
{
    return QString();
}

QByteArray ProtocolGenertor::generate()
{
    return QByteArray();
}

void ProtocolGenertor::setLanguageMap(LanguageMap *)
{

}

LanguageMap* ProtocolGenertor::languageMap() const
{
    return Q_NULLPTR;
}

NETWORKTRANSLATOR_NAMESPACE_END
