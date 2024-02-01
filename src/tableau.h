/* UQAM / Département d'informatique
   INF3105 - Structures de données et algorithmes
   Squelette pour la classe générique Tableau<T> pour le TP1 et Lab3.

   AUTEUR(S):
    1) Nom + Code permanent du l'étudiant.e 1
    2) Nom + Code permanent du l'étudiant.e 2
*/

#if !defined(_TABLEAU___H_)
#define _TABLEAU___H_

#include <assert.h>

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

  private:
    T*             elements;
    int            nbElements;
    int            capacite;
};


// ---------- Définitions -------------


template <class T>
Tableau<T>::Tableau(int capacite_)
{
    // À compléter
    elements = new T[1024]; // cette ligne n'est peut-être pas bonne.
}

template <class T>
Tableau<T>::Tableau(const Tableau& autre)
{
	// À compléter
}

template <class T>
Tableau<T>::~Tableau()
{
	// À compléter
}

template <class T>
int Tableau<T>::taille() const
{
	// À compléter
    return 0;
}

template <class T>
void Tableau<T>::ajouter(const T& item)
{
	// À compléter
}

template <class T>
void Tableau<T>::inserer(const T& element, int index)
{
	// À compléter
}

template <class T>
void Tableau<T>::enlever(int index)
{
	// À compléter
}

template <class T>
int Tableau<T>::chercher(const T& element)
{
	// À compléter
    // Voir la fonction Tableau<T>::contient() dans les notes de cours à la page 47.
    // Il suffit de l'adapter pour retourner la position au lieu d'un booléen.
    return -1;
}

template <class T>
void Tableau<T>::vider()
{
    // À compléter
}

template <class T>
const T& Tableau<T>::operator[] (int index) const
{
	// À compléter
    return elements[0];
}

template <class T>
T& Tableau<T>::operator[] (int index)
{
	// À compléter
    return elements[0];
}

template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
	// À compléter
    return *this;
}

template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{
	// À compléter
    return false;
}

#endif //define _TABLEAU___H_
