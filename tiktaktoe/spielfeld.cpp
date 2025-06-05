#include "spielfeld.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;


Spielfeld::Spielfeld() {}

void Spielfeld::test(){
    cout << "Test" << endl;
}

QString board[3][3];

void Spielfeld::setFeld(int eins, int zwei, QString symbol){
    board[eins][zwei] = symbol;
}

void Spielfeld::clear(){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            board[i][j] = "";
        }
    }
}

bool Spielfeld::prüfeGewinner(){
    QString kombinationen[8][3] = {
        {"A1", "A2", "A3"},
        {"B1", "B2", "B3"},
        {"C1", "C2", "C3"},
        {"A1", "B1", "C1"},
        {"A2", "B2", "C2"},
        {"A3", "B3", "C3"},
        {"A1", "B2", "C3"},
        {"A3", "B2", "C1"}
    };

    for (const auto& kombi : kombinationen) {

        QChar zeichen = kombi[0].at(0).toUpper();
        int zeile = zeichen.unicode() - 'A';
        int spalte = kombi[0].at(1).digitValue() - 1;
        QString b1 = board[zeile][spalte];

        zeichen = kombi[1].at(0).toUpper();
        zeile = zeichen.unicode() - 'A';
        spalte = kombi[1].at(1).digitValue() - 1;
        QString b2 = board[zeile][spalte];

        zeichen = kombi[2].at(0).toUpper();
        zeile = zeichen.unicode() - 'A';
        spalte = kombi[2].at(1).digitValue() - 1;
        QString b3 = board[zeile][spalte];

        if (b1 == b2 && b2 == b3 && b1 != ""){
            return true;
        }
    }
    return false;
}

bool Spielfeld::spielfeldVoll(){
    QStringList felder = {
        "A1", "A2", "A3",
        "B1", "B2", "B3",
        "C1", "C2", "C3"
    };

    for (const QString& name : felder) {


        QChar zeichen = name.at(0).toUpper();
        int zeile = zeichen.unicode() - 'A';
        int spalte = name.at(1).digitValue() - 1;
        QString symbol = board[zeile][spalte];

        if (symbol == "") {
            return false;
        }
    }
    return true;
}

QString Spielfeld::getSymbol(QString name) {
    QChar zeichen = name.at(0).toUpper();
    int zeile = zeichen.unicode() - 'A';
    int spalte = name.at(1).digitValue() - 1;
    return board[zeile][spalte];
}
