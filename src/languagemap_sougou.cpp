//Qt
#include <QtCore/QMap>

//QNetworkTranslator
#include "languagemap_sougou.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class LanguageMapPrivate_Sougou : public QSharedData
{
public:
    LanguageMapPrivate_Sougou()
    {

    }

    void init()
    {
        languageMap.insert(LanguageType_eAuto,"auto");
        languageMap.insert(LanguageType_eZh_Simplified,"zh-CHS");
        languageMap.insert(LanguageType_eEn,"en");
    }

    QMap<LanguageType,QString> languageMap;
};

LanguageMap_Sougou::LanguageMap_Sougou()
    : LanguageMap()
    , d(new LanguageMapPrivate_Sougou)
{
    d->init();
}

LanguageMap_Sougou::~LanguageMap_Sougou()
{
    d = 0;
}

QString LanguageMap_Sougou::languageString(LanguageType type) const
{
    return d->languageMap.value(type);
}

LanguageType LanguageMap_Sougou::languageType(const QString &type) const
{
    QMapIterator<LanguageType, QString> i(d->languageMap);
    while (i.hasNext()) {
        i.next();
        if(i.value() == type)
            return i.key();
    }
    return LanguageType_eNone;
}

NETWORKTRANSLATOR_NAMESPACE_END
