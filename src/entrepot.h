/*  INF3105 - Structures de données et algorithmes   *
 *  UQAM / Département d'informatique                *
 *  TP1                                              */

#if !defined(_ENTREPOT__H_)
#define _ENTREPOT__H_

#include <iostream>
#include "position.h"
#include "tableau.h"

using namespace std;

// Représente un entrepot
class Entrepot{
  public:
    
    // Interface publique ici.
    
  private:
    // Représentation ici.
    
  friend ostream& operator << (ostream& os, const Entrepot& entrepot);
  friend istream& operator >> (istream& is, Entrepot& entrepot);
};
#endif
