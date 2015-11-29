#include "chromosom.h"

chromosom::chromosom(): iloscGenow(6) {
    this->tablicaGenow = new int[this->iloscGenow];
}

chromosom::chromosom(int num)
{
    this->tablicaGenow = new int[num];
    this->iloscGenow = num;
}

int chromosom::getGen(int i) {
    if(this->iloscGenow>i) return this->tablicaGenow[i]; else return 0;
}

void chromosom::setGen(int i,int value) {
    if(this->iloscGenow>i) this->tablicaGenow[i] = value;
}

void chromosom::setWartoscFunkcjiCelu(long wartosc)
{
    this->wartoscFunkcjiCelu = wartosc;
}

long chromosom::getWartoscFunkcjiCelu()
{
    return this->wartoscFunkcjiCelu;
}
