#ifndef TAFLA_HH
#define TAFLA_HH

#include "Powierzchnia.hh"
#include "Przeszkoda.hh"
#include <memory>

class Tafla : public Powierzchnia, public Przeszkoda{
public:
    static std::shared_ptr<Tafla> stworz(std::shared_ptr<drawNS::Draw3DAPI>& sc);
    Tafla(std::shared_ptr<drawNS::Draw3DAPI>& sc);
    ~Tafla() {}
    bool czyKolizja(std::shared_ptr<Interfejs>) const override;
};

#endif
