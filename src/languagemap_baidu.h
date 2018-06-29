#ifndef LANGUAGEMAP_BAIDU_H
#define LANGUAGEMAP_BAIDU_H

//QNetworkTranslator
#include "languagemap.h"

class LanguageMapPrivate_Baidu;
class LanguageMap_Baidu : public LanguageMap
{
    Q_DISABLE_COPY(LanguageMap_Baidu)
public:
    explicit LanguageMap_Baidu();
    virtual ~LanguageMap_Baidu();

    QString languageString(LanguageType) const override;
    LanguageType languageType(const QString &) const override;

private:
    QSharedDataPointer<LanguageMapPrivate_Baidu> d;
    friend class LanguageMapPrivate_Baidu;
};

#endif // LANGUAGEMAP_BAIDU_H
