#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>
#include <memory>
#include <vector>
#include "Interfejs.hh"

class Interfejs;

class Przeszkoda{
protected:
    static std::vector<std::shared_ptr<Przeszkoda> > lista;
    static std::vector<std::shared_ptr<Interfejs> > lista_dronow;
    static int stworzone;
    static int zniszczone;
public:
    static bool kolizjaDrona(std::shared_ptr<Interfejs> D);
    static void statystyka();
    static std::shared_ptr<Interfejs> getDron(int num) { return lista_dronow[num]; }
    virtual bool czyKolizja(std::shared_ptr<Interfejs> D) const = 0;
    Przeszkoda() { stworzone++; }
    Przeszkoda(const Przeszkoda & P) { stworzone++; };
    ~Przeszkoda() { zniszczone++; }
};

#endif
