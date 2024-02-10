/*  INF3105 - Structures de donn�es et algorithmes   *
 *  UQAM / D�partement d'informatique                *
 *  TP1                                              */

#if !defined(_ENTREPOT__H_)
#define _ENTREPOT__H_

#include <iostream>
#include "position.h"
#include "tableau.h"

using namespace std;

// Repr�sente un entrepot
class Entrepot{
  public:
    // Interface publique ici
    Entrepot(float x=0, float y=0, int numberBoxes=0);
    Entrepot(const Entrepot&);

    int numberBoxes;
    float x,y;

    float getLatitude() const
    {
        return x;
    }

    float getLongitude() const
    {
        return y;
    }

    void setLatitude(float x)
    {
        this->x = x;
    }

    void setLongitude(float y)
    {
        this->y = y;
    }


private:
    // Repr�sentation ici.
    //float x,y; for now

  friend ostream& operator << (ostream& os, const Entrepot& entrepot);
  friend istream& operator >> (istream& is, Tableau<Entrepot>& entrepots);
};
#endif
