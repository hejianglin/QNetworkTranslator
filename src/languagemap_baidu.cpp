//Qt
#include <QtCore/QMap>
#include <QtCore/QString>

//QNetworkTranslator
#include "languagemap_baidu.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class LanguageMapPrivate_Baidu : public QSharedData
{
public:
    LanguageMapPrivate_Baidu()
    {

    }

    ~LanguageMapPrivate_Baidu()
    {

    }

    void init()
    {
        languageMap.insert(LanguageType_eAuto,QString("auto"));
        languageMap.insert(LanguageType_eZh_Simplified,QString("zh"));
        languageMap.insert(LanguageType_eZh_Traditional,QString("zh"));
        languageMap.insert(LanguageType_eEn,QString("en"));
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

NETWORKTRANSLATOR_NAMESPACE_END
