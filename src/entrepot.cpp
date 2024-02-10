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

        entrepots.ajouter(entrepot);

        Entrepot entrepot(entrepot.x, entrepot.y, entrepot.numberBoxes);


        assert(op == '(');
        assert(comma == ',');
        assert(cp == ')');
    }

    // Print the information after adding the entrepots
    std::cout << "Number of warehouses: " << entrepots.taille() << std::endl;
    for (int i = 0; i < entrepots.taille(); ++i)
    {
        std::cout << "Warehouse ID: " << i << ", Coordinates: ("
                  << entrepots[i].getLatitude() << ", " << entrepots[i].getLongitude() << "), Number of boxes: " << entrepots[i].numberBoxes << std::endl;
    }

    return is;
}


Entrepot::Entrepot(float _x, float _y, int _numberBoxes) : numberBoxes(_numberBoxes), x(_x), y(_y){

}

