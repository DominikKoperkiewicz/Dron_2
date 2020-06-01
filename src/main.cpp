#include "Dron.hh"
#include "Prostopadloscian.hh"
#include "Wirnik.hh"
#include "Powierzchnia.hh"
#include "Tafla.hh"
#include "Dno.hh"
#include "Obiekt3D.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "Przeszkoda.hh"

#include <iostream>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::cin;
using std::endl;


void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

void menu() {
    cout << "-----------------------------\n";
    cout << "plyn    - p [odleglosc] [kat]\n";
    cout << "rotacja - r [kat]            \n";
    cout << "pomoc   - h                  \n";
    cout << "wyjscie - q                  \n";
    cout << "-----------------------------\n";
}

int main()
{
    std::shared_ptr<drawNS::Draw3DAPI> scena(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000));
    scena->change_ref_time_ms(0);


    int a;
    Dno Dn(scena);
    Tafla taf(scena);
    Dron D(scena);

    Dn.rysuj();
    taf.rysuj();
    D.rysuj();

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
                D.plyn(d1, d2);
                break;
            case 'r':
                cin >> d1;
                D.rotacjaZ(d1);
                break;
            case 'h':
                menu();
                break;
            case 'q':
                return 0;
        }
    }
    return 0;
}
