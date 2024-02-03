/*  INF3105 - Structures de données et algorithmes      *
 *  UQAM / Département d'informatique                   *
 * 	TP1                                                 */

#ifndef CAMION_H_
#define CAMION_H_
#include <iostream>

#include "position.h"

using namespace std;

// Représente un camion
class Camion{
  public:
    Camion(double x=0, double y=0, int capacity=0, int numberBoxesIn=0);
    Camion(const Camion&);
    ~Camion();


    // Interface publique ici.
    void truckPosition() const;


  private:
    double x;
    double y;
    int capacity;
    int numberBoxesIn;

  friend ostream& operator << (ostream& os, const Camion& camion);
  friend istream& operator >> (istream& is, Camion& camion);
};

#endif

