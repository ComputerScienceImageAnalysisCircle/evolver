#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(unsigned int i=0; i < 100*80; i++) {
        this->matryca[i] = 0;
        this->abonenci[i] = 0;
    }

    this->iloscMiast=3;
    this->iloscAnten = 3;
    this->generowanieMiast();
    setWindowTitle(tr("Algorytm genetyczny ustawiajacy anteny"));

    QSize wsize = ui->graphicsView->size();
    this->maxIloscWokseliX = wsize.width()/4;
    this->maxIloscWokseliY = wsize.height()/4;

    this->timer = new QTimer(this);
    //    connect(timer, SIGNAL(timeout()), native, SLOT(animate()));

    QGraphicsScene *scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

    //inicjalizacja populacji
    this->pop = new populacja(100);
    pop->generowanieLosowejPopulacji();

    this->generowanieAnten();
    this->rysowanieGrafiki();

    this->suma =0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text()=="Start") {
        ui->pushButton->setText("Stop");
    } else {
        this->wsplKrzyzowki = this->ui->lineEdit_2->text().toFloat();
        this->wsplMutacji = this->ui->lineEdit->text().toFloat();
        ui->pushButton->setText("Start");
    }
    emit(start());
}

int MainWindow::aFunction() {
    int i =0;
    while(i < 1000) {
        ui->label_2->setText(QString::number(i));
        i++;
    }
    return 0;
}


void MainWindow::on_actionZamknij_triggered()
{
    this->close();
}



void MainWindow::rysowanieGrafiki() {

    ui->graphicsView->scene()->clear();

    //rysowanie miast
    foreach(miasto m, this->listaMiast) {

        for(int i=m.getPosY(); i < m.getPosY()+m.getHeight(); i++) {

            for(int j=m.getPosX(); j< m.getPosX()+m.getWidth(); j++) {

                this->matryca[100*i+j] = m.getWokselPointer(m.getWidth()*(i-m.getPosY())+(j-m.getPosX()));

                int cc = 255 - m.getWokselPointer(m.getWidth()*(i-m.getPosY())+(j-m.getPosX()));

                QColor color = QColor(cc,cc,cc);
                ui->graphicsView->scene()->addRect(j*6,i*6,4,4,QPen(color),QBrush(QColor(Qt::transparent)));

            }
        }
    }

    //rysowanie anten
    foreach(antena a, this->listaAnten) {
        ui->graphicsView->scene()->addRect(a.getPozycja().x*6,a.getPozycja().y*6,4,4,QPen(QColor(Qt::red)), QBrush(QColor(Qt::transparent)));
        ui->graphicsView->scene()->addEllipse(a.getPozycja().x*6-(a.getPromien()*6/2),a.getPozycja().y*6-(a.getPromien()*6/2),a.getPromien()*6,a.getPromien()*6,QPen(QColor(Qt::red)), QBrush(QColor(Qt::transparent)));
    }

}


void MainWindow::generowanieMiast() {

    for(int i=0; i<this->iloscMiast; i++) {

        int x = rand()%80;
        int y = rand()%40;
        int w = 25;
        int h = 25;

        miasto m = miasto(x,y,w,h);
        this->listaMiast.append(m);

    }

}

void MainWindow::generowanieAnten()
{

    this->listaAnten.clear();
    for(int i=0; i < this->iloscAnten*2; i=i+2) {
        antena a = antena();

        a.setPozycja(this->pop->getChromosom(0)->getGen(i),this->pop->getChromosom(0)->getGen(i+1));
        this->listaAnten.append(a);
    }
}

void MainWindow::on_actionO_Autorze_triggered()
{
    About *a = new About();
    a->show();
}

void MainWindow::update(int i)
{
    ui->label_2->setText(QString::number(i));

    populacja *tmp = new populacja(100);
    pop->funkcjaCelu(matryca,abonenci);
    pop->sortowanie();

    int max = pop->getChromosom(0)->getWartoscFunkcjiCelu();

    if(max > suma) {
        suma = max;
        this->generowanieAnten();
        this->rysowanieGrafiki();
        ui->label_4->setText(QString::number(suma) + " zl");
        ui->label_6->setText(QString::number(suma/69.99));

    }

    //wybor bazowy
    wskListChromo = pop->wyborBazowyNajlepszych();

    for(int z=0; z < wskListChromo->count(); z ++) {
        tmp->addChromosom(wskListChromo->at(z));
    }


    //wybor ruletka
    wskListChromo->clear();
    wskListChromo = pop->ruletka();
    for(int z=0; z < wskListChromo->count(); z ++) {
        tmp->addChromosom(wskListChromo->at(z));
    }


    //krzyzowki i mutacje
    tmp->krzyzowka(this->wsplKrzyzowki);
    tmp->mutacja(this->wsplMutacji);



    delete pop;
    pop = tmp;
    wskListChromo->clear();

}

void MainWindow::on_pushButton_2_clicked()
{

    this->listaMiast.clear();
    this->generowanieMiast();

    //inicjalizacja populacji
    this->pop = new populacja(100);
    pop->generowanieLosowejPopulacji();
    for(int i=0; i<100*80; i++) this->matryca[i] = 0;

    this->generowanieAnten();
    this->rysowanieGrafiki();

    this->suma=0;

    this->ui->label_4->setText("0 zl");
    this->ui->label_6->setText("0");
}

void MainWindow::on_actionOtw_rz_Obraz_triggered()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Otworz Plik"), "", "Wszystkie (*.*)");

    if (!fileName.isEmpty()) {

        //tutaj wczytywanie obrazu
        IplImage *img0 = 0;
        img0 = cvLoadImage(fileName.toLocal8Bit().data(), 0);

        this->listaMiast.clear();
        miasto m = miasto(0,0,img0->width,img0->height);
        m.clear();

        for(int i=0; i < img0->height; i++) {
            for(int j=0; j < img0->width; j++) {
                uchar piksel = CV_IMAGE_ELEM(img0, uchar, i, j);
                m.setWoksel(img0->width*i+j,piksel);
            }
        }

        this->listaMiast.append(m);
        //inicjalizacja populacji
        this->pop = new populacja(100);
        pop->generowanieLosowejPopulacji();
        for(int i=0; i<100*80; i++) this->matryca[i] = 0;

        this->generowanieAnten();
        this->rysowanieGrafiki();

        this->suma=0;

        this->ui->label_4->setText("0 zl");
        this->ui->label_6->setText("0");
    }
}
