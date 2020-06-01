#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <memory>
#include <list>

class Przeszkoda{
protected:
    static std::list<std::shared_ptr<Przeszkoda> > lista;
    static int stworzone;
    static int zniszczone;
public:
    static bool kolizjaDrona(Interfejs & D);
    virtual bool czyKolizja(Interfejs & D) const = 0;
    Przeszkoda() { stworzone++; }
    ~Przeszkoda() { zniszczone++; }
};

#endif
