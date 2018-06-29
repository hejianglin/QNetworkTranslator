//QNetworkTranslator
#include "protocolgenertor.h"

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

void ProtocolGenertor::setSource(const QStringList &)
{

}

QStringList ProtocolGenertor::source() const
{
    return QStringList();
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
