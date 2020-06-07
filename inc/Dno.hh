#ifndef DNO_HH
#define DNO_HH

#include "Powierzchnia.hh"
#include "Przeszkoda.hh"
#include <memory>

class Dno : public Powierzchnia, public Przeszkoda{
public:
    static std::shared_ptr<Dno> stworz(std::shared_ptr<drawNS::Draw3DAPI>& sc);
    Dno(std::shared_ptr<drawNS::Draw3DAPI>& sc);
    ~Dno() {}
    bool czyKolizja(std::shared_ptr<Interfejs>) const override;
};

#endif
