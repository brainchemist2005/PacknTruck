/*  INF3105 - Structures de données et algorithmes   *
 *  UQAM / Département d'informatique                *
 *  TP1                                              *
 *                                                   */

#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include "entrepot.h"
#include "camion.h"

using namespace std;

int tp1(std::istream& entree);

// argc: nombre d'arguments passés.
// argv: tableau de chaines de carractères.
// exemple: ./tp1 entrepot.txt
// argv[0]="./tp1"; argv[1]="entrepot.txt"

int main(int argc, const char** argv)
{
    Tableau<Entrepot> entrepots;

    if(argc == 1){
    	// Pas d'argument entrepot ==> lecture depuis l'entrée standard avec std::cin.
    	return tp1(std::cin);
    }
    else
    	if(argc == 2){
    		ifstream fichier_entrepot(argv[1]);
    		if(fichier_entrepot.fail()){
    			cerr << "Erreur ouverture fichier camion_entrepôt : " << argv[1] << endl;
    			return 1;
    		}
    		else
    				return tp1(fichier_entrepot);
    	}
    	else {
    		cerr << "Trop de paramètres!" << endl;
    		return 2;
    	}
}

int tp1(istream& camion_entrepot){
    Tableau<Entrepot> entrepots;
	Camion camion;
	camion_entrepot >> camion;
	Entrepot entrepot;
    camion_entrepot >> entrepots;
    camion.truckPosition(entrepots,camion);

    std::cout << camion << std::endl;
    for (int i = 0; i < entrepots.taille(); ++i)
    {
        std::cout << "Distance:" << i << "\t\tNumber of boxes: " << entrepots[i].numberBoxes << "\t\tPosition: ("
                  << entrepots[i].getLatitude() << ", " << entrepots[i].getLongitude() << ")" << std::endl;
    }

    return 0;
}