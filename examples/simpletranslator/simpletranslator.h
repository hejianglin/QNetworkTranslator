#ifndef SIMPLETRANSLAOTR_H
#define SIMPLETRANSLAOTR_H

#include <QObject>

#include "networktranslator.h"

USE_NETWORKTRANSLATOR_NAMESPACE

class SimpleTranslator : public QObject
{
    Q_OBJECT
public:
    explicit SimpleTranslator(QObject *parent = 0);
    void translatetest();

private slots:
    void translatorFinished(NetworkTranslatorReply);

private:
    NetworkTranslator *m_cNetworkTranslator;
};

#endif // SIMPLETRANSLAOTR_H
