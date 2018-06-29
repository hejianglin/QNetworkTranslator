//QNetwrokTranslaotr
#include "protocolreader.h"

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

QStringList ProtocolReader::source() const
{
    return QStringList();
}

QStringList ProtocolReader::target() const
{
    return QStringList();
}

int ProtocolReader::error() const
{
    return 0;
}

QString ProtocolReader::errorString() const
{
    return QString();
}
