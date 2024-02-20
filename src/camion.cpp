/*  INF3105 - Structures de données et algorithmes      *
 *  UQAM / Département d'informatique                   *
 * 	TP1                                                 */

#include "camion.h"

Camion::Camion(double _x, double _y, int _param1, int _param2): longitude(_x), latitude(_y)  {

}

ostream& operator << (ostream& os, const Camion& camion)
{
    char vir= ',';
	os << "Truck position: (" << camion.longitude << vir << camion.latitude << ")";

    return os;
}

void Camion::truckPosition(Tableau<Entrepot>& entrepots,Camion& camion)
{
    int max = 0,numberofbox;
    numberofbox = entrepots[0].numberBoxes;

    for(int i=1 ; i< entrepots.taille(); i++)
    {
        if(entrepots[i].numberBoxes > numberofbox)
        {
            numberofbox = entrepots[i].numberBoxes;
            max = i;
        }
    }

    camion.longitude = entrepots[max].longitude;
    camion.latitude = entrepots[max].latitude;
}

istream& operator >> (istream& is, Camion& camion)
{
    char redundant;

    is >> camion.capacity;
    is >> redundant;

    return is;
}