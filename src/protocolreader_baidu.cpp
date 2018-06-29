#include "protocolreader_baidu.h"

#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>

class ProtocolReaderPrivate_Baidu : public QSharedData
{
public:
    ProtocolReaderPrivate_Baidu(LanguageMap *map = Q_NULLPTR)
        : m_eSourceLanguage(LanguageType_eNone)
        , m_eTargetLanguage(LanguageType_eNone)
        , m_cLanguageMap(map)

    {

    }

    ~ProtocolReaderPrivate_Baidu()
    {

    }

    void read(const QByteArray &data)
    {
        QJsonObject dataObj = QJsonDocument::fromJson(data).object();
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

    LanguageType m_eSourceLanguage;
    LanguageType m_eTargetLanguage;
    QStringList m_slSource;
    QStringList m_slTarget;
    LanguageMap *m_cLanguageMap;
};

ProtocolReader_Baidu::ProtocolReader_Baidu(LanguageMap *map)
    :d(new ProtocolReaderPrivate_Baidu(map))
{

}

virtual ProtocolReader_Baidu::~ProtocolReader_Baidu()
{
    d = 0;
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




