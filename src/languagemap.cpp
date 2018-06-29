//Qt
#include <QtCore/QMap>

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

class LanguageMapPrivate_Baidu : public QSharedData
{
public:
    LanguageMapPrivate_Baidu()
    {

    }

    void init()
    {
        languageMap.insert(LanguageType_eAuto,"auto");
        languageMap.insert(LanguageType_eZh,"zh");
        languageMap.insert(LanguageType_eEn,"en");
    }

    QMap<LanguageType,QString> languageMap;
};

LanguageMap_Baidu::LanguageMap_Baidu()
    : LanguageMap()
    , d(new LanguageMapPrivate_Baidu)
{
    d->init();
}

LanguageMap_Baidu::~LanguageMap_Baidu()
{
    d = 0;
}

QString LanguageMap_Baidu::languageString(LanguageType type) const
{
    return d->languageMap.value(type);
}

LanguageType LanguageMap_Baidu::languageType(const QString &type) const
{
    QMapIterator<LanguageType, QString> i(d->languageMap);
    while (i.hasNext()) {
        i.next();
        if(i.value() == type)
            return i.key();
    }
    return LanguageType_eNone;
}


