//Qt
#include <QtCore/QMap>
#include <QtCore/QObject>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>

//QNetworkTranslator
#include "protocolreader_sougou.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class ProtocolReaderPrivate_Sougou : public QSharedData
{
public:
    ProtocolReaderPrivate_Sougou()
        : m_iError(0)
        , m_eSourceLanguage(LanguageType_eNone)
        , m_eTargetLanguage(LanguageType_eNone)
    {
        //detail:http://deepi.sogou.com/docs/fanyiDoc
        m_mapError[1001] = QObject::tr("Unsupported language type");
        m_mapError[1002] = QObject::tr("Text too long");
        m_mapError[1003] = QObject::tr("Invalid PID");
        m_mapError[1004] = QObject::tr("Trial PID limit reached");
        m_mapError[1005] = QObject::tr("PID traffic too high");
        m_mapError[1006] = QObject::tr("Insufficient balance");
        m_mapError[1007] = QObject::tr("Random number does not exist");
        m_mapError[1008] = QObject::tr("Signature does not exist");
        m_mapError[1009] = QObject::tr("The signature is incorrect");
        m_mapError[10010] = QObject::tr("Text does not exist");
        m_mapError[1050] = QObject::tr("Internal server error");
    }

    ~ProtocolReaderPrivate_Sougou()
    {

    }

    void read(const QByteArray &data)
    {
        if(data.isEmpty()){
            m_iError = 999;
            m_sErrorString = QObject::tr("empty respone");
            return ;
        }



        QJsonObject dataObj = QJsonDocument::fromJson(data).object();
        if(dataObj["errorCode"].toString().toInt(0,10) != 0){
            m_iError =  dataObj["errorCode"].toString().toInt(0,10);
            m_sErrorString = m_mapError.value(m_iError);
            return ;
        }

        m_sSource.append(dataObj["query"].toString());
        m_sTarget.append(dataObj["translation"].toString());
    }

    int m_iError;
    QString m_sErrorString;
    LanguageType m_eSourceLanguage;
    LanguageType m_eTargetLanguage;
    QString m_sSource;
    QString m_sTarget;
    LanguageMap *m_cLanguageMap;
    QMap<int,QString> m_mapError;
};

ProtocolReader_Sougou::ProtocolReader_Sougou()
    :d(new ProtocolReaderPrivate_Sougou)
{

}

ProtocolReader_Sougou::~ProtocolReader_Sougou()
{
    d = 0;
}

void ProtocolReader_Sougou::setLanguageMap(LanguageMap *map)
{
    d->m_cLanguageMap = map;
}

LanguageMap *ProtocolReader_Sougou::languageMap() const
{
    return d->m_cLanguageMap;
}

void ProtocolReader_Sougou::read(const QByteArray &data)
{
    return d->read(data);
}

void ProtocolReader_Sougou::read(const QString &data)
{
    return read(data.toUtf8());
}

LanguageType ProtocolReader_Sougou::sourceLanguage() const
{
    return d->m_eSourceLanguage;
}

LanguageType ProtocolReader_Sougou::targetLanguage() const
{
    return d->m_eTargetLanguage;
}

QString ProtocolReader_Sougou::source() const
{
    return d->m_sSource;
}

QString ProtocolReader_Sougou::target() const
{
    return d->m_sTarget;
}

int ProtocolReader_Sougou::error() const
{
    return d->m_iError;
}

QString ProtocolReader_Sougou::errorString() const
{
    return d->m_sErrorString;
}

NETWORKTRANSLATOR_NAMESPACE_END
