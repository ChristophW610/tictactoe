#ifndef SPIELFELD_H
#define SPIELFELD_H

#include <QMainWindow>

class Spielfeld
{
public:
    Spielfeld();
    void test();
    void setFeld(int eins, int zwei, QString symbol);
    QString board[3][3];
    void clear();
    bool prüfeGewinner();
    bool spielfeldVoll();
    QString getSymbol(QString name);
};

#endif // SPIELFELD_H
