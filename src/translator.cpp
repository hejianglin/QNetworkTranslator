//Qt
#include <QtCore/QTextCodec>
#include <QDebug>

//QNetworkTranslator
#include "translator.h"
#include "translator_p.h"
#include "protocolgenertor_baidu.h"
#include "networkrequestfactory.h"

TranslatorPrivate::TranslatorPrivate(Translator *q)
    : m_eClient(TranslatorClient_eNone)
    , m_eSourceLanguage_Default(LanguageType_eAuto)
    , m_eTargetLanguage_Default(LanguageType_eNone)
    , q_ptr(q)
{

}

TranslatorPrivate::~TranslatorPrivate()
{

}

bool TranslatorPrivate::isValid() const
{
    if(m_eClient <= TranslatorClient_eNone){
        return false;
    }

    if(m_sAppID.isEmpty() || m_sAppKey.isEmpty()){
        return false;
    }
    return true;
}

void TranslatorPrivate::_q_finished(QNetworkReply *reply)
{
    //http 收到返回结果
    if(reply)
    {
        if(reply->error() != QNetworkReply::NoError)
        {
            qDebug()<<"error:"<<reply->errorString();
        }
        else
        {
            qDebug()<<"rec:"<<reply->readAll();
        }

        reply->deleteLater();
    }
}

//////////////////////////////
/// \brief Translator::Translator
/// \param parent
///
Translator::Translator(QObject *parent)
    :QObject(parent)
    ,d_ptr(new TranslatorPrivate(this))
{
    Q_D(Translator);
    connect(&(d->networkAccessManager),SIGNAL(finished(QNetworkReply*)),this,SLOT( _q_finished(QNetworkReply *)));
}

Translator::~Translator()
{
    delete d_ptr;
}

void Translator::setTranslatorClient(TranslatorClient client)
{
    Q_D(Translator);
    d->m_eClient = client;
}

TranslatorClient Translator::translatorClient() const
{
    Q_D(const Translator);
    return d->m_eClient;
}

void Translator::setTranslatorClientUrl(const QString &url)
{
    Q_D(Translator);
    d->m_sClientUrl = url;
}

QString Translator::translatorClientUrl() const
{
    Q_D(const Translator);
    return d->m_sClientUrl;
}

void Translator::setAppID(const QString &appID)
{
    Q_D(Translator);
    d->m_sAppID = appID;
}

QString Translator::appID() const
{
    Q_D(const Translator);
    return d->m_sAppID;
}

void Translator::setAppKey(const QString &appKey)
{
    Q_D(Translator);
    d->m_sAppKey = appKey;
}

QString Translator::appKey() const
{
    Q_D(const Translator);
    return d->m_sAppKey;
}

void Translator::setDefaultSourceLanguage(LanguageType type)
{
    Q_D(Translator);
    d->m_eSourceLanguage_Default = type;
}

LanguageType Translator::defaultSourceLanguage() const
{
    Q_D(const Translator);
    return d->m_eSourceLanguage_Default;
}

void Translator::setDefaultTargetLanguage(LanguageType type)
{
    Q_D(Translator);
    d->m_eTargetLanguage_Default = type;
}

LanguageType Translator::defaultTargetLanguage() const
{
    Q_D(const Translator);
    return d->m_eTargetLanguage_Default;
}

bool Translator::translator(const QString &source)
{
    Q_D(Translator);
    TranslatorRequest request;
    request.setSource(source);
    request.setSourceLanguage(d->m_eSourceLanguage_Default);
    request.setTargetLanguage(d->m_eTargetLanguage_Default);
    return translator(request);
}

bool Translator::translator(const TranslatorRequest &request)
{
    Q_D(Translator);

    //check
    if(!request.isValid()){
        qDebug()<<Q_FUNC_INFO<<__LINE__;
        return false;
    }

    if(!d->isValid()){
        qDebug()<<Q_FUNC_INFO<<__LINE__;
        return false;
    }

    LanguageMap * languageMap = new LanguageMap_Baidu;
    ProtocolGenertor * protocoGenertor = new ProtocolGenertor_Baidu(languageMap);
    protocoGenertor->setAppID(d->m_sAppID);
    protocoGenertor->setAppKey(d->m_sAppKey);
    protocoGenertor->setSourceLanguage(request.sourceLanguage());
    protocoGenertor->setTargetLanguage(request.targetLanguage());
    protocoGenertor->setSource(request.source());
    qDebug()<<protocoGenertor->generate();

    NetworkRequestFactory networkfactory;

    d->networkAccessManager.post(networkfactory.create(d->m_eClient),protocoGenertor->generate());
    delete protocoGenertor;
    delete languageMap;
    return true;
}

#include "moc_translator.cpp"
