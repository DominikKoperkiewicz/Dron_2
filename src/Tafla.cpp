#include "Tafla.hh"

std::shared_ptr<Tafla> Tafla::stworz(std::shared_ptr<drawNS::Draw3DAPI>& sc)
{
    std::shared_ptr<Tafla> Wsk = std::make_shared<Tafla>(sc);
    Przeszkoda::lista.push_back( Wsk );

    return Wsk;
}

Tafla::Tafla(std::shared_ptr<drawNS::Draw3DAPI>& sc)
{
    this->scena = sc;
    this->kolor = "blue";
    this->pozycja = {0,0,2};
    this->rysuj();
}

bool Tafla::czyKolizja(std::shared_ptr<Interfejs> D) const
{
    if( (D->getPozycja())[2] >= this->pozycja[2] ) { return true; }
    return false;
}
