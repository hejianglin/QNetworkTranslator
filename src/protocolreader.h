#ifndef PROTOCOLREADER_H
#define PROTOCOLREADER_H

//Qt
#include <QtCore/QStringList>

//QNetwrokTranslator
#include "languagemap.h"
#include "networktranslator_global.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class ProtocolReader
{
public:
    ProtocolReader();
    virtual ~ProtocolReader();

    virtual void setLanguageMap(LanguageMap *);
    virtual LanguageMap *languageMap() const;

    virtual void read(const QByteArray &);
    virtual void read(const QString &);
    virtual LanguageType sourceLanguage() const;
    virtual LanguageType targetLanguage() const;
    virtual QString source() const;
    virtual QString target() const;

    virtual int error() const;
    virtual QString errorString() const;
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif // PROTOCOLREADER_H
