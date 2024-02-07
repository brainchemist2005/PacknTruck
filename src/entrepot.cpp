/*  INF3105 - Structures de données et algorithmes      *
 *  UQAM / Département d'informatique                   *
 * 	TP1                                                 */

#include "entrepot.h"

ostream& operator << (ostream& os, const Entrepot& entrepot)
{
	os << "Number of boxes: " << entrepot.numberBoxes << " Position: (" << entrepot.x << "," << entrepot.y <<")";
    return os;
}

istream& operator >> (istream& is, Entrepot& entrepot)
{

    char comma, op, cp, space;

    is >> space;

    // Read number of boxes
    is >> entrepot.numberBoxes;

    // Read opening parenthesis
    is >> op;
    assert(op == '(');

    // Read coordinates
    is >> entrepot.x >> comma >> entrepot.y;

    // Read closing parenthesis
    is >> cp;
    assert(cp == ')');

    return is;
}

Entrepot::Entrepot(float _x, float _y, int _numberBoxes) : numberBoxes(_numberBoxes), x(_x), y(_y){

}

