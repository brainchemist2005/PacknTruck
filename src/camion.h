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

    // Interface publique ici.

  private:
    // Représentation ici.

  friend ostream& operator << (ostream& os, const Camion& camion);
  friend istream& operator >> (istream& is, Camion& camion);
};

#endif

