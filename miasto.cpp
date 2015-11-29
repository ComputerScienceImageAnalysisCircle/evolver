#include "miasto.h"

miasto::miasto(int pozX, int pozY, int width, int height)
{
    this->width=width;
    this->height=height;
    this->liczbaMieszkancow=0;
    this->wymiar = this->width*this->height;
    this->tabWoksel = new int[this->wymiar];
    this->pozycjaMapa = new cursor;
    this->pozycjaMapa->x = pozX;
    this->pozycjaMapa->y = pozY;

    for(int i=0; i<this->height; i++) {
        for(int j=0; j<this->width; j++) {
            this->tabWoksel[this->width*i+j] = rand()%(100)+25;
            this->liczbaMieszkancow += this->tabWoksel[i];
        }
    }

}



int miasto::getWidth()
{
    return this->width;
}

int miasto::getHeight()
{
    return this->height;
}

int miasto::getWokselPointer(int i)
{
    if(i < this->wymiar) return this->tabWoksel[i]; else return 0;
}

int miasto::getPosX()
{
    return this->pozycjaMapa->x;
}

int miasto::getPosY()
{
    return this->pozycjaMapa->y;
}

int miasto::getWymiar()
{
    return this->wymiar;
}

void miasto::setWoksel(int i, uchar p)
{
    this->tabWoksel[i] = (int)p;
}

void miasto::clear()
{
     this->liczbaMieszkancow =0;

    for(int i=0; i<this->height; i++) {
        for(int j=0; j<this->width; j++) {
            this->tabWoksel[this->width*i+j] = 0;
        }
    }
}
