#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Wirnik.hh"
#include "Interfejs.hh"

class Dron : public Prostopadloscian, public Interfejs {
private:
    Wektor3D cel;
    Wirnik LewyWir;
    Wirnik PrawyWir;

public:
    Dron(std::shared_ptr<drawNS::Draw3DAPI>& sc) { wymiary = {1.7,1.5,1}; this->scena = sc; LewyWir.setScena(sc); PrawyWir.setScena(sc); }
    ~Dron() {}

    void przesun(Wektor3D W);
    void obrocZ(double st);
    void plyn(double odl, double k); //odleglosc, kat
    void rotacjaZ(double k); //kat
    void rysuj() override;
};

#endif
