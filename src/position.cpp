/*  INF3105 - Structures de données et algorithmes       *
 *  UQAM / Département d'informatique                    *
 *  TP1                                                  */

#include <assert.h>
#include <math.h>

#include "position.h"

#define PI 3.14159265359
#define RAYON_TERRE 6371 * 1000  // en mètres

Position::Position(const Position& position)
  : latitude(position.latitude), longitude(position.longitude)
{
}

Position::Position(double latitude_, double longitude_)
  : latitude(latitude_), longitude(longitude_)
{
}

double Position::distance(const Position& position) const {
  double s1 = sin((position.latitude-latitude)/2);
  double s2 = sin((position.longitude-longitude)/2);
  return 2*RAYON_TERRE * asin(sqrt(s1*s1 + cos(latitude)*cos(position.latitude)*s2*s2));
}

std::ostream& operator << (std::ostream& os, const Position& position) {
  os << "(" 
     << (position.latitude * 180.0 / PI)
     << "," 
     << (position.longitude * 180.0 / PI)
     << ")";
  return os;
}

std::istream& operator >> (std::istream& is, Position& position) {
  char po, vir, pf;
  is >> po;
  if(is){
    is >> position.latitude >> vir >> position.longitude >> pf;
    assert(po=='(');
    assert(vir==',');
    assert(pf==')');
    position.latitude  *= PI / 180.0;
    position.longitude *= PI / 180.0;
  }
  return is;
}


