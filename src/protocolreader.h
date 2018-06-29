#ifndef PROTOCOLREADER_H
#define PROTOCOLREADER_H

//Qt
#include <QtCore/QStringList>

//QNetwrokTranslator
#include "languagemap.h"
#include "networktranslator_global.h"

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
    virtual QStringList source() const;
    virtual QStringList target() const;

    virtual int error() const;
    virtual QString errorString() const;
};

#endif // PROTOCOLREADER_H
