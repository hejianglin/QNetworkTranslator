#ifndef PROTOCOLGENERTOR_H
#define PROTOCOLGENERTOR_H

//Qt
#include <QtCore/QString>
#include <QtCore/QStringList>

//QNetworkTranslator
#include "languagemap.h"
#include "translator_global.h"

///////////////////////////////////////
/// \brief The ProtocolGenertor class
///
class ProtocolGenertor
{
    Q_DISABLE_COPY(ProtocolGenertor)
public:
    ProtocolGenertor(LanguageMap *languageMap = Q_NULLPTR);
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

//!  user extral
//    virtual void addParameter(const QString &,const QString &);
//    virtual void delParameter(const QString &);
//    virtual void delParameters(const QStringList &);
//    virtual QString parameter(const QString &) const;
//    virtual QStringList Parameters() const;

    virtual QByteArray generate();
};

#endif
