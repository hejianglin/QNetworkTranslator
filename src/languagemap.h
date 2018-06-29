#ifndef LANGUAGEMAP_H
#define LANGUAGEMAP_H

//Qt
#include <QtCore/QSharedDataPointer>

//QNetworkTranslator
#include "networktranslator_global.h"

class LanguageMap
{
    Q_DISABLE_COPY(LanguageMap)
public:
    explicit LanguageMap();
    virtual ~LanguageMap();

    virtual QString languageString(LanguageType) const;
    virtual LanguageType languageType(const QString &) const;
};

#endif // LANGUAGEMAP_H
