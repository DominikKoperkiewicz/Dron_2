#include "Dron.hh"
#include "Interfejs.hh"
#include "Prostopadloscian.hh"
#include "Wirnik.hh"
#include "Powierzchnia.hh"
#include "Tafla.hh"
#include "Dno.hh"
#include "Obiekt3D.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "Przeszkoda.hh"
#include "Przesz_Prostopad.hh"

#include <iostream>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::cin;
using std::endl;

std::shared_ptr<Interfejs> wybrany;

void menu() {
    cout << "--------------------------------\n";
    cout << "plyn       - p [odleglosc] [kat]\n";
    cout << "rotacja    - r [kat]            \n";
    cout << "statystyka - s                  \n";
    cout << "Wybierz    - w [kolor] (r,g,b)  \n";
    cout << "pomoc      - h                  \n";
    cout << "wyjscie    - q                  \n";
    cout << "--------------------------------\n";
}

void wybor()
{
    char ch;
    cin >> ch;
    switch(ch)
    {
        case 'r': wybrany = Przeszkoda::getDron(0);
            break;
        case 'g': wybrany = Przeszkoda::getDron(1);
            break;
        case 'b': wybrany = Przeszkoda::getDron(2);
    }
}

int main()
{
    //TWORZENIE SCENY
    std::shared_ptr<drawNS::Draw3DAPI> scena(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000));
    scena->change_ref_time_ms(0);

    //TWORZENIE ELEMENTOW SCENY
    Dno::stworz(scena);
    Tafla::stworz(scena);
    Przesz_Prostopad::stworz(scena, { 0,-3,-3}, {2,4,4}, "black");
    Przesz_Prostopad::stworz(scena, { 3, 3,-4.5}, {3,3,1}, "black");
    Przesz_Prostopad::stworz(scena, {-3,-3,-4}, {1,1,2}, "black");

    Dron::stworz(scena, {0,0,1.5}, 0.85, "red");
    Dron::stworz(scena, {3, 3, -1}, 0.7, "green");
    Dron::stworz(scena, {-3,-3,0}, 0.5, "blue");

    Przeszkoda::getDron(0)->rysuj();
    Przeszkoda::getDron(1)->rysuj();
    Przeszkoda::getDron(2)->rysuj();

    wybrany = Przeszkoda::getDron(0);

    menu();

    char c;
    double d1,d2;
    while(true)
    {
        cin >> c;
        switch(c)
        {
            case 'p':
                cin >> d1 >> d2;
                wybrany->plyn(d1, d2);
                break;
            case 'r':
                cin >> d1;
                wybrany->rotacjaZ(d1);
                break;
            case 's':
                Przeszkoda::statystyka();
                break;
            case 'h':
                menu();
                break;
            case 'w':
                wybor();
                break;
            case 'q':
                return 0;
        }
    }
    return 0;
}
