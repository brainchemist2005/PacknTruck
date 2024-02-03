/*  INF3105 - Structures de données et algorithmes      *
 *  UQAM / Département d'informatique                   *
 * 	TP1                                                 */

#include "entrepot.h"

ostream& operator << (ostream& os, const Entrepot& entrepot)
{
	os << "Number of boxes: " << entrepot.numberBoxes << "Position: (" << entrepot.x << "," << entrepot.y <<")";
    return os;
}

istream& operator >> (istream& is, Entrepot& entrepot)
{
    char comma, redundant, op, cp;

    is >> entrepot.numberBoxes;

    if(is)
    {
        is >> redundant >> op >> entrepot.x >> comma >> entrepot.y >> cp;
        assert(cp == ')');
        assert(op == '(');
        assert(comma == ',');
    }

    return is;
}

Entrepot::Entrepot(double _x, double _y, int _numberBoxes) : x(_x), y(_y), numberBoxes(_numberBoxes){

}

