#include "computer.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

Computer::Computer() {}

void Computer::randomZug(Spielfeld& spielfeld){
    QStringList felder = {
        "A1", "A2", "A3",
        "B1", "B2", "B3",
        "C1", "C2", "C3"
    };
    std::vector<QString> freie;
    for (const QString& name : felder) {
        QChar zeichen = name.at(0).toUpper();
        int zeile = zeichen.unicode() - 'A';
        int spalte = name.at(1).digitValue() - 1;
        QString symbol = spielfeld.board[zeile][spalte];
        if (symbol == "") {
            freie.push_back(name);
        }
    }

    if (!freie.empty()) {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(0, freie.size() - 1);
        QString zufallsFeld = freie[distr(eng)];
        //findChild<QPushButton*>(zufallsFeld)->setText("o");
        QChar zeichen = zufallsFeld.at(0).toUpper();
        int zeile = zeichen.unicode() - 'A';
        int spalte = zufallsFeld.at(1).digitValue() - 1;
        spielfeld.setFeld(zeile, spalte, "o");
    }
}

std::pair<int, int> Computer::findeBestenZug(QString b[3][3]){
    int bestVal = -1000;
    std::pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (b[i][j] == "") {
                b[i][j] = "o"; // Test-Zug
                int moveVal = minimax(b, 0, false);
                b[i][j] = "";
                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
    return bestMove;
}

int Computer::minimax(QString b[3][3], int depth, bool isMax){
    int score = bewerten(b);
    if (score == 10 || score == -10) return score;

    // Unentschieden?
    bool voll = true;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (b[i][j] == "") voll = false;
    if (voll) return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (b[i][j] == "") {
                    b[i][j] = "o"; // Computer
                    best = std::max(best, minimax(b, depth + 1, false));
                    b[i][j] = "";
                }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (b[i][j] == "") {
                    b[i][j] = "x"; // Mensch
                    best = std::min(best, minimax(b, depth + 1, true));
                    b[i][j] = "";
                }
        return best;
    }
}

int Computer::bewerten(QString b[3][3]){
    for (int i = 0; i < 3; ++i) {
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2]) {
            if (b[i][0] == "o") return +10;
            if (b[i][0] == "x") return -10;
        }
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i]) {
            if (b[0][i] == "o") return +10;
            if (b[0][i] == "x") return -10;
        }
    }

    // Diagonalen
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == "o") return +10;
        if (b[0][0] == "x") return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == "o") return +10;
        if (b[0][2] == "x") return -10;
    }

    return 0;
}

void Computer::bestenZugMachen(Spielfeld& spielfeld, QString b[3][3]){
    std::pair<int, int> zug = findeBestenZug(b);
    int i = zug.first;
    int j = zug.second;
    if (i != -1 && j != -1) {
        spielfeld.setFeld(i, j, "o");
    }
}

bool Computer::versucheZug(QString symbol, Spielfeld& spielfeld){
    QString kombis[8][3] = {
        {"A1", "A2", "A3"},
        {"B1", "B2", "B3"},
        {"C1", "C2", "C3"},
        {"A1", "B1", "C1"},
        {"A2", "B2", "C2"},
        {"A3", "B3", "C3"},
        {"A1", "B2", "C3"},
        {"A3", "B2", "C1"}
    };

    for (int i = 0; i < 8; ++i) {
        QString t1 = kombis[i][0];
        QString t2 = kombis[i][1];
        QString t3 = kombis[i][2];

        int count = 0;
        QString leer = "";
        if(spielfeld.getSymbol(t1) == symbol) count++; else if (spielfeld.getSymbol(t1) == "") leer = t1;
        if(spielfeld.getSymbol(t2) == symbol) count++; else if (spielfeld.getSymbol(t2) == "") leer = t2;
        if(spielfeld.getSymbol(t3) == symbol) count++; else if (spielfeld.getSymbol(t3) == "") leer = t3;

        if (count == 2 && leer != "") {
            QChar zeichen = leer.at(0).toUpper();
            int zeile = zeichen.unicode() - 'A';
            int spalte = leer.at(1).digitValue() - 1;
            spielfeld.setFeld(zeile, spalte, "o");
            return true;
        }
    }
    return false;
}

void Computer::zug(QString schwierigkeitsgrad, Spielfeld& spielfeld){
    if(schwierigkeitsgrad == "unmöglich"){
        bestenZugMachen(spielfeld, spielfeld.board);
        return;
    }else if(schwierigkeitsgrad == "schwer"){
        //wenn gewinnen kann, dann gewinnen
        if(versucheZug("o", spielfeld)) return;

        //wenn blocken kann, dann blocken
        if(versucheZug("x", spielfeld)) return;
    }
    randomZug(spielfeld);
}


