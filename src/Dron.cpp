#include "Dron.hh"
#define _USE_MATH_DEFINES
#include <cmath>

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
        this->cel = this->pozycja + W*odl;


        this->rysuj();
        W = (W/20);

        double tmp = 20*odl;
        for(int i = 0; i < tmp; i++)
        {
            this->przesun(W);
            LewyWir.setObrot(LewyWir.getObrot()+7);
            PrawyWir.setObrot(PrawyWir.getObrot()-7);
            this->rysuj();
        }
        this->pozycja = this->cel;
        this->rysuj();
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
    Wektor3D W2 = {0,-1,0};
    W1 = orientacjaZ*W1;
    W2 = orientacjaZ*W2;
    LewyWir.setPozycja(this->pozycja + W2 - W1);
    PrawyWir.setPozycja(this->pozycja + W2 + W1);
    LewyWir.setOrientacjaZ(orientacjaZ.getKat() + LewyWir.getObrot());
    PrawyWir.setOrientacjaZ(orientacjaZ.getKat() + PrawyWir.getObrot());
    LewyWir.rysuj();
    PrawyWir.rysuj();
}
