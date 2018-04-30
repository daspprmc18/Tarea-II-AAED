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

        delete left;
        delete right;
        std::cout << "Eliminando Nodo " << key << "\n\n";
    }
};

// Arbol:

template <typename T>
class tree {
private:

    node<T>* treeSearch (node<T>* c, const T& k) {

        if ( !c || c->key == k ) // Si C es NULL o el elemento en el nodo apuntado por C es el que se busca
            return c;

        if ( k < c->key ) // Si K es menor que el elemento en el nodo apuntado por C
            return treeSearch( c->left, k ); // Buscar K en subárbol izquierdo.
        else
            return treeSearch( c->right, k ); // Buscar K en el subárbol derecho.
    };
public:

    tree () : root (nullptr) {
    };
    // Constructor. Crea un arbol vacio

    tree (const tree<T>& obj) {
    };
    // Constructor copia

    ~tree () {
        delete root;
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

    node<T>* treeSearch (const T & k) {
        return treeSearch( root, k );
    };
    // Busca la llave recursivamente; si la encuentra, devuelve un 
    // apuntador al nodo que la contiene, sino devuelve NULL

    node<T>* iterativeTreeSearch (const T & k) {

        node<T> * current = root;

        while ( current != nullptr && current->key != k ) { // Mientras C sea distinto de NULL y el elemento en el nodo apuntado por C no es K.

            if ( k < current->key ) // Si K es menor que el elemento en el nodo apuntado por C
                current = current->left; // Buscar K en subárbol izquierdo.
            else
                current = current->right; // Buscar K en el subárbol derecho.
        }
        return current;
    };
    // Lo mismo que en el anterior pero usando un procedimiento 
    // iterativo

    node<T>* treeMinimum () {

        node<T>* current = root;

        while ( current->left != nullptr ) // Mientras el nodo apuntado por C tenga hijo izquierdo.
            current = current->left; // Avanza C al hijo izquierdo de C.

        return current;
    };
    // Devuelve el nodo que tiene la llave menor.
    // Si el arbol está vacio devuelve NULL.

    node<T>* treeMaximum () {

        node<T> * current = root;

        while ( current->right != nullptr ) // Mientras el nodo apuntado por C tenga hijo derecho.
            current = current->right; // Avanza C al hijo derecho de C.

        return current;
    };
    // Devuelve el nodo que tiene la llave mayor.
    // Si el arbol esta vacio devuelve NULL.

    node<T>* treeSuccessor (const node<T>* x) {
    };
    // Devuelve el nodo cuya llave es la que le sigue a la
    // del nodo x. Si no existe tal nodo devuelve NULL.

    void treeInsert (node<T>* z) {

        node<T> * trailing = nullptr; // Puntero que se arrastra para tener una referencia al padre del nodo que vamos a insertar.
        node<T> * current = root; // Puntero que busca la posición en la cual vamos a insertar al nuevo nodo. 

        while ( current ) { // Mientras C no apunte a NULL.

            trailing = current; // T referencia al padre de C.

            if ( z->key < current->key ) // Si el elemento en el nodo apuntado por Z es menor que el elemento en el nodo apuntado por C: 
                current = current->left; // Actualice C al subárbol izquierdo de C.
            else
                current = current->right; // Actualice C al subárbol derecho de C.

        } // Finaliza cuando encuentra la posición adecuada para insertar el nodo Z.

        z->p = trailing; // El padre de Z es el nodo al cual apunta T actualmente.

        if ( !trailing ) // El árbol está vacío.
            root = z; // Z es la nueva raíz.
        else if ( z->key < trailing->key ) { // Si el elemento en el nodo apuntado por Z es menor que el elemento en el nodo apuntado por T: 
            trailing->left = z; // Z es hijo izquierdo de T.
        } else
            trailing->right = z; // Z es hijo derecho de T.
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
    // Devuelve la raiz del arbol. (Para efectos de revisión de la tarea).

private:
    node<T> *root; // root of the Tree

};
#endif // BINARY_SEARCH_Tree