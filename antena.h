#ifndef ANTENA_H
#define ANTENA_H

#include <cursor.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <QDebug>

#define PI 3.141592

class antena
{
    cursor pozycja;
    int mocSygnalu;
    int r;
    int zanikanieSygnalu;
    int zysk;
    int liczbaAbonentow;

public:
    antena();
    antena(cursor pozycja, int r);
    void setPozycja(cursor pozycja);
    void setPozycja(int x, int y);
    cursor getPozycja();
    void setPromien(int r);
    int getPromien();
    int getZysk();
    void przeliczZysk(int *matryca, int *abonenci);
    int getLiczbaAbonentow();

};

#endif // ANTENA_H
