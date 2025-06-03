#ifndef COMPUTER_H
#define COMPUTER_H

#include "spielfeld.h"
#include <QMainWindow>

class Computer
{
public:
    Computer();
    void randomZug(Spielfeld& spielfeld);
    std::pair<int, int> findeBestenZug(QString b[3][3]);
    int minimax(QString b[3][3], int depth, bool isMax);
    int bewerten(QString b[3][3]);

private:
    //Spielfeld spielfeld;
    //MainWindow mw;
};

#endif // COMPUTER_H
