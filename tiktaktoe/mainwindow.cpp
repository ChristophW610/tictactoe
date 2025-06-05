#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

bool spielBeendet = false;
QString schwierigkeitsgrad;
Spielfeld spielfeld;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    spielBeendet = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::versucheZug(QString symbol){
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
        QPushButton* b1 = findChild<QPushButton*>(kombis[i][0]);
        QPushButton* b2 = findChild<QPushButton*>(kombis[i][1]);
        QPushButton* b3 = findChild<QPushButton*>(kombis[i][2]);

        int count = 0;
        QPushButton* leer = nullptr;

        if (b1->text() == symbol) count++; else if (b1->text() == "") leer = b1;
        if (b2->text() == symbol) count++; else if (b2->text() == "") leer = b2;
        if (b3->text() == symbol) count++; else if (b3->text() == "") leer = b3;

        if (count == 2 && leer != nullptr) {
            leer->setText("o");

            QChar zeichen = leer->objectName().at(0).toUpper();
            int zeile = zeichen.unicode() - 'A';
            int spalte = leer->objectName().at(1).digitValue() - 1;
            spielfeld.setFeld(zeile, spalte, "o");
            if (spielfeld.prüfeGewinner()) {
                ui->label->setText("Du hast verloren!");
                spielBeendet = true;
            }
            return true;
        }
    }
    return false;
}

void MainWindow::bestenZugMachen(){
    std::pair<int, int> zug = computer.findeBestenZug(spielfeld.board);
    int i = zug.first;
    int j = zug.second;
    if (i != -1 && j != -1) {
        spielfeld.board[i][j] = "o";
        QString feldName = QString("%1%2").arg(QChar('A' + i)).arg(j + 1);
        QPushButton* feld = findChild<QPushButton*>(feldName);
        if (feld){
            feld->setText("o");
        }else{
            cout << feldName.toStdString() << endl;
        }

        if (spielfeld.prüfeGewinner()) {
            ui->label->setText("Du hast verloren!");
            spielBeendet = true;
        }
    }
    boardAktualisieren();
}

void MainWindow::computerZug(){

    if(spielBeendet || spielfeld.spielfeldVoll()) return;

    if(schwierigkeitsgrad == "unmöglich"){
        bestenZugMachen();
        return;
    }

    if(schwierigkeitsgrad == "schwer"){
        //wenn gewinnen kann, dann gewinnen
        if(versucheZug("o")) return;

        //wenn blocken kann, dann blocken
        if(versucheZug("x")) return;
    }

    computer.randomZug(spielfeld);
    if (spielfeld.prüfeGewinner()) {
        ui->label->setText("Du hast verloren!");
        spielBeendet = true;
    }
    boardAktualisieren();
}

void MainWindow::buttonClicked(std::pair<int, int> zug){

    if(spielBeendet || spielfeld.board[zug.first][zug.second] != "") return;
    spielfeld.setFeld(zug.first, zug.second, "x");
    boardAktualisieren();
    if(spielfeld.spielfeldVoll()){
        spielBeendet = true;
        ui->label->setText("Unentschieden!");
    }
    if(spielfeld.prüfeGewinner()){
        ui->label->setText("Du hast gewonnen!");
        spielBeendet = true;
    }
    computerZug();
}

void MainWindow::on_A1_clicked()
{
    std::pair<int, int> feld = {0, 0};
    buttonClicked(feld);
}

void MainWindow::on_A2_clicked()
{
    std::pair<int, int> feld = {0, 1};
    buttonClicked(feld);
}

void MainWindow::on_A3_clicked()
{
    std::pair<int, int> feld = {0, 2};
    buttonClicked(feld);
}

void MainWindow::on_B1_clicked()
{
    std::pair<int, int> feld = {1, 0};
    buttonClicked(feld);
}

void MainWindow::on_B2_clicked()
{
    std::pair<int, int> feld = {1, 1};
    buttonClicked(feld);
}

void MainWindow::on_B3_clicked()
{
    std::pair<int, int> feld = {1, 2};
    buttonClicked(feld);
}

void MainWindow::on_C1_clicked()
{
    std::pair<int, int> feld = {2, 0};
    buttonClicked(feld);
}

void MainWindow::on_C2_clicked()
{
    std::pair<int, int> feld = {2, 1};
    buttonClicked(feld);
}

void MainWindow::on_C3_clicked()
{
    std::pair<int, int> feld = {2, 2};
    buttonClicked(feld);
}

void MainWindow::on_resetButton_clicked()
{
    ui->label->setText("");
    spielBeendet = false;
    spielfeld.clear();
    boardAktualisieren();
}

void MainWindow::on_comboBox_activated(int index)
{
    if(index == 0){
        schwierigkeitsgrad = "einfach";
    }else if(index == 1){
        schwierigkeitsgrad = "schwer";
    }else if (index == 2){
        schwierigkeitsgrad = "unmöglich";
    }
}

void MainWindow::boardAktualisieren(){
    QString reihen[] = {"A", "B", "C"};

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            QString feldName = reihen[i] + QString::number(j + 1);
            QPushButton* feld = findChild<QPushButton*>(feldName);
            if (feld) {
                feld->setText(spielfeld.board[i][j]);
            }
        }
    }
}
