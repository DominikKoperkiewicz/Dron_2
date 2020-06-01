#ifndef OBIEKT3D_HH
#define OBIEKT3D_HH

#include "Wektor.hh"
#include "MacierzOb.hh"

#include <iostream>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;


class Obiekt3D{
    protected:
        Wektor3D pozycja;
        MacierzOb orientacjaZ;
        int id = -1;
        std::shared_ptr<drawNS::Draw3DAPI> scena;

    public:
        Obiekt3D() {}
        ~Obiekt3D() {}
        virtual void rysuj() = 0;
        void setPozycja(Wektor3D W) { this->pozycja = W; }
        void setOrientacjaZ(double k) { this->orientacjaZ.setObrot(k,'z'); }
        void setScena(std::shared_ptr<drawNS::Draw3DAPI> sc) { this->scena = sc; }
};

#endif
