#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Obiekt3D.hh"

class Prostopadloscian : public Obiekt3D{
    protected:
        Wektor3D wymiary;

    public:
        void rysuj() override;
        Prostopadloscian() : wymiary{1,1,1} {}
        ~Prostopadloscian(){}


};

#endif
