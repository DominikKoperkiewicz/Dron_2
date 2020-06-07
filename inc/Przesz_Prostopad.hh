#ifndef PRZESZ_PROSTOPAD_HH
#define PRZESZ_PROSTOPAD_HH

#include "Prostopadloscian.hh"
#include "Przeszkoda.hh"

class Przesz_Prostopad : public Prostopadloscian, public Przeszkoda{
protected:

public:
    static std::shared_ptr<Przesz_Prostopad> stworz(std::shared_ptr<drawNS::Draw3DAPI>& sc, Wektor3D poz, Wektor3D wym, string kol);
    Przesz_Prostopad(std::shared_ptr<drawNS::Draw3DAPI>& sc, Wektor3D poz, Wektor3D wym, string kol);
    ~Przesz_Prostopad() {}
    bool czyKolizja(std::shared_ptr<Interfejs> D) const override;
};

#endif
