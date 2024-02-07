/*  INF3105 - Structures de données et algorithmes      *
 *  UQAM / Département d'informatique                   *
 * 	TP1                                                 */

#include "camion.h"

Camion::Camion(float _x, float _y, int _param1, int _param2): x(_x),y(_y)  {

}

ostream& operator << (ostream& os, const Camion& camion)
{
	os << "Truck position: (" << camion.x << camion.y << ")";

    return os;
}

istream& operator >> (istream& is, Camion& camion)
{
    char redundant;

    is >> camion.capacity;
    is >> redundant;

    return is;
}




