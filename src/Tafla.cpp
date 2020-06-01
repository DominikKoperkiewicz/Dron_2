#include "Tafla.hh"

bool Tafla::czyKolizja(Interfejs & D) const override
{
    if( D.pozycja[2] >= this->pozycja[2] ) { return true; }
    return false;
}
