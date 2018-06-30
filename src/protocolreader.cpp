//QNetwrokTranslaotr
#include "protocolreader.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

ProtocolReader::ProtocolReader()
{

}

ProtocolReader::~ProtocolReader()
{

}

void ProtocolReader::setLanguageMap(LanguageMap *)
{

}

LanguageMap *ProtocolReader::languageMap() const
{
    return Q_NULLPTR;
}

void ProtocolReader::read(const QByteArray &)
{

}

void ProtocolReader::read(const QString &)
{

}

LanguageType ProtocolReader::sourceLanguage() const
{
    return LanguageType_eNone;
}

LanguageType ProtocolReader::targetLanguage() const
{
    return LanguageType_eNone;
}

QString ProtocolReader::source() const
{
    return QString();
}

QString ProtocolReader::target() const
{
    return QString();
}

int ProtocolReader::error() const
{
    return 0;
}

QString ProtocolReader::errorString() const
{
    return QString();
}

NETWORKTRANSLATOR_NAMESPACE_END
