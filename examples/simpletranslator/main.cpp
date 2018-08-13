#include <QCoreApplication>

#include "simpletranslator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SimpleTranslator simpleTranslator;
    simpleTranslator.translatetest();

    return a.exec();
}
