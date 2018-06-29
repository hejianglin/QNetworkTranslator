#ifndef PROTOCOLGENERTOR_BAIDU_H
#define PROTOCOLGENERTOR_BAIDU_H

//Qt
#include <QtCore/QSharedData>

//QNetworkTranslator
#include "languagemap.h"
#include "protocolgenertor.h"

class ProtocolGenertorPrivate_Baidu;
class ProtocolGenertor_Baidu : public ProtocolGenertor
{
    Q_DISABLE_COPY(ProtocolGenertor_Baidu)
public:
    ProtocolGenertor_Baidu(LanguageMap *map = Q_NULLPTR);
    virtual ~ProtocolGenertor_Baidu();

    void setAppID(const QString &) override;
    QString appID() const override;

    void setAppKey(const QString &) override;
    QString appKey() const override;

    void setSourceLanguage(LanguageType) override;
    LanguageType sourceLanguage() const override;

    void setTargetLanguage(LanguageType) override;
    LanguageType targetLanguage() const override;

    void setSource(const QString &) override;
    QString source() const override;

    QByteArray generate() override;

private:
    QSharedDataPointer<ProtocolGenertorPrivate_Baidu> d;
    friend class ProtocolGenertorPrivate_Baidu;
};
#endif// PROTOCOLGENERTOR_BAIDU_H
