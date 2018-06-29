#ifndef LANGUAGEMAP_H
#define LANGUAGEMAP_H

//Qt
#include <QtCore/QSharedDataPointer>

//QNetworkTranslator
#include "translator_global.h"

///////////////////////////////////////
/// \brief The LanguageMap class
/// base
class LanguageMap
{
    Q_DISABLE_COPY(LanguageMap)
public:
    explicit LanguageMap();
    virtual ~LanguageMap();

    virtual QString languageString(LanguageType) const;
    virtual LanguageType languageType(const QString &) const;
};


///////////////////////////////////////
/// \brief The LanguageMap_Baidu class
/// baidu client
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

///////////////////////////////////////
/// \brief The LanguageMapFactory class
/// simple factory
class LanguageMapFactory
{
public:
    explicit LanguageMapFactory()
    {

    }

    virtual ~LanguageMapFactory()
    {

    }

    LanguageMap *create(TranslatorClient client)
    {
        switch (client)
        {
        case TranslatorClient_eBaidu: return new LanguageMap_Baidu;
        default:   break;
        }
        return Q_NULLPTR;
    }
};

#endif // LANGUAGEMAP_H
