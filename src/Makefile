# Makefile pour TP1.
# Adaptez ce fichier au besoin (si vous ajouter des fichiers).


# Choisir l'une des deux configurations (-g: Debug | -O2: Release)
OPTIONS = -g -O0 -Wall
#OPTIONS = -O2 -Wall

all : tp1

tp1 : tp1.cpp position.o entrepot.o camion.o
	g++ ${OPTIONS} -o tp1 tp1.cpp position.o entrepot.o camion.o
	
position.o : position.cpp position.h tableau.h
	g++ ${OPTIONS} -c -o position.o position.cpp

entrepot.o : entrepot.cpp entrepot.h position.h tableau.h
	g++ ${OPTIONS} -c -o entrepot.o entrepot.cpp

camion.o : camion.cpp camion.h position.h 
	g++ ${OPTIONS} -c -o camion.o camion.cpp

clean:
	rm -rf tp1 *~ *.o

