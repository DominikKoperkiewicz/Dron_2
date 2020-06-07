#include "dno.hh"

std::shared_ptr<Dno> Dno::stworz(std::shared_ptr<drawNS::Draw3DAPI>& sc)
{
    std::shared_ptr<Dno> Wsk = std::make_shared<Dno>(sc);
    Przeszkoda::lista.push_back( Wsk );

    return Wsk;
}

Dno::Dno(std::shared_ptr<drawNS::Draw3DAPI>& sc)
{
    this->scena = sc;
    this->kolor = "black";
    this->pozycja = {0,0,-5};
    this->rysuj();
}

bool Dno::czyKolizja(std::shared_ptr<Interfejs> D) const
{
    if( (D->getPozycja())[2] - D->getWymiary()[2] / 2  <= this->pozycja[2] ) { return true; }
    return false;
}
