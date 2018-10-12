//Qt
#include <QtCore/QTextCodec>
#include <QtNetwork/QNetworkReply>

#include <QDebug>

//QNetworkTranslator
#include "networktranslator.h"
#include "networktranslator_p.h"
#include "networkrequestfactory.h"
#include "languagemapfactory.h"
#include "protocolgenertorfactory.h"
#include "protocolreaderfactory.h"

NETWORKTRANSLATOR_NAMESPACE_BEGIN

NetworkTranslatorPrivate::NetworkTranslatorPrivate(NetworkTranslator *q)
    : m_eEngine(TranslationEngine_eNone)
    , m_eSourceLanguage_Default(LanguageType_eAuto)
    , m_eTargetLanguage_Default(LanguageType_eNone)
    , m_cLanguageMap(Q_NULLPTR)
    , m_cProtocolGenertor(Q_NULLPTR)
    , m_cProtocolRead(Q_NULLPTR)
    , q_ptr(q)
{

}

NetworkTranslatorPrivate::~NetworkTranslatorPrivate()
{
    if(m_cLanguageMap != Q_NULLPTR){
        delete m_cLanguageMap;
    }

    if(m_cProtocolGenertor != Q_NULLPTR){
        delete m_cProtocolGenertor;
    }

    if(m_cProtocolRead != Q_NULLPTR){
        delete m_cProtocolRead;
    }


}

void NetworkTranslatorPrivate::init()
{
    if(m_eEngine <= TranslationEngine_eNone){
        return ;
    }

    //languagemap
    LanguageMapFactory cLanguageMapFactory;
    if(m_cLanguageMap != Q_NULLPTR){
        delete m_cLanguageMap;
    }
    m_cLanguageMap = cLanguageMapFactory.create(m_eEngine);

    //request head
    NetworkRequestFactory cNetworkRequestFactory;
    m_cRequestHead = cNetworkRequestFactory.create(m_eEngine);

    //protocolgenertor
    ProtocolGenertorFactory cProtocolGenertorFactory;
    if(m_cProtocolGenertor != Q_NULLPTR){
        delete m_cProtocolGenertor;
    }
    m_cProtocolGenertor = cProtocolGenertorFactory.create(m_eEngine);
    m_cProtocolGenertor->setLanguageMap(m_cLanguageMap);

    //protocolreader
    ProtocolReaderFactory cProtocolReaderFactory;
    if(m_cProtocolRead != Q_NULLPTR){
        delete m_cProtocolRead;
    }
    m_cProtocolRead = cProtocolReaderFactory.create(m_eEngine);
    m_cProtocolRead->setLanguageMap(m_cLanguageMap);
}

bool NetworkTranslatorPrivate::isValid()
{
    if(m_eEngine <= TranslationEngine_eNone){
        m_sErrorString = QObject::tr("unset translator engine");
        return false;
    }

    if(m_sAppID.isEmpty() || m_sAppKey.isEmpty()){
        m_sErrorString = QObject::tr("appid or appkey unset");
        return false;
    }
    return true;
}

void NetworkTranslatorPrivate::_q_finished(QNetworkReply *reply)
{
    Q_Q(NetworkTranslator);



    if(reply == Q_NULLPTR){
        return ;
    }

    NetworkTranslatorReply TranslatorReply;
    if(reply->error() != QNetworkReply::NoError){
        TranslatorReply.setError(static_cast<NetworkTranslatorReply::TranslationError>(reply->error()));
        TranslatorReply.setErrorString(reply->errorString());
    } else {
        QTextCodec *pCodec = QTextCodec::codecForName("utf-8");
        QString data = pCodec->toUnicode(reply->readAll());
        m_cProtocolRead->read(data);
        if(m_cProtocolRead->error() != 0){
            
            TranslatorReply.setError(static_cast<NetworkTranslatorReply::TranslationError>(m_cProtocolRead->error()));
            TranslatorReply.setErrorString(m_cProtocolRead->errorString());
        } else {
            
            TranslatorReply.setSourceLanguage(m_cProtocolRead->sourceLanguage());
            TranslatorReply.setTargetLanguage(m_cProtocolRead->targetLanguage());
            TranslatorReply.setSource(m_cProtocolRead->source());
            TranslatorReply.setTarget(m_cProtocolRead->target());
        }
    }

    
    Q_EMIT q->finished(TranslatorReply);
    reply->deleteLater();
}

//////////////////////////////
/// \brief Translator::Translator
/// \param parent
///
NetworkTranslator::NetworkTranslator(QObject *parent)
    :QObject(parent)
    ,d_ptr(new NetworkTranslatorPrivate(this))
{
    Q_D(NetworkTranslator);
    connect(&(d->m_cNetworkAccessManager),SIGNAL(finished(QNetworkReply*)),this,SLOT( _q_finished(QNetworkReply *)));
}

NetworkTranslator::~NetworkTranslator()
{
    delete d_ptr;

}

void NetworkTranslator::setTranslatorEngine(TranslationEngine engine)
{
    Q_D(NetworkTranslator);
    d->m_eEngine = engine;
    d->init();
}

TranslationEngine NetworkTranslator::translatorEngine() const
{
    Q_D(const NetworkTranslator);
    return d->m_eEngine;
}

void NetworkTranslator::setTranslatorEngineUrl(const QString &url)
{
    Q_D(NetworkTranslator);
    d->m_sEngineUrl = url;
}

QString NetworkTranslator::translatorEngineUrl() const
{
    Q_D(const NetworkTranslator);
    return d->m_sEngineUrl;
}

void NetworkTranslator::setAppID(const QString &appID)
{
    Q_D(NetworkTranslator);
    d->m_sAppID = appID;
}

QString NetworkTranslator::appID() const
{
    Q_D(const NetworkTranslator);
    return d->m_sAppID;
}

void NetworkTranslator::setAppKey(const QString &appKey)
{
    Q_D(NetworkTranslator);
    d->m_sAppKey = appKey;
}

QString NetworkTranslator::appKey() const
{
    Q_D(const NetworkTranslator);
    return d->m_sAppKey;
}

void NetworkTranslator::setDefaultSourceLanguage(LanguageType type)
{
    Q_D(NetworkTranslator);
    d->m_eSourceLanguage_Default = type;
}

LanguageType NetworkTranslator::defaultSourceLanguage() const
{
    Q_D(const NetworkTranslator);
    return d->m_eSourceLanguage_Default;
}

void NetworkTranslator::setDefaultTargetLanguage(LanguageType type)
{
    Q_D(NetworkTranslator);
    d->m_eTargetLanguage_Default = type;
}

LanguageType NetworkTranslator::defaultTargetLanguage() const
{
    Q_D(const NetworkTranslator);
    return d->m_eTargetLanguage_Default;
}

bool NetworkTranslator::translator(const QString &source)
{
    Q_D(NetworkTranslator);
    NetworkTranslatorRequest request;
    request.setSource(source);
    request.setSourceLanguage(d->m_eSourceLanguage_Default);
    request.setTargetLanguage(d->m_eTargetLanguage_Default);
    return translator(request);
}

bool NetworkTranslator::translator(NetworkTranslatorRequest &request)
{
    Q_D(NetworkTranslator);

    NetworkTranslatorReply::TranslationError eTranslationError =
            NetworkTranslatorReply::TranslationError_eNone;
    do{
        if(!request.isValid()){
            eTranslationError = NetworkTranslatorReply::TranslationError_eRequestError;
            d->m_sErrorString = request.errorString();
            break;
        }

        if(!d->isValid()){
            eTranslationError = NetworkTranslatorReply::TranslationError_eConfigError;
            break;
        }

        d->m_cProtocolGenertor->setAppID(d->m_sAppID);
        d->m_cProtocolGenertor->setAppKey(d->m_sAppKey);
        d->m_cProtocolGenertor->setSource(request.source());
        d->m_cProtocolGenertor->setSourceLanguage(request.sourceLanguage());
        d->m_cProtocolGenertor->setTargetLanguage(request.targetLanguage());
        if(!d->m_cProtocolGenertor->isValid()){
            eTranslationError = NetworkTranslatorReply::TranslationError_eProtocolGenerteError;
            d->m_sErrorString = d->m_cProtocolGenertor->errorString();
            break;
        }
    }while(0);

    if(eTranslationError != NetworkTranslatorReply::TranslationError_eNone){
        NetworkTranslatorReply reply;
        reply.setError(eTranslationError);
        reply.setErrorString(d->m_sErrorString);
        reply.setSource(request.source());
        reply.setSourceLanguage(request.sourceLanguage());
        reply.setTargetLanguage(request.targetLanguage());
        return false;
    }

    if(!d->m_sEngineUrl.isEmpty()){
        d->m_cRequestHead.setUrl(QUrl(d->m_sEngineUrl));
    }

    d->m_cNetworkAccessManager.post(d->m_cRequestHead,d->m_cProtocolGenertor->generate());
    return true;
}

bool NetworkTranslator::isValid()
{
    Q_D(NetworkTranslator);
    return d->isValid();
}

QString NetworkTranslator::errorString() const
{
    Q_D(const NetworkTranslator);
    return d->m_sErrorString;
}

NETWORKTRANSLATOR_NAMESPACE_END

#include "moc_networktranslator.cpp"
