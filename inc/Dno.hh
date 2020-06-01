#ifndef DNO_HH
#define DNO_HH

#include "Powierzchnia.hh"

class Dno : public Powierzchnia{
public:
    Dno(std::shared_ptr<drawNS::Draw3DAPI>& sc) { this->scena = sc; this->kolor = "black"; this->pozycja = {0,0,-5}; }
    ~Dno() {}
};

#endif
