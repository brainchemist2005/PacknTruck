/*  INF3105 - Structures de données et algorithmes      *
 *  UQAM / Département d'informatique                   *
 * 	TP1                                                 */

#include "entrepot.h"

ostream& operator << (ostream& os, const Entrepot& entrepot)
{
	os << "Number of boxes: " << entrepot.numberBoxes << " Position: (" << entrepot.longitude << "," << entrepot.latitude << ")";
    return os;
}


istream& operator>>(istream& is, Tableau<Entrepot>& entrepots)
{
    Entrepot entrepot;
    char comma, op, cp, space;

    is >> space;

    while (is >> entrepot.numberBoxes >> op >> entrepot.longitude >> comma >> entrepot.latitude >> cp)
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

Entrepot::Entrepot(double _x, double _y, int _numberBoxes, int _id)
        : numberBoxes(_numberBoxes), id(_id), longitude(_x), latitude(_y) {

}

Entrepot::Entrepot(const Entrepot& other)
        : numberBoxes(other.numberBoxes), id(other.id), longitude(other.longitude), latitude(other.latitude), distance(other.distance) {
}
