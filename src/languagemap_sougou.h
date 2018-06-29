#ifndef LANGUAGEMAP_SOUGOU_H
#define LANGUAGEMAP_SOUGOU_H


//QNetworkTranslator
#include "languagemap.h"

class LanguageMapPrivate_Sougou;
class LanguageMap_Sougou : public LanguageMap
{
    Q_DISABLE_COPY(LanguageMap_Sougou)
public:
    explicit LanguageMap_Sougou();
    virtual ~LanguageMap_Sougou();

    QString languageString(LanguageType) const override;
    LanguageType languageType(const QString &) const override;

private:
    QSharedDataPointer<LanguageMapPrivate_Sougou> d;
    friend class LanguageMapPrivate_Sougou;
};

#endif // LANGUAGEMAP_SOUGOU_H
