#include "mainwindow.h"
#include "particle.h"
#include <windows.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    Particle par;
    boundary b = {-10,-10,-10,10,10,10};
    while(true)
    {
        Particle::MakeRandomPositionParticle(b);
        Sleep(500);
    }


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
