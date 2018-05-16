#ifndef HASH_CLASS
#define HASH_CLASS

#include <list>
#include <vector>

template <typename T>

class hasht {
public:

    hasht (int nEntradas) {
    };
    // Constructor que especifica el numero de cubetas (entradas) 
    // en la tabla

    hash (const hasht<T>& obj) {
    };
    // Constructor copia

    ~hasht () {
    };
    // Destructor (borra la tabla)

    T* search (const T& item) {
    };
    // Retorna un puntero a la llave o NULL si no se encuentra

    void insert (const T& item) {
    };
    // Inserta el elemento en la tabla

private:
    int numEntradas;
    // Nmero de entradas en la tabla
    std::vector< std::list<T> > tabla;
    // La tabla es un vector de listas de STL
};
#endif