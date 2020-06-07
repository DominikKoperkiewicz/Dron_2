#include "Wirnik.hh"

void Wirnik::rysuj()
{
    Wektor3D poz = pozycja;
    Wektor3D W = wymiary/2;

    Wektor3D tab[12];

    tab[0] = {-W[0]/2, W[1], W[2] };
    tab[1] = {-W[0], 0.0 , W[2] };
    tab[2] = {-W[0]/2,-W[1], W[2] };
    tab[3] = { W[0]/2,-W[1], W[2] };
    tab[4] = { W[0], 0.0 , W[2] };
    tab[5] = { W[0]/2, W[1], W[2] };

    tab[6] = {-W[0]/2, W[1],-W[2] };
    tab[7] = {-W[0], 0.0 ,-W[2] };
    tab[8] = {-W[0]/2,-W[1],-W[2] };
    tab[9] = { W[0]/2,-W[1],-W[2] };
    tab[10] = { W[0], 0.0 ,-W[2] };
    tab[11] = { W[0]/2, W[1],-W[2] };


    for(int i = 0; i < 12; i++)
    {
        tab[i] = orientacjaX * orientacjaY * orientacjaZ * tab[i];
        tab[i] = tab[i] + poz;
    }

    const std::vector<std::vector<Point3D> > points_map = {{
    drawNS::Point3D(tab[0][0], tab[0][1], tab[0][2] ),
    drawNS::Point3D(tab[1][0], tab[1][1], tab[1][2] ),
    drawNS::Point3D(tab[2][0], tab[2][1], tab[2][2] ),
    drawNS::Point3D(tab[3][0], tab[3][1], tab[3][2] ),
    drawNS::Point3D(tab[4][0], tab[4][1], tab[4][2] ),
    drawNS::Point3D(tab[5][0], tab[5][1], tab[5][2] )
    },{
    drawNS::Point3D(tab[6][0], tab[6][1], tab[6][2] ),
    drawNS::Point3D(tab[7][0], tab[7][1], tab[7][2] ),
    drawNS::Point3D(tab[8][0], tab[8][1], tab[8][2] ),
    drawNS::Point3D(tab[9][0], tab[9][1], tab[9][2] ),
    drawNS::Point3D(tab[10][0], tab[10][1], tab[10][2] ),
    drawNS::Point3D(tab[11][0], tab[11][1], tab[11][2] )
    }};

    int tmp = this->id;
    this->id = this->scena->draw_polyhedron(points_map, this->kolor);
    this->scena->erase_shape(tmp);
}
