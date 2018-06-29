//QNetworkTranslator
#include "languagemap.h"

LanguageMap::LanguageMap()
{

}

LanguageMap::~LanguageMap()
{

}

LanguageType LanguageMap::languageType(const QString &) const
{
    return LanguageType_eNone;
}

QString LanguageMap::languageString(LanguageType) const
{
    return QString();
}

