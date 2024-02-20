/*  INF3105 - Structures de données et algorithmes      *
 *  UQAM / Département d'informatique                   *
 * 	TP1                                                 */

#ifndef CAMION_H_
#define CAMION_H_
#include <iostream>

#include "position.h"
#include "entrepot.h"

using namespace std;

// Représente un camion
class Camion{
  public:
    Camion(double x=0, double y=0, int capacity=0, int numberBoxesIn=0);
    Camion(const Camion&);

    // Interface publique ici.
    void truckPosition(Tableau<Entrepot>& entrepots, Camion& camion);

    double getLongitude()
    {
     return longitude;
    }

    double getLatitude()
    {
        return latitude;
    }

    int getCapacity() const
    {
        return capacity;
    }

  private:
    double longitude;
    double latitude;
    int capacity;
    int numberBoxesIn;

  friend ostream& operator << (ostream& os, const Camion& camion);
  friend istream& operator >> (istream& is, Camion& camion);
};

#endif

