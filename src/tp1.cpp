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
#include <iomanip>

using namespace std;

int tp1(std::istream& entree);

// argc: nombre d'arguments passés.
// argv: tableau de chaines de carractères.
// exemple: ./tp1 entrepot.txt
// argv[0]="./tp1"; argv[1]="entrepot.txt"

Position referencePosition;

bool compareEntrepotDistance(const Entrepot& e1, const Entrepot& e2) {
    Position pos1(e1.latitude, e1.longitude);
    Position pos2(e2.latitude, e2.longitude);

    double distance1 = pos1.distance(referencePosition);
    double distance2 = pos2.distance(referencePosition);

    return distance1 < distance2;
}

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
    Position position(camion.getLongitude(), camion.getLatitude());

    double result;

    std::cout << camion << std::endl;
    for (int i = 0; i < entrepots.taille(); ++i) {
        Position position1(entrepots[i].longitude, entrepots[i].latitude);

        result = position.distance(position1);

        entrepots[i].distance = result;

    }

    entrepot.quickSort(entrepots, 0, entrepots.taille()-1);

    int pickedUp = entrepot.pickUpEntrepot(entrepots,camion.getCapacity());

    for (int i = 0; i <= pickedUp; ++i) {
        std::cout << "Distance:" << std::setw(15) << std::left << entrepots[i].distance << "Number of boxes: "  << entrepots[i].numberBoxes
                  << "\tPosition: (" << entrepots[i].getLongitude() << ", " << entrepots[i].getLatitude() << ")" << std::endl;
    }

    std::ofstream outputFile("res+.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i <= pickedUp; ++i) {
            outputFile << "Distance:" << std::setw(15) << std::left << entrepots[i].distance << "Number of boxes: " << entrepots[i].numberBoxes
                       << "\tPosition: (" << entrepots[i].getLongitude() << ", " << entrepots[i].getLatitude() << ")" << std::endl;
        }
        outputFile.close();
    } else {
        std::cout << "Erreur de fichier" << std::endl;
    }

    return 0;
}