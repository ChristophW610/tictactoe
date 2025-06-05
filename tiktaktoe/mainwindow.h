#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "spielfeld.h"
#include "computer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString schwierigkeitsgrad = "einfach";
    void computerZug();
    bool prüfeGewinner();
    bool spielfeldVoll();
    bool versucheZug(QString symbol);
    void bestenZugMachen();
    std::pair<int, int> findeBestenZug(QString b[3][3]);
    int minimax(QString b[3][3], int depth, bool isMax);
    int bewerten(QString b[3][3]);
    void boardAktualisieren();
    bool spielBeendet;
    void buttonClicked(std::pair<int, int> zug);

private slots:
    void on_A1_clicked();

    void on_A2_clicked();

    void on_A3_clicked();

    void on_B1_clicked();

    void on_B2_clicked();

    void on_B3_clicked();

    void on_C1_clicked();

    void on_C2_clicked();

    void on_C3_clicked();

    void on_resetButton_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    Spielfeld spielfeld;

    Computer computer;
};
#endif // MAINWINDOW_H
