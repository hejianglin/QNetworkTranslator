//Qt
#include <QtCore/QUrl>
#include <QtCore/QObject>
#include <QtCore/QStringList>
#include <QtCore/QCryptographicHash>

//QNetworkTranslator
#include "protocolgenertor_baidu.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class ProtocolGenertorPrivate_Baidu : public QSharedData
{
public:
    inline ProtocolGenertorPrivate_Baidu(LanguageMap *map = Q_NULLPTR)
        :m_cLanguageMap(map)
    {

    }

    ~ ProtocolGenertorPrivate_Baidu()
    {

    }

    bool isValid()
    {
        if(m_cLanguageMap == Q_NULLPTR){
            m_sErrorString = QObject::tr("language map set error");
            return false;
        }
        if(m_sAppID.isEmpty()){
            m_sErrorString = QObject::tr("appid unset");
            return false;
        }
        if(m_sAppKey.isEmpty()){
            m_sErrorString = QObject::tr("appkey unset");
            return false;
        }
        if(m_eSourceLanguage < LanguageType_eAuto){
            m_sErrorString = QObject::tr("source language type unset");
            return false;
        }
        if(m_eTargetLanguage <= LanguageType_eAuto){
            m_sErrorString = QObject::tr("target language type unset");
            return false;
        }
        if(m_sSource.isEmpty()){
            m_sErrorString = QObject::tr("source is empty");
            return false;
        }
        return true;
    }

    QString calculateSign()
    {
        QByteArray temp;
        temp.append(m_sAppID);
        temp.append(m_sSource);
        temp.append(QString::number(m_iRandomNumber));
        temp.append(m_sAppKey);
        return QString(QCryptographicHash::hash(temp,QCryptographicHash::Md5).toHex());
    }

    LanguageType m_eSourceLanguage;
    LanguageType m_eTargetLanguage;
    int m_iRandomNumber;
    QString m_sAppID;
    QString m_sAppKey;
    QString m_sSource;
    QString m_sErrorString;
    LanguageMap *m_cLanguageMap;
};

ProtocolGenertor_Baidu::ProtocolGenertor_Baidu()
    :ProtocolGenertor()
    ,d(new ProtocolGenertorPrivate_Baidu())
{
}

ProtocolGenertor_Baidu::~ProtocolGenertor_Baidu()
{
    d = 0;

}

void ProtocolGenertor_Baidu::setAppID(const QString &appid)
{
    d->m_sAppID = appid;
}

QString ProtocolGenertor_Baidu::appID() const
{
    return d->m_sAppID;
}

void ProtocolGenertor_Baidu::setAppKey(const QString &appkey)
{
    d->m_sAppKey = appkey;
}

QString ProtocolGenertor_Baidu::appKey() const
{
    return d->m_sAppKey;
}

void ProtocolGenertor_Baidu::setSourceLanguage(LanguageType type)
{
    d->m_eSourceLanguage = type;
}

LanguageType ProtocolGenertor_Baidu::sourceLanguage() const
{
    return d->m_eSourceLanguage;
}

void ProtocolGenertor_Baidu::setTargetLanguage(LanguageType type)
{
    d->m_eTargetLanguage = type;
}

LanguageType ProtocolGenertor_Baidu::targetLanguage() const
{
    return d->m_eTargetLanguage;
}

void ProtocolGenertor_Baidu::setSource(const QString &source)
{
    d->m_sSource = source;
}

QString ProtocolGenertor_Baidu::source() const
{
    return d->m_sSource;
}

void ProtocolGenertor_Baidu::setLanguageMap(LanguageMap *map)
{
    d->m_cLanguageMap = map;
}

LanguageMap* ProtocolGenertor_Baidu::languageMap() const
{
    return d->m_cLanguageMap;
}

bool ProtocolGenertor_Baidu::isValid()
{
    return d->isValid();
}

QString ProtocolGenertor_Baidu::errorString() const
{
    return d->m_sErrorString;
}

QByteArray ProtocolGenertor_Baidu::generate()
{
    if(!d->isValid()){
        return QByteArray();
    }

    QStringList slProtol;
    slProtol.append("q=" + QString(QUrl::toPercentEncoding(d->m_sSource)));
    slProtol.append("from=" + d->m_cLanguageMap->languageString(d->m_eSourceLanguage));
    slProtol.append("to=" + d->m_cLanguageMap->languageString(d->m_eTargetLanguage));
    slProtol.append("appid=" + d->m_sAppID);
    d->m_iRandomNumber = qrand();
    slProtol.append("salt=" + QString::number(d->m_iRandomNumber));
    slProtol.append("sign=" + d->calculateSign());
    QByteArray temp;
    return temp.append(slProtol.join("&"));
}

NETWORKTRANSLATOR_NAMESPACE_END
