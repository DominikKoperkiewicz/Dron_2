#ifndef TAFLA_HH
#define TAFLA_HH

#include "Powierzchnia.hh"
#include "Przeszkoda.hh"
#include <list>
#include <memory>

class Tafla : public Powierzchnia, public Przeszkoda{
public:
    Tafla(std::shared_ptr<drawNS::Draw3DAPI>& sc) { this->scena = sc; this->kolor = "blue"; this->pozycja = {0,0,2}; lista.push_back(std::make_shared<Przeszkoda>()); }
    ~Tafla() {}
    bool czyKolizja(Interfejs & D) const override;
};

#endif
