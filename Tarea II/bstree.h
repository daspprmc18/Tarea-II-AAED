#ifndef BINARY_SEARCH_Tree
#define BINARY_SEARCH_Tree
#include <iostream>
#include <stack>
using namespace std;
// Nodos del arbol:

template <typename T>
class node {
public:
    // Esta clase es usada por otras clases.
    // Para mayor eficiencia, los atributos se hacen publicos.
    T key;
    node<T> *p, *left, *right;

    // Constructor por omision

    node () {
    };

    // Constructor por copia. Copia el nodo y sus hijos.

    node (const node<T> * obj, node<T> * padre) {
    }

    // Inicializacion de datos miembro

    node (const T& k, node<T> *w = NULL, node<T> *y = NULL, node<T> *z = NULL) : key (k), p (w), left (y), right (z) {
    };

    ~node () {
    }
};

// Arbol:

template <typename T>
class tree {
public:

    tree () {
    };
    // Constructor. Crea un arbol vacio

    tree (const tree<T>& obj) {
    };
    // Constructor copia

    ~tree () {
    };
    // Destructor (borra el arbol)

    void inorderTreeWalk (node<T>* x, stack<T> & pila) {
    };

    // Efectua un recorrido en orden del subrbol cuya raiz es apuntada
    // por x, guardando en cada visita la llave de cada nodo en la pila.
    // Es decir, cada vez que se llega a un nodo se hace
    // pila.push(x->key). Si se hace correctamente, al finalizar el 
    // metodo la pila debe contener las llaves de los nodos del 
    // subarbol ordenadas de mayor a menor.

    node<T>* treeSearch (const T& k) {
    };
    // Busca la llave recursivamente; si la encuentra, devuelve un 
    // apuntador al nodo que la contiene, sino devuelve NULL

    node<T>* iterativeTreeSearch (const T& k) {
    };
    // Lo mismo que en el anterior pero usando un procedimiento 
    // iterativo

    node<T>* treeMinimum () {
    };
    // Devuelve el nodo que tiene la llave menor.
    // Si el arbol est vacio devuelve NULL.

    node<T>* treeMaximum () {
    };
    // Devuelve el nodo que tiene la llave mayor.
    // Si el arbol esta vacio devuelve NULL.

    node<T>* treeSuccessor (const node<T>* x) {
    };
    // Devuelve el nodo cuya llave es la que le sigue a la
    // del nodo x. Si no existe tal nodo devuelve NULL.

    void treeInsert (node<T>* z) {
    };
    // Inserta el nodo z en la posicion que le corresponde en el arbol.

    node<T>* treeDelete (node<T>* z) {
    };
    // Saca del arbol la llave contenida en el nodo apuntado por z.
    // Devuelve la direccion del nodo eliminado para que se pueda 
    // disponer de ella.

    node<T> * getRoot () const {
        return this->root;
    };
    // Devuelve la raiz del arbol. (Para efectos de revisin de la tarea).

private:
    node<T> *root; // root of the Tree

};
#endif // BINARY_SEARCH_Tree