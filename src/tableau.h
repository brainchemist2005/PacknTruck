/* UQAM / Département d'informatique
   INF3105 - Structures de données et algorithmes
   Squelette pour la classe générique Tableau<T> pour le TP1 et Lab3.

   AUTEUR(S):
    1)  BOUARGAN ZAKARIAE BOUZ90340206
*/

#if !defined(_TABLEAU___H_)
#define _TABLEAU___H_

#include <assert.h>
#include <functional>
#include "entrepot.h"

template <class T>
class Tableau{

  public:
    Tableau(int capacite_initiale=4);
    Tableau(const Tableau&);
    ~Tableau();

    // Ajouter un élément à la fin
    void           ajouter(const T& element);
    // Vider le tableau
    void           vider();
    // Retourne le nombre d'éléments dans le tableau
    int            taille() const;

    // Insérer élément à la position index. 
    // Les éléments à partir de l'index sont décalés d'une position.
    void           inserer(const T& element, int index=0);

    // Enlève l'élément à la position index. 
    // Les éléments après l'index sont décalés d'une position après.
    void           enlever(int index=0);

    // Chercher et retourner la position de l'élément. Si non trouvé, retourner -1.
    int            chercher(const T& element);

    const T&       operator[] (int index) const;
    T&             operator[] (int index);

    bool           operator == (const Tableau<T>& autre) const;
    Tableau<T>&    operator = (const Tableau<T>& autre);

    void bubbleSort();

private:
    T*             elements;
    int            nbElements;
    int            capacite;

};



// ---------- Définitions -------------


template <class T>
Tableau<T>::Tableau(int capacite_) : nbElements(0), capacite(capacite_)
{
    elements = new T[capacite_];
}

template <class T>
Tableau<T>::Tableau(const Tableau& autre)
{
    elements = new T[capacite];

    for(int i=0; i<nbElements ; i++)
        elements[i] = autre[i];
}

template <class T>
Tableau<T>::~Tableau()
{
	delete[] elements;
}




template <class T>
int Tableau<T>::taille() const
{
    return nbElements;
}

template <class T>
void Tableau<T>::ajouter(const T& item)
{
    if(nbElements == capacite)
    {
        capacite *= 2;
        T * newElements = new T(capacite);
        for(int i=0; i<nbElements ; i++)
            newElements[i] = elements[i];

        delete[] elements;
        elements = newElements;
    }

    elements[nbElements++] = item;
}

template <class T>
void Tableau<T>::inserer(const T& element, int index)
{
    elements[index] = element;
}

template <class T>
void Tableau<T>::enlever(int index)
{
    if(nbElements == 0 || index >=nbElements || index < 0)
        return;

    for(int i=index ; i<nbElements-1 ; i++)
        elements[i] = elements[i+1];

    nbElements--;
}

template <class T>
int Tableau<T>::chercher(const T& element)
{
    for (int i = 0; i < nbElements; i++) {
        if (elements[i] == element) {
            return i;
        }
    }
    return -1;
}


template <class T>
void Tableau<T>::bubbleSort() {
    int n = this->taille();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            // Assuming T has a defined comparison operator for >
            if (this->elements[j] > this->elements[j+1]) {
                T temp = this->elements[j];
                this->elements[j] = this->elements[j+1];
                this->elements[j+1] = temp;
            }
        }
    }
}


template <class T>
void Tableau<T>::vider()
{
    nbElements = 0;
}

template <class T>
const T& Tableau<T>::operator[] (int index) const
{
    std::cout << index << " " << nbElements << std::endl;
    assert(index > 0 && index < nbElements);
    return elements[index];
}

template <class T>
T& Tableau<T>::operator[] (int index)
{
    assert(index >= 0 && index < nbElements);
    return elements[index];
}

template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
    if(this!=autre)
    {
        delete[] elements;
        capacite = autre.capacite;
        nbElements = autre.nbElements;

        elements = new T[capacite];

        for (int i = 0; i < nbElements; i++) {
            elements[i] = autre.elements[i];
        }
    }
    return *this;
}


template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{
    if(this != &autre)
        return false;

    for(int i=0 ; i<nbElements ; i++)
        if(elements[i] != autre.elements[i])
            return false;

    return true;
}

#endif //define _TABLEAU___H_
