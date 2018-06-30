#ifndef PROTOCOLGENERTOR_H
#define PROTOCOLGENERTOR_H

//Qt
#include <QtCore/QString>
#include <QtCore/QStringList>

//QNetworkTranslator
#include "languagemap.h"
#include "networktranslator_global.h"


NETWORKTRANSLATOR_NAMESPACE_BEGIN

class ProtocolGenertor
{
    Q_DISABLE_COPY(ProtocolGenertor)
public:
    ProtocolGenertor();
    virtual ~ProtocolGenertor();

    virtual void setAppID(const QString &);
    virtual QString appID() const;

    virtual void setAppKey(const QString &);
    virtual QString appKey() const;

    virtual void setSourceLanguage(LanguageType);
    virtual LanguageType sourceLanguage() const;

    virtual void setTargetLanguage(LanguageType);
    virtual LanguageType targetLanguage() const;

    virtual void setSource(const QString &);
    virtual QString source() const;

    virtual void setLanguageMap(LanguageMap *);
    virtual LanguageMap *languageMap() const;

    virtual bool isValid();
    virtual QString errorString() const;
    virtual QByteArray generate();
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif
