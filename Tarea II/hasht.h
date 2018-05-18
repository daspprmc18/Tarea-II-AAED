#ifndef HASH_CLASS
#define HASH_CLASS

#include <list>
#include <vector>
#include <algorithm>

using std::vector;
using std::list;
using std::fill;

template <typename T>

class hasht {
public:

    hasht(int nEntradas) : numEntradas(nEntradas) {

        tabla.resize(nEntradas);        // Reestructura el tamaño del vector.
        for (int i = 0; i < numEntradas; ++i)
            tabla[i].resize(numEntradas); // Reestructura el tamaño de la lista.
    };
    // Constructor que especifica el numero de cubetas (entradas) 
    // en la tabla

    hasht(const hasht<T>& obj) {

        numEntradas = obj.numEntradas;
        typename list<T>::iterator begin;
        typename list<T>::iterator end;
        
        
    };
    // Constructor copia

    ~hasht() {
    };
    // Destructor (borra la tabla)

    T* search(const T& item) {
    };
    // Retorna un puntero a la llave o NULL si no se encuentra

    void insert(const T& item) {
    };
    // Inserta el elemento en la tabla

private:
    int numEntradas;
    // Nmero de entradas en la tabla
    vector< list<T> > tabla;
    // La tabla es un vector de listas de STL
} ;
#endif