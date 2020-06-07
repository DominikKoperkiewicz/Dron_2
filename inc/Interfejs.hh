#ifndef INTERFEJS_HH
#define INTERFEJS_HH

#include "Wektor.hh"
#include "Przeszkoda.hh"
#include <memory>

class Przeszkoda;

class Interfejs{
protected:

public:
    Interfejs() {}
    ~Interfejs() {}
    virtual void przesun(Wektor3D W) = 0;
    virtual void obrocZ(double st) = 0;
    virtual void plyn(double odl, double k) = 0;
    virtual void rotacjaZ(double k) = 0;
    virtual Wektor3D getPozycja() const = 0;
    virtual Wektor3D getWymiary() const = 0;
    virtual void rysuj() = 0;
};

#endif
