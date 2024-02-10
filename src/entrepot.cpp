/*  INF3105 - Structures de données et algorithmes      *
 *  UQAM / Département d'informatique                   *
 * 	TP1                                                 */

#include "entrepot.h"

ostream& operator << (ostream& os, const Entrepot& entrepot)
{
	os << "Number of boxes: " << entrepot.numberBoxes << " Position: (" << entrepot.x << "," << entrepot.y <<")";
    return os;
}


istream& operator>>(istream& is, Tableau<Entrepot>& entrepots)
{
    Entrepot entrepot;
    char comma, op, cp, space;

    is >> space;

    while (is >> entrepot.numberBoxes >> op >> entrepot.x >> comma >> entrepot.y >> cp)
    {
        entrepot.id++;
        entrepots.ajouter(entrepot);

        Entrepot entrepot;

        assert(op == '(');
        assert(comma == ',');
        assert(cp == ')');
    }

    return is;
}

int nearestWarehouse()
{

}


Entrepot::Entrepot(float _x, float _y, int _numberBoxes, int _id) : numberBoxes(_numberBoxes), x(_x), y(_y), id(_id){

}

