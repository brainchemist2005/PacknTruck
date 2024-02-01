/*  INF3105 - Structures de données et algorithmes       *
 *  UQAM / Département d'informatique                    *
 *  TP1                                                  */

#if !defined(_POSITION__H_)
#define _POSITION__H_

#include <iostream>

// Cette classe représente un point sur la surface de la Terre.
class Position{
  public:
    Position(){}
    Position(double latitude_, double longitude_);
    Position(const Position&);

    double distance(const Position&) const;

  private:
    double latitude;
    double longitude;

  friend std::ostream& operator << (std::ostream&, const Position&);
  friend std::istream& operator >> (std::istream&, Position&);
};
#endif

