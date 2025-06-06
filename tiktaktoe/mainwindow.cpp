#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

QString schwierigkeitsgrad;

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

void MainWindow::buttonClicked(std::pair<int, int> zug){
    if(spielBeendet || spielfeld.board[zug.first][zug.second] != "") return;
    spielfeld.setFeld(zug.first, zug.second, "x");
    boardAktualisieren();
    if(spielfeld.prüfeGewinner()){
        ui->label->setText("Du hast gewonnen!");
        spielBeendet = true;
        return;
    }else if(spielfeld.spielfeldVoll()){
        spielBeendet = true;
        ui->label->setText("Unentschieden!");
        return;
    }
    computer.zug(schwierigkeitsgrad, spielfeld);
    if (spielfeld.prüfeGewinner()) {
        ui->label->setText("Du hast verloren!");
        spielBeendet = true;
    }
    boardAktualisieren();
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
