#ifndef PROTOCOLREADER_SOUGOU_H
#define PROTOCOLREADER_SOUGOU_H

//Qt
#include <QtCore/QSharedData>

//QNetwrokTranstor
#include "languagemap.h"
#include "protocolreader.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class ProtocolReaderPrivate_Sougou;
class ProtocolReader_Sougou : public ProtocolReader
{
public:
    ProtocolReader_Sougou();
    virtual ~ProtocolReader_Sougou();

    void setLanguageMap(LanguageMap *) override;
    LanguageMap *languageMap() const override;

    void read(const QByteArray &) override;
    void read(const QString &) override;
    LanguageType sourceLanguage() const override;
    LanguageType targetLanguage() const override;
    QString source() const override;
    QString target() const override;

    int error() const override;
    QString errorString() const override;

private:
    QSharedDataPointer<ProtocolReaderPrivate_Sougou> d;
    friend class ProtocolReaderPrivate_Sougou;
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif // PROTOCOLREADER_SOUGOU_H
