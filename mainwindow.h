#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chromosom.h>
#include <populacja.h>
#include <miasto.h>
#include <QTimer>
#include <QDebug>
#include <cursor.h>
#include <iostream>
#include <antena.h>
#include <about.h>
#include <QFileDialog>
#include <cv.h>
#include "highgui.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    miasto *tablicaMiast;
    int iloscMiast;
    int iloscAnten;
    QTimer *timer;
    int maxIloscWokseliX;
    int maxIloscWokseliY;
    QList<miasto> listaMiast;
    QList<antena> listaAnten;
    int matryca[100*80];
    int abonenci[100*80];
    int suma;
    float wsplKrzyzowki;
    float wsplMutacji;

    void rysowanieGrafiki();
    void generowanieMiast();
    void generowanieAnten();
    int aFunction();
    int wielka();
    QList<chromosom> *wskListChromo;
    populacja *pop;


signals:
    void start();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
        void update(int i);

private slots:
    void on_pushButton_clicked();
    void on_actionZamknij_triggered();
    void on_actionO_Autorze_triggered();


    void on_pushButton_2_clicked();

    void on_actionOtw_rz_Obraz_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
