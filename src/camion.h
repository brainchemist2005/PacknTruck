/*  INF3105 - Structures de donn�es et algorithmes      *
 *  UQAM / D�partement d'informatique                   *
 * 	TP1                                                 */

#ifndef CAMION_H_
#define CAMION_H_
#include <iostream>

#include "position.h"

using namespace std;

// Repr�sente un camion
class Camion{
  public:
    Camion(float x=0, float y=0, int capacity=0, int numberBoxesIn=0);
    Camion(const Camion&);


    // Interface publique ici.
    void truckPosition() const;


  private:
    float x;
    float y;
    int capacity;
    int numberBoxesIn;

  friend ostream& operator << (ostream& os, const Camion& camion);
  friend istream& operator >> (istream& is, Camion& camion);
};

#endif

