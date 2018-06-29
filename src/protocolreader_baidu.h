#ifndef PROTOCOLREADER_BAIDU_H
#define PROTOCOLREADER_BAIDU_H

//Qt
#include <QtCore/QSharedData>

//QNetwrokTranstor
#include "languagemap.h"
#include "protocolreader.h"



class ProtocolReaderPrivate_Baidu;
class ProtocolReader_Baidu : public ProtocolReader
{
public:
    ProtocolReader_Baidu();
    virtual ~ProtocolReader_Baidu();

    void setLanguageMap(LanguageMap *) override;
    LanguageMap *languageMap() const override;

    void read(const QByteArray &) override;
    void read(const QString &) override;
    LanguageType sourceLanguage() const override;
    LanguageType targetLanguage() const override;
    QStringList source() const override;
    QStringList target() const override;

    int error() const override;
    QString errorString() const override;

private:
    QSharedDataPointer<ProtocolReaderPrivate_Baidu> d;
    friend class ProtocolReaderPrivate_Baidu;
};

#endif // PROTOCOLREADER_BAIDU_H
