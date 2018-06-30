#include <QDebug>
#include <QCoreApplication>

#include "simpletranslaotr.h"

USE_NETWORKTRANSLATOR_NAMESPACE

SimpleTranslaotr::SimpleTranslaotr(QObject *parent)
    : QObject(parent)
    , m_cNetworkTranslator(new NetworkTranslator(this))
{
    connect(m_cNetworkTranslator,SIGNAL(finished(NetworkTranslatorReply)),\
            this,SLOT(translatorFinished(NetworkTranslatorReply)));
}

void SimpleTranslaotr::translatetest()
{
    m_cNetworkTranslator->setTranslatorClient(TranslatorClient_eBaidu);
    m_cNetworkTranslator->setAppID("");//your appid
    m_cNetworkTranslator->setAppKey("");//your appkey
    m_cNetworkTranslator->setDefaultSourceLanguage(LanguageType_eEn);
    m_cNetworkTranslator->setDefaultTargetLanguage(LanguageType_eZh_Simplified);
    if(!m_cNetworkTranslator->translator("I have a dream!")){
        qDebug()<<Q_FUNC_INFO<<__LINE__<<"error:"<<m_cNetworkTranslator->errorString();
    }
}

void SimpleTranslaotr::translatorFinished(NetworkTranslatorReply reply)
{
    if(reply.error() != NetworkTranslatorReply::TranslatorError_eNone){
        qDebug()<<Q_FUNC_INFO<<__LINE__<<reply.error();
        qDebug()<<Q_FUNC_INFO<<__LINE__<<reply.errorString();
    }else{
        qDebug()<<Q_FUNC_INFO<<__LINE__<<"translate success!";
        qDebug()<<"source:"<<reply.source()<<"target:"<<reply.target();
    }
    qApp->quit();
}
