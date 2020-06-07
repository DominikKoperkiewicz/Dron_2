#include "Przeszkoda.hh"


std::vector<std::shared_ptr<Przeszkoda> > Przeszkoda::lista;
std::vector<std::shared_ptr<Interfejs> > Przeszkoda::lista_dronow;
int Przeszkoda::stworzone = 0;
int Przeszkoda::zniszczone = 0;

bool Przeszkoda::kolizjaDrona(std::shared_ptr<Interfejs> D)
{
    for(std::shared_ptr<Przeszkoda> n : lista)
    {
        if( n->czyKolizja(D) ) { return true; }
    }
    return false;
}

void Przeszkoda::statystyka()
{
    std::cout << "\n Stworzone: " << Przeszkoda::stworzone;
    std::cout << "\nIstniejace: " << Przeszkoda::stworzone-zniszczone;
    std::cout << "\nZniszczone: " << Przeszkoda::zniszczone;
    std::cout << "\n";
}
