//QNetwrokTranslaotr
#include "protocolreader.h"

ProtocolReader::ProtocolReader(LanguageMap *map)
{

}

ProtocolReader::~ProtocolReader()
{

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

QStringList ProtocolReader::source() const
{
    return QStringList();
}

QStringList ProtocolReader::target() const
{
    return QStringList();
}
