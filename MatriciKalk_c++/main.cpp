#include "grafica.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Grafica w;
    w.show();

    return a.exec();
}
