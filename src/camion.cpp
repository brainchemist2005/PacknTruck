/*  INF3105 - Structures de données et algorithmes      *
 *  UQAM / Département d'informatique                   *
 * 	TP1                                                 */

#include "camion.h"

ostream& operator << (ostream& os, const Camion& camion)
{
	os << "Truck position: (" << camion.x << camion.y << ")";

    return os;
}

istream& operator >> (istream& is, Camion& camion)
{

    is >> camion.capacity;

    return is;
}




