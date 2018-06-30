#include <QCoreApplication>

#include "simpletranslaotr.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SimpleTranslaotr simpleTranslator;
    simpleTranslator.translatetest();

    return a.exec();
}
