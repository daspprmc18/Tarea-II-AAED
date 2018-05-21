#ifndef HASH_CLASS
#define HASH_CLASS

#include <list>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::vector;
using std::list;
using std::fill;
using std::copy;
using std::cout;

typedef long int Integer;

template <typename T>

class hasht {
private:
    int numEntradas;
    // Número de entradas en la tabla

    vector< list<T> > tabla;
    // La tabla es un vector de listas de STL

    /*private:

        double loadF () {

            double n = 0.0L;

            for ( int i = 0; i < numEntradas; ++i ) // Calcula n.
                n += tabla.at( i ).size( );

            // Calcula factor de carga: m/n .

            double loadF = ( double ) numEntradas / n;
            return loadF;
        };*/

public:

    hasht (int nEntradas) : numEntradas (nEntradas) {
        tabla.resize( numEntradas );
    };
    // Constructor que especifica el numero de cubetas (entradas) 
    // en la tabla

    hasht (const hasht<T>& obj) {

        numEntradas = obj.numEntradas;
        tabla.resize( numEntradas );

        for ( int i = 0; i < numEntradas; ++i ) {
            if ( !obj.tabla[i].empty( ) ) {
                tabla[i].insert( tabla[i].begin( ), obj.tabla[i].begin( ), obj.tabla[i].end( ) );
            }
        }
    };
    // Constructor copia

    ~hasht () {

        for ( int i = 0; i < numEntradas; ++i )
            tabla[i].clear( );

        tabla.clear( );
    };
    // Destructor (borra la tabla)

    T* search (const T& item) {

        int pos                       = item % numEntradas;
        T * result                    = nullptr;
        typename list<T>::iterator it = find( tabla[pos].begin( ), tabla[pos].end( ), item );

        if ( it != tabla[pos].end( ) ) // Asume que el operador != está sobrecargado para el tipo de datos T.
            result = &( *it );

        return result;
    };
    // Retorna un puntero a la llave o NULL si no se encuentra

    void insert (const T& item) { // h(k) = k mód m
        int pos = item % numEntradas; // Función de dispersión.
        tabla[pos].push_front( item );
    };
    // Inserta el elemento en la tabla

    /*double loadFactor () {
        return loadF( );
    };*/

    /*void printTable () {

        typename list<T>::iterator it;
        typename list<T>::iterator begin;
        typename list<T>::iterator end;

        cout << "Tabla de dispersión: \n\n";

        for ( int i = 0; i < numEntradas; ++i ) {

            cout << i << ": " << " ";

            begin = tabla[i].begin( );
            it = begin;
            end = tabla[i].end( );

            while ( it != end ) {

                cout << *it << "  ";
                ++it;
            }
            cout << "\n\n";
        }
    }*/

    /*
    // Compara la lista en la posición i de el vector de *this con la lista en la posición i del vector de orig.
    // Si hay un solo valor distinto en alguna de las listas retorna falso.

    bool operator== ( hasht<T>& orig ) {

        for ( Integer i = 0; i < numEntradas; ++i ) {

            typename list<T>::iterator ito = orig.tabla[i].begin( ); // Iterador lista i de orig.

            for ( typename list<T>::iterator it = tabla[i].begin( ); it != tabla[i].end( ); ++it ) { // it: iterador de lista i de *this.

                if ( *it != *ito  )
                    return false;

                ++ito;
            }
        }
    };*/

} ;
#endif