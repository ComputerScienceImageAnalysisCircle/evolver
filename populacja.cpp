#include "populacja.h"

populacja::populacja(int iloscOsobnikow)
{
    this->iloscOsobnikow = iloscOsobnikow;
    this->tablicaOsobnikow = new chromosom[iloscOsobnikow];
    this->obecnyOsobnik=0;
}

void populacja::generowanieLosowejPopulacji() {

    for(int i=0; i<this->iloscOsobnikow; i++) {

        chromosom *x = new chromosom(6);
        for(int j=0; j<5; j=j+2) {
            x->setGen(j,rand()%70+15);
            x->setGen(j+1,rand()%50+15);
        }

        this->tablicaOsobnikow[i] = *x;
        delete x;
    }
}

void populacja::funkcjaCelu(int *matryca, int *abonenci) {

    long suma=0;
    float a=1.5;
    int b=1;

    for(int i=0; i < this->iloscOsobnikow; i++) {
        for(int a=0; a<100*80; a++) abonenci[a]=0;

        suma=0;
        for(int j=0; j<5; j=j+2) {
            cursor pozycja;
            pozycja.x = this->tablicaOsobnikow[i].getGen(j);
            pozycja.y = this->tablicaOsobnikow[i].getGen(j+1);

            antena *a = new antena(pozycja,15);

            a->przeliczZysk(matryca, abonenci);


            for(int a=0; a < 100*80; a++) {
                suma += abonenci[a];
            }
            for(int a=0; a<100*80; a++) abonenci[a]=0;
        }

//        for(int a=0; a < 100*80; a++) {
//            suma += abonenci[a];
//        }

        //skalowanie liniowe funkcji celu
        this->tablicaOsobnikow[i].setWartoscFunkcjiCelu(a*suma+b);
    }

}

void populacja::krzyzowka(float wspl) {

    int poz = 6*wspl;

    for(int i= ceil(iloscOsobnikow/10); i< iloscOsobnikow/2; i=i+2) {

        chromosom *tmp1 = &this->tablicaOsobnikow[i];
        chromosom *tmp2 = &this->tablicaOsobnikow[i+1];
        chromosom *tmp3 = new chromosom(6);
        chromosom *tmp4 = new chromosom(6);

        for(int j=0; j < poz;j++) {
            tmp3->setGen(j,tmp1->getGen(j));
        }

        for(int j=poz; j < 6;j++) {
            tmp3->setGen(j,tmp2->getGen(j));
        }

        for(int j=0; j < poz;j++) {
            tmp4->setGen(j,tmp2->getGen(j));
        }

        for(int j=poz; j < 6;j++) {
            tmp4->setGen(j,tmp1->getGen(j));
        }

        this->tablicaOsobnikow[i] = *tmp3;
        this->tablicaOsobnikow[i+1] = *tmp4;

    }
}

void populacja::mutacja(float wspl) {

    for(int i=10; i < this->iloscOsobnikow; i++) {
        for(int j=0; j<6; j++) {
            //srand(time(NULL)+i*j);

            float los = rand()%100;

            if(los <= wspl*100) {
                this->tablicaOsobnikow[i].setGen(j,rand()%50+15);
            }
        }
    }
}

QList<chromosom>* populacja::wyborBazowyNajlepszych() {

    this->sortowanie();

    QList<chromosom>* wskListChromo = new QList<chromosom>;

    for(int i=0; i<(this->iloscOsobnikow/10); i++) {
        wskListChromo->append(this->tablicaOsobnikow[i]);
    }

    return wskListChromo;
}

QList<chromosom>* populacja::ruletka() {

    QList<chromosom> *wskListChromo = new QList<chromosom>;

    while(wskListChromo->count() < this->iloscOsobnikow-ceil(this->iloscOsobnikow/10)) {

        int los = rand()%this->tablicaOsobnikow[10].getWartoscFunkcjiCelu() - 1 + this->tablicaOsobnikow[99].getWartoscFunkcjiCelu();

            for(int i=0; i < this->iloscOsobnikow-1; i++) {

            if(this->tablicaOsobnikow[i].getWartoscFunkcjiCelu() > los && this->tablicaOsobnikow[i+1].getWartoscFunkcjiCelu() < los) {
                wskListChromo->append(this->tablicaOsobnikow[i]);
            }
        }

    }

    return wskListChromo;
}

void populacja::sortowanie() {

    for(int i=0; i < this->iloscOsobnikow; i++) {
        for(int j=0; j < this->iloscOsobnikow; j++) {
            if(this->tablicaOsobnikow[i].getWartoscFunkcjiCelu() > this->tablicaOsobnikow[j].getWartoscFunkcjiCelu()) {
                chromosom ch = this->tablicaOsobnikow[i];
                this->tablicaOsobnikow[i] = this->tablicaOsobnikow[j];
                this->tablicaOsobnikow[j] = ch;
            }
        }
    }

}

chromosom *populacja::getChromosom(int i)  {
    return &this->tablicaOsobnikow[i];
}

int populacja::getIloscOsobnikow()
{
    return this->iloscOsobnikow;
}

void populacja::addChromosom(chromosom ch)
{
    this->tablicaOsobnikow[this->obecnyOsobnik] = ch;
    this->obecnyOsobnik++;
}
