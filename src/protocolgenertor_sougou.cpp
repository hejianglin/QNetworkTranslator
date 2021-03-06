//Qt
#include <QtCore/QUrl>
#include <QtCore/QObject>
#include <QtCore/QStringList>
#include <QtCore/QCryptographicHash>

//QNetworkTranslator
#include "protocolgenertor_sougou.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

class ProtocolGenertorPrivate_Sougou : public QSharedData
{
public:
    inline ProtocolGenertorPrivate_Sougou(LanguageMap *map = Q_NULLPTR)
        :m_cLanguageMap(map)
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

ProtocolGenertor_Sougou::ProtocolGenertor_Sougou()
    :ProtocolGenertor()
    ,d(new ProtocolGenertorPrivate_Sougou())
{

}

ProtocolGenertor_Sougou::~ProtocolGenertor_Sougou()
{
    d = 0;
}

void ProtocolGenertor_Sougou::setAppID(const QString &appid)
{
    d->m_sAppID = appid;
}

QString ProtocolGenertor_Sougou::appID() const
{
    return d->m_sAppID;
}

void ProtocolGenertor_Sougou::setAppKey(const QString &appkey)
{
    d->m_sAppKey = appkey;
}

QString ProtocolGenertor_Sougou::appKey() const
{
    return d->m_sAppKey;
}

void ProtocolGenertor_Sougou::setSourceLanguage(LanguageType type)
{
    d->m_eSourceLanguage = type;
}

LanguageType ProtocolGenertor_Sougou::sourceLanguage() const
{
    return d->m_eSourceLanguage;
}

void ProtocolGenertor_Sougou::setTargetLanguage(LanguageType type)
{
    d->m_eTargetLanguage = type;
}

LanguageType ProtocolGenertor_Sougou::targetLanguage() const
{
    return d->m_eTargetLanguage;
}

void ProtocolGenertor_Sougou::setSource(const QString &source)
{
    d->m_sSource = source;
}

QString ProtocolGenertor_Sougou::source() const
{
    return d->m_sSource;
}

void ProtocolGenertor_Sougou::setLanguageMap(LanguageMap *map)
{
    d->m_cLanguageMap = map;
}

LanguageMap* ProtocolGenertor_Sougou::languageMap() const
{
    return d->m_cLanguageMap;
}

bool ProtocolGenertor_Sougou::isValid()
{
    return d->isValid();
}

QString ProtocolGenertor_Sougou::errorString() const
{
    return d->m_sErrorString;
}

QByteArray ProtocolGenertor_Sougou::generate()
{
    if(!d->isValid()){
        return QByteArray();
    }

    QStringList slProtol;
    slProtol.append("q=" + QString(QUrl::toPercentEncoding(d->m_sSource)));
    slProtol.append("from=" + d->m_cLanguageMap->languageString(d->m_eSourceLanguage));
    slProtol.append("to=" + d->m_cLanguageMap->languageString(d->m_eTargetLanguage));
    slProtol.append("pid=" + d->m_sAppID);
    d->m_iRandomNumber = qrand();
    slProtol.append("salt=" + QString::number(d->m_iRandomNumber));
    slProtol.append("sign=" + d->calculateSign());
    QByteArray temp;
    return temp.append(slProtol.join("&"));
}

NETWORKTRANSLATOR_NAMESPACE_END
