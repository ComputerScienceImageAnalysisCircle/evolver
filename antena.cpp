#include "antena.h"

antena::antena()
{
    this->pozycja.x = rand()%100;
    this->pozycja.y = rand()%80;
    this->r = 15;
    this->zysk=0;
    this->liczbaAbonentow=0;
}


antena::antena(cursor pozycja, int r) {

    this->pozycja.x = pozycja.x;
    this->pozycja.y = pozycja.y;

    this->r = r;

    this->zysk=0;
    this->liczbaAbonentow=0;
}

void antena::setPozycja(cursor pozycja) {
    this->pozycja = pozycja;
}

void antena::setPozycja(int x, int y) {
    this->pozycja.x = x;
    this->pozycja.y = y;
}

cursor antena::getPozycja() {
    return this->pozycja;
}

void antena::setPromien(int r)
{
    this->r = r;
}

int antena::getPromien()
{
    return this->r;
}

void antena::przeliczZysk(int *matryca, int *abonenci)
{
    cursor punkt = this->pozycja;
    cursor srodek = this->pozycja;

    for(int kat=0; kat < 360; kat++) {
        for(int promien=0; promien < this->r; promien++) {
            punkt.x = (int) (srodek.x + promien * cos(2 * PI * kat / 360));
            punkt.y = (int) (srodek.y + promien * sin(2 * PI * kat / 360));

            abonenci[100*punkt.y+punkt.x] = matryca[100*punkt.y+punkt.x];
        }
    }

}

int antena::getZysk()
{
    return this->zysk;
}

int antena::getLiczbaAbonentow()
{
    return this->liczbaAbonentow;
}
