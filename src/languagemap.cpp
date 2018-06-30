//QNetworkTranslator
#include "languagemap.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

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

NETWORKTRANSLATOR_NAMESPACE_END
