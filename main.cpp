#include "promode.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProMode *w = w->GetInstance();
    w->show();
    return a.exec();
}
