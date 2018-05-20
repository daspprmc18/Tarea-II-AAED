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

template <typename T>

class hasht {
private:
    int numEntradas;
    // Número de entradas en la tabla

    vector< list<T> > tabla;
    // La tabla es un vector de listas de STL

private:

    double loadF () {

        double n = 0.0L;

        for ( int i = 0; i < numEntradas; ++i ) // Calcula n.
            n += tabla.at( i ).size( );

        // Calcula factor de carga: m/n .

        double loadF = ( double ) numEntradas / n;
        return loadF;
    };

public:

    hasht (int nEntradas) : numEntradas (nEntradas) {
        tabla.resize( numEntradas );
    };
    // Constructor que especifica el numero de cubetas (entradas) 
    // en la tabla

    hasht (const hasht<T>& obj) {

        numEntradas = obj.numEntradas;

        typename list<T>::iterator listBeginObj;
        typename list<T>::iterator listEndObj;
        typename list<T>::iterator listBegin;

        for ( int i = 0; i < numEntradas; ++i ) {

            if ( !obj.tabla[i].empty( ) ) {

                listBeginObj  = obj.tabla[i].begin( );
                listEndObj    = obj.tabla[i].end( );
                listBegin     = tabla[i].begin( );
                copy( listBeginObj, listEndObj, listBegin );
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

    double loadFactor () {
        return loadF( );
    };

    void printTable () {

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
    }

} ;
#endif