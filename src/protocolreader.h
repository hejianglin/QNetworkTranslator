#ifndef PROTOCOLREADER_H
#define PROTOCOLREADER_H

//Qt
#include <QtCore/QStringList>

//QNetwrokTranslator
#include "languagemap.h"
#include "translator_global.h"

class ProtocolReader
{
public:
    ProtocolReader(LanguageMap *map = Q_NULLPTR);
    virtual ~ProtocolReader();
    virtual void read(const QByteArray &);
    virtual void read(const QString &);
    virtual LanguageType sourceLanguage() const;
    virtual LanguageType targetLanguage() const;
    virtual QStringList source() const;
    virtual QStringList target() const;
};

#endif // PROTOCOLREADER_H
