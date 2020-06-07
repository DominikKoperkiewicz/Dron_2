#include "Dron.hh"
#define _USE_MATH_DEFINES
#include <cmath>

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI>& sc, Wektor3D poz, double rozm, string kol)
{
    wymiary = {1.7,1.5,1};
    wymiary = wymiary*rozm;
    this->pozycja = poz;
    LewyWir.setWymiary(LewyWir.getWymiary()*rozm);
    PrawyWir.setWymiary(PrawyWir.getWymiary()*rozm);
    LewyWir.setKolor(kol);
    PrawyWir.setKolor(kol);
    this->kolor = kol;
    this->scena = sc;
    LewyWir.setScena(sc);
    PrawyWir.setScena(sc);
    //Przeszkoda::lista.push_back(std::make_shared<Dron>(*this));
    //Przeszkoda::lista_dronow.push_back(std::make_shared<Dron>(reinterpret_cast<Interfejs*>(Przeszkoda::lista.back())));
    //Przeszkoda::lista_dronow.push_back(std::make_shared<Dron>(*this));
}

void Dron::przesun(Wektor3D W)
{
    this->pozycja = this->pozycja + W;
}


void Dron::obrocZ(double st)
{
    this->setOrientacjaZ(st + this->orientacjaZ.getKat());
}

void Dron::plyn(double odl, double k)
{
    if(k < 90 && k > -90 && odl > 0 && odl < 10)
    {
        Wektor3D W;
        k = k*(M_PI/180);
        double rad = orientacjaZ.getKat()*M_PI/180;
        W[0] = sin(rad)*cos(k);
        W[1] = cos(rad)*cos(k);
        W[2] = sin(k);
        //Wektor3D cel = this->pozycja + W*odl;


        this->rysuj();
        W = (W/20);

        double tmp = 20*odl;
        for(int i = 0; i < tmp; i++)
        {
            this->przesun(W);
            if( !Przeszkoda::kolizjaDrona( std::make_shared<Dron>(*this) ) )
            {
                LewyWir.setObrot(LewyWir.getObrot()+7);
                PrawyWir.setObrot(PrawyWir.getObrot()-7);
                this->rysuj();
            }
            else
            {
                this->przesun(W*(-1));
            }
        }
    }
}

void Dron::rotacjaZ(double k)
{
    double tmp = abs(k)/k;
    double wy = orientacjaZ.getKat() + k;

    this->rysuj();

    for(int i = 0; i < abs(k)/4 ; i++)
    {
        this->obrocZ(tmp*4);
        //LewyWir.setObrot(LewyWir.getObrot()+7);
        //PrawyWir.setObrot(PrawyWir.getObrot()-7);
        this->rysuj();
    }
    this->setOrientacjaZ(wy);
}

void Dron::rysuj()
{
    Prostopadloscian::rysuj();

    Wektor3D W1 = {this->wymiary[0]/3,0,0};
    Wektor3D W2 = {0,this->wymiary[1]/(-2) - LewyWir.getWymiary()[2]/2,0};
    W1 = orientacjaZ*W1;
    W2 = orientacjaZ*W2;
    LewyWir.setPozycja(this->pozycja + W2 - W1);
    PrawyWir.setPozycja(this->pozycja + W2 + W1);
    LewyWir.setOrientacjaZ(orientacjaZ.getKat() + LewyWir.getObrot());
    PrawyWir.setOrientacjaZ(orientacjaZ.getKat() + PrawyWir.getObrot());
    LewyWir.setOrientacjaY(-orientacjaZ.getKat());
    PrawyWir.setOrientacjaY(-orientacjaZ.getKat());
    LewyWir.rysuj();
    PrawyWir.rysuj();
}

bool Dron::czyKolizja(std::shared_ptr<Interfejs> D) const
{
/*
    if( D == reinterpret_cast<std::shared_ptr<Interfejs> >(this) ) { return false; }

    if( (this->pozycja - D->getPozycja()).dlugosc() < this->wymiary.dlugosc() + D->getWymiary().dlugosc() ) { return true; }
*/
    return false;
}

std::shared_ptr<Dron> Dron::stworz(std::shared_ptr<drawNS::Draw3DAPI>& sc, Wektor3D poz, double rozm, string kol)
{
    std::shared_ptr<Dron> D = std::make_shared<Dron>(sc, poz, rozm, kol);
    Przeszkoda::lista.push_back( D );
    Przeszkoda::lista_dronow.push_back( D );

    return D;
}
