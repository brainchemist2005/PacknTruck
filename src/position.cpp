/*  INF3105 - Structures de donn?es et algorithmes       *
 *  UQAM / D?partement d'informatique                    *
 *  TP1                                                  */

#include <assert.h>
#include <math.h>
#include <cmath>

#include "position.h"

#define PI 3.14159265358979323846
#define RAYON_TERRE 6371008.8

Position::Position(const Position& position)
        : latitude(position.latitude), longitude(position.longitude)
{
}

Position::Position(double latitude_, double longitude_)
        : latitude(latitude_), longitude(longitude_)
{
}

double Position::distance(const Position& position) const {
    const double lat1_rad = latitude * PI / 180.0;
    const double lon1_rad = longitude * PI / 180.0;
    const double lat2_rad = position.latitude * PI / 180.0;
    const double lon2_rad = position.longitude * PI / 180.0;
    double dlat = lat2_rad - lat1_rad;
    double dlon = lon2_rad - lon1_rad;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1_rad) * cos(lat2_rad) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return RAYON_TERRE * c;
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

