#include "Przeszkoda.hh"

static bool Przeszkoda::kolizjaDrona(Interfejs & D)
{
    for(int n : lista)
    {
        if( n->czyKoliizja(D) ) return true;
    }
    return false;
}
