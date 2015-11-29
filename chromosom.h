#ifndef CHROMOSOM_H
#define CHROMOSOM_H

class chromosom
{
    int *tablicaGenow;
    int iloscGenow;
    long wartoscFunkcjiCelu;

public:
    void setGen(int i,int value);
    int getGen(int i);
    void setWartoscFunkcjiCelu(long wartosc);
    long getWartoscFunkcjiCelu();
    chromosom(int num);
    chromosom();
};

#endif // CHROMOSOM_H
