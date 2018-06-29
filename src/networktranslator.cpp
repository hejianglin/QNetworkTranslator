//Qt
#include <QtCore/QTextCodec>
#include <QtNetwork/QNetworkReply>

//QNetworkTranslator
#include "networktranslator.h"
#include "networktranslator_p.h"
#include "networkrequestfactory.h"
#include "languagemapfactory.h"
#include "protocolgenertorfactory.h"
#include "protocolreaderfactory.h"

QNetworkTranslatorPrivate::QNetworkTranslatorPrivate(QNetworkTranslator *q)
    : m_eClient(TranslatorClient_eNone)
    , m_eSourceLanguage_Default(LanguageType_eAuto)
    , m_eTargetLanguage_Default(LanguageType_eNone)
    , m_cLanguageMap(Q_NULLPTR)
    , m_cProtocolGenertor(Q_NULLPTR)
    , m_cProtocolRead(Q_NULLPTR)
    , q_ptr(q)
{

}

QNetworkTranslatorPrivate::~QNetworkTranslatorPrivate()
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

void QNetworkTranslatorPrivate::init()
{
    if(m_eClient <= TranslatorClient_eNone){
        return ;
    }

    //languagemap
    LanguageMapFactory cLanguageMapFactory;
    if(m_cLanguageMap != Q_NULLPTR){
        delete m_cLanguageMap;
    }
    m_cLanguageMap = cLanguageMapFactory.create(m_eClient);

    //request head
    NetworkRequestFactory cNetworkRequestFactory;
    m_cRequestHead = cNetworkRequestFactory.create(m_eClient);

    //protocolgenertor
    ProtocolGenertorFactory cProtocolGenertorFactory;
    if(m_cProtocolGenertor != Q_NULLPTR){
        delete m_cProtocolGenertor;
    }
    m_cProtocolGenertor = cProtocolGenertorFactory.create(m_eClient);
    m_cProtocolGenertor->setLanguageMap(m_cLanguageMap);

    //protocolreader
    ProtocolReaderFactory cProtocolReaderFactory;
    if(m_cProtocolRead != Q_NULLPTR){
        delete m_cProtocolRead;
    }
    m_cProtocolRead = cProtocolReaderFactory.create(m_eClient);
    m_cProtocolRead->setLanguageMap(m_cLanguageMap);
}

bool QNetworkTranslatorPrivate::isValid()
{
    if(m_eClient <= TranslatorClient_eNone){
        m_sErrorString = QObject::tr("unset translator client");
        return false;
    }

    if(m_sAppID.isEmpty() || m_sAppKey.isEmpty()){
        m_sErrorString = QObject::tr("appid or appkey unset");
        return false;
    }
    return true;
}

void QNetworkTranslatorPrivate::_q_finished(QNetworkReply *reply)
{
    Q_Q(QNetworkTranslator);

    if(reply == Q_NULLPTR){
        return ;
    }

    QNetworkTranslatorReply TranslatorReply;
    if(reply->error() != QNetworkReply::NoError){
        TranslatorReply.setError((QNetworkTranslatorReply::TranslatorError)reply->error());
        TranslatorReply.setErrorString(reply->errorString());
    } else {
        QTextCodec *pCodec = QTextCodec::codecForName("utf-8");
        QByteArray sData = reply->readAll();
        m_cProtocolRead->read(pCodec->toUnicode(sData));
        if(m_cProtocolRead->error() != 0){
           TranslatorReply.setError((QNetworkTranslatorReply::TranslatorError)m_cProtocolRead->error());
            TranslatorReply.setErrorString(m_cProtocolRead->errorString());
        } else {
            TranslatorReply.setSourceLanguage(m_cProtocolRead->sourceLanguage());
            TranslatorReply.setTargetLanguage(m_cProtocolRead->targetLanguage());
            TranslatorReply.setSource(m_cProtocolRead->source());
            TranslatorReply.setTarget(m_cProtocolRead->source());
        }
    }

    Q_EMIT q->finished(TranslatorReply);
    reply->deleteLater();
}

//////////////////////////////
/// \brief Translator::Translator
/// \param parent
///
QNetworkTranslator::QNetworkTranslator(QObject *parent)
    :QObject(parent)
    ,d_ptr(new QNetworkTranslatorPrivate(this))
{
    Q_D(QNetworkTranslator);
    connect(&(d->m_cNetworkAccessManager),SIGNAL(finished(QNetworkReply*)),this,SLOT( _q_finished(QNetworkReply *)));
}

QNetworkTranslator::~QNetworkTranslator()
{
    delete d_ptr;
}

void QNetworkTranslator::setTranslatorClient(TranslatorClient client)
{
    Q_D(QNetworkTranslator);
    d->m_eClient = client;
    d->init();
}

TranslatorClient QNetworkTranslator::translatorClient() const
{
    Q_D(const QNetworkTranslator);
    return d->m_eClient;
}

void QNetworkTranslator::setTranslatorClientUrl(const QString &url)
{
    Q_D(QNetworkTranslator);
    d->m_sClientUrl = url;
}

QString QNetworkTranslator::translatorClientUrl() const
{
    Q_D(const QNetworkTranslator);
    return d->m_sClientUrl;
}

void QNetworkTranslator::setAppID(const QString &appID)
{
    Q_D(QNetworkTranslator);
    d->m_sAppID = appID;
}

QString QNetworkTranslator::appID() const
{
    Q_D(const QNetworkTranslator);
    return d->m_sAppID;
}

void QNetworkTranslator::setAppKey(const QString &appKey)
{
    Q_D(QNetworkTranslator);
    d->m_sAppKey = appKey;
}

QString QNetworkTranslator::appKey() const
{
    Q_D(const QNetworkTranslator);
    return d->m_sAppKey;
}

void QNetworkTranslator::setDefaultSourceLanguage(LanguageType type)
{
    Q_D(QNetworkTranslator);
    d->m_eSourceLanguage_Default = type;
}

LanguageType QNetworkTranslator::defaultSourceLanguage() const
{
    Q_D(const QNetworkTranslator);
    return d->m_eSourceLanguage_Default;
}

void QNetworkTranslator::setDefaultTargetLanguage(LanguageType type)
{
    Q_D(QNetworkTranslator);
    d->m_eTargetLanguage_Default = type;
}

LanguageType QNetworkTranslator::defaultTargetLanguage() const
{
    Q_D(const QNetworkTranslator);
    return d->m_eTargetLanguage_Default;
}

bool QNetworkTranslator::translator(const QString &source)
{
    return translator(QStringList()<<source);
}

bool QNetworkTranslator::translator(const QStringList &source)
{
    Q_D(QNetworkTranslator);
    QNetworkTranslatorRequest request;
    request.setSource(source);
    request.setSourceLanguage(d->m_eSourceLanguage_Default);
    request.setTargetLanguage(d->m_eTargetLanguage_Default);
    return translator(request);
}

bool QNetworkTranslator::translator(QNetworkTranslatorRequest &request)
{
    Q_D(QNetworkTranslator);

    //check
    if(!request.isValid() || !d->isValid()){
        return false;
    }

    //request
    d->m_cProtocolGenertor->setAppID(d->m_sAppID);
    d->m_cProtocolGenertor->setAppKey(d->m_sAppKey);
    d->m_cProtocolGenertor->setSource(request.source());
    d->m_cProtocolGenertor->setSourceLanguage(request.sourceLanguage());
    d->m_cProtocolGenertor->setTargetLanguage(request.targetLanguage());
    if(!d->m_cProtocolGenertor->isValid()){
        d->m_sErrorString = d->m_cProtocolGenertor->errorString();
        return false;
    }

    if(!d->m_sClientUrl.isEmpty()){
        d->m_cRequestHead.setUrl(QUrl(d->m_sClientUrl));
    }

    d->m_cNetworkAccessManager.post(d->m_cRequestHead,d->m_cProtocolGenertor->generate());
    return true;
}

QString QNetworkTranslator::errorString() const
{
    Q_D(const QNetworkTranslator);
    return d->m_sErrorString;
}
#include "moc_networktranslator.cpp"
