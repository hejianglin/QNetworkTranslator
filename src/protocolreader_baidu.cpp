//Qt
#include <QtCore/QObject>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>

//QNetworkTranslator
#include "protocolreader_baidu.h"

class ProtocolReaderPrivate_Baidu : public QSharedData
{
public:
    ProtocolReaderPrivate_Baidu()
        : m_iError(0)
        , m_eSourceLanguage(LanguageType_eNone)
        , m_eTargetLanguage(LanguageType_eNone)
    {

    }

    ~ProtocolReaderPrivate_Baidu()
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
        if(dataObj.contains("error_code")){//error
            m_iError =  dataObj["error_code"].toString().toInt(0,10);
            m_sErrorString = dataObj["error_msg"].toString();
            return ;
        }

        if(m_cLanguageMap)
        {
            m_eSourceLanguage = m_cLanguageMap->languageType(\
                        dataObj["from"].toString());
            m_eTargetLanguage = m_cLanguageMap->languageType(\
                        dataObj["to"].toString());
        }

        QJsonArray result = dataObj["trans_result"].toArray();
        for (int resultIndex = 0; resultIndex < result.size(); ++resultIndex) {
            QJsonObject resultObj = result[resultIndex].toObject();
            m_slSource.append(resultObj["src"].toString());
            m_slTarget.append(resultObj["dst"].toString());
        }
    }

    int m_iError;
    QString m_sErrorString;
    LanguageType m_eSourceLanguage;
    LanguageType m_eTargetLanguage;
    QStringList m_slSource;
    QStringList m_slTarget;
    LanguageMap *m_cLanguageMap;
};

ProtocolReader_Baidu::ProtocolReader_Baidu()
    :d(new ProtocolReaderPrivate_Baidu)
{

}

ProtocolReader_Baidu::~ProtocolReader_Baidu()
{
    d = 0;
}

void ProtocolReader_Baidu::setLanguageMap(LanguageMap *map)
{
    d->m_cLanguageMap = map;
}

LanguageMap *ProtocolReader_Baidu::languageMap() const
{
    return d->m_cLanguageMap;
}

void ProtocolReader_Baidu::read(const QByteArray &data)
{
    return d->read(data);
}

void ProtocolReader_Baidu::read(const QString &data)
{
    return read(data.toUtf8());
}

LanguageType ProtocolReader_Baidu::sourceLanguage() const
{
    return d->m_eSourceLanguage;
}

LanguageType ProtocolReader_Baidu::targetLanguage() const
{
    return d->m_eTargetLanguage;
}

QStringList ProtocolReader_Baidu::source() const
{
    return d->m_slSource;
}

QStringList ProtocolReader_Baidu::target() const
{
    return d->m_slTarget;
}

int ProtocolReader_Baidu::error() const
{
    return d->m_iError;
}

QString ProtocolReader_Baidu::errorString() const
{
    return d->m_sErrorString;
}



