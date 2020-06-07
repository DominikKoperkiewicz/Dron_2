#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Wirnik.hh"
#include "Interfejs.hh"
#include "Przeszkoda.hh"

class Dron : public Prostopadloscian, public Interfejs, public Przeszkoda {
private:
    Wirnik LewyWir;
    Wirnik PrawyWir;

public:
    Dron(std::shared_ptr<drawNS::Draw3DAPI>& sc, Wektor3D poz, double rozm, string kol);
    ~Dron() {}
    static std::shared_ptr<Dron> stworz(std::shared_ptr<drawNS::Draw3DAPI>& sc, Wektor3D poz, double rozm, string kol);
    void przesun(Wektor3D W) override;
    void obrocZ(double st) override;
    void plyn(double odl, double k) override; //odleglosc, kat
    void rotacjaZ(double k) override; //kat
    void rysuj() override;
    Wektor3D getPozycja() const override { return pozycja; }
    Wektor3D getWymiary() const override { return wymiary; }
    bool czyKolizja(std::shared_ptr<Interfejs> D) const;
};

#endif
