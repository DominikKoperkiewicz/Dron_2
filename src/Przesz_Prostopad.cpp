#include "Przesz_Prostopad.hh"

std::shared_ptr<Przesz_Prostopad> Przesz_Prostopad::stworz(std::shared_ptr<drawNS::Draw3DAPI>& sc, Wektor3D poz, Wektor3D wym, string kol)
{
    std::shared_ptr<Przesz_Prostopad> Wsk = std::make_shared<Przesz_Prostopad>(sc,poz,wym,kol);
    Przeszkoda::lista.push_back( Wsk );

    return Wsk;
}

Przesz_Prostopad::Przesz_Prostopad(std::shared_ptr<drawNS::Draw3DAPI>& sc, Wektor3D poz, Wektor3D wym, string kol)
{
    this->scena = sc;
    this->kolor = kol;
    this->pozycja = poz;
    this->wymiary = wym;
    this->rysuj();
}

bool Przesz_Prostopad::czyKolizja(std::shared_ptr<Interfejs> D) const
{
    double wymD = D->getWymiary().dlugosc()*0.7;
    bool osX = D->getPozycja()[0] <= (this->pozycja[0] + this->wymiary[0]/2 + wymD) && D->getPozycja()[0] >= (this->pozycja[0] - this->wymiary[0]/2 - wymD);
    bool osY = D->getPozycja()[1] <= (this->pozycja[1] + this->wymiary[1]/2 + wymD) && D->getPozycja()[1] >= (this->pozycja[1] - this->wymiary[1]/2 - wymD);;
    bool osZ = D->getPozycja()[2] <= (this->pozycja[2] + this->wymiary[2]/2 + wymD) && D->getPozycja()[2] >= (this->pozycja[2] - this->wymiary[2]/2 - wymD);;

    if( osX && osY && osZ )
    {
        return true;
    }

    return false;
}
