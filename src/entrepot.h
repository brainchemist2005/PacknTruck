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
    
    // Interface publique ici.
    
  private:
    // Repr�sentation ici.
    
  friend ostream& operator << (ostream& os, const Entrepot& entrepot);
  friend istream& operator >> (istream& is, Entrepot& entrepot);
};
#endif
