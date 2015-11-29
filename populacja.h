#ifndef POPULACJA_H
#define POPULACJA_H

#include <chromosom.h>
#include <antena.h>
#include <QList>
#include <QDebug>

class populacja
{
    chromosom *tablicaOsobnikow;
    int iloscOsobnikow;
    int obecnyOsobnik;

public:
    populacja(int iloscOsobnikow);
    void funkcjaCelu(int *matryca,int *abonenci);
    int getIloscOsobnikow();
    void generowanieLosowejPopulacji();
    QList<chromosom> *ruletka();
    void sortowanie();
    QList<chromosom> *wyborBazowyNajlepszych();
    void krzyzowka(float wspl);
    void mutacja(float wspl);
    chromosom *getChromosom(int i);
    void addChromosom(chromosom ch);
};

#endif // POPULACJA_H
