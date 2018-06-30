#ifndef PROTOCOLGENERTOR_SOUGOU_H
#define PROTOCOLGENERTOR_SOUGOU_H

//Qt
#include <QtCore/QSharedData>

//QNetworkTranslator
#include "languagemap.h"
#include "protocolgenertor.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class ProtocolGenertorPrivate_Sougou;
class ProtocolGenertor_Sougou : public ProtocolGenertor
{
    Q_DISABLE_COPY(ProtocolGenertor_Sougou)
public:
    ProtocolGenertor_Sougou();
    virtual ~ProtocolGenertor_Sougou();

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

    void setLanguageMap(LanguageMap *) override;
    LanguageMap *languageMap() const override;

    bool isValid() override;
    QString errorString() const override;
    QByteArray generate() override;

private:
    QSharedDataPointer<ProtocolGenertorPrivate_Sougou> d;
    friend class ProtocolGenertorPrivate_Sougou;
};

NETWORKTRANSLATOR_NAMESPACE_END

#endif // PROTOCOLGENERTOR_SOUGOU_H
