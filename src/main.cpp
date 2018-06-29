#include <QCoreApplication>
#include <QJsonObject>
#include <QDebug>

#include "protocolgenertor_baidu.h"
#include "translator.h"
#include "translator_global.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Translator *client = new Translator;
    client->setTranslatorClient(TranslatorClient_eBaidu);
    client->setAppID("20180616000177249");
    client->setAppKey("kCRSPpGPuSQoPXwaT9hD");
    client->setDefaultSourceLanguage(LanguageType_eEn);
    client->setDefaultTargetLanguage(LanguageType_eZh);

    if(!client->translator("hello world!\n my name is hanmeimei,nice to see you!"))
    {
        qDebug()<<"error!";
    }
    return a.exec();
}
