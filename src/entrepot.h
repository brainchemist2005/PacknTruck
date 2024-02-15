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
    // Interface publique ici
    Entrepot(float x=0, float y=0, int numberBoxes=0,int id=0);
    Entrepot(const Entrepot&);

    int numberBoxes,id;
    float longitude,latitude,distance;

    float getLatitude() const
    {
        return latitude;
    }

    float getLongitude() const
    {
        return longitude;
    }

    void setLatitude(float lat)
    {
        this->latitude = lat;
    }

    void setLongitude(float longi)
    {
        this->longitude = longi;
    }

    int pickUpEntrepot(Tableau<Entrepot>& arr, int max)
    {
        int box=0,x;
        for(int i=0 ; i<arr.taille(); i++)
        {
            if(arr[i].numberBoxes + box <= max)
            {
                box += arr[i].numberBoxes;
                arr[i].numberBoxes = 0;
            }

            else
            {
                x = max - box;
                box += x;
                x = arr[i].numberBoxes - x;
                arr[i].numberBoxes = x;
                return i;
            }
        }
        return arr.taille()-1;
    }

    int partition(Tableau<Entrepot>& arr, int low, int high) {
        Entrepot pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low; j <= high - 1; j++) {
            // If current element is smaller than the pivot
            if (arr[j].distance < pivot.distance) {
                i++;    // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void swap(Entrepot& a, Entrepot& b) {
        Entrepot t = a;
        a = b;
        b = t;
    }

    void quickSort(Tableau<Entrepot>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);  // Before pi
            quickSort(arr, pi + 1, high); // After pi
        }
    }


private:
    // Représentation ici.
    //float longitude,latitude; for now

  friend ostream& operator << (ostream& os, const Entrepot& entrepot);
  friend istream& operator >> (istream& is, Tableau<Entrepot>& entrepots);
};
#endif
