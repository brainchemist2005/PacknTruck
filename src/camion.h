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

    // Interface publique ici.

  private:
    // Repr�sentation ici.

  friend ostream& operator << (ostream& os, const Camion& camion);
  friend istream& operator >> (istream& is, Camion& camion);
};

#endif

