#ifndef MIASTO_H
#define MIASTO_H

#include <stdlib.h>
#include <time.h>
#include <cursor.h>
#include <math.h>
#include <QDebug>

class miasto
{
    int width;
    int height;
    int liczbaMieszkancow;
    int *tabWoksel;
    int wymiar;
    cursor *pozycjaMapa;

public:
    miasto(int pozX, int pozY, int width, int height);
    int getWidth();
    int getHeight();
    int getPosX();
    int getPosY();
    int getWymiar();
    int getWokselPointer(int i);
    void setWoksel(int i,uchar p);
    void clear();

};

#endif // MIASTO_H
