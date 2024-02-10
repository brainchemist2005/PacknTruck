/*  INF3105 - Structures de données et algorithmes      *
 *  UQAM / Département d'informatique                   *
 * 	TP1                                                 */

#include "camion.h"

Camion::Camion(float _x, float _y, int _param1, int _param2): x(_x),y(_y)  {

}

ostream& operator << (ostream& os, const Camion& camion)
{
    char vir= ',';
	os << "Truck position: (" << camion.x << vir << camion.y << ")";

    return os;
}

void Camion::truckPosition(Tableau<Entrepot>& entrepots,Camion& camion)
{
    int max = 0,numberofbox;
    numberofbox = entrepots[0].numberBoxes;

    for(int i=1 ; i< entrepots.taille(); i++)
    {
        if(entrepots[i].numberBoxes > numberofbox) {
            numberofbox = entrepots[i].numberBoxes;
            max = i;
        }
    }

    camion.x = entrepots[max].x;
    camion.y = entrepots[max].y;

}

istream& operator >> (istream& is, Camion& camion)
{
    char redundant;

    is >> camion.capacity;
    is >> redundant;

    return is;
}

//4:30 4:40
//right autouroute lour park ouest