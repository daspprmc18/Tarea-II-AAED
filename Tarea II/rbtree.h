#ifndef RED_BLACK_rbtree
#define RED_BLACK_rbtree

#include <stdio.h>
#include <stack>

enum colors {
    RED, BLACK
};

// Nodos del arbol:

template <typename T>
class rbnode {
public:
    // Esta clase es para ser usada por otras clases.
    // Por eficiencia se hacen los atributos publicos.
    T key;
    rbnode<T> *p, *left, *right;
    enum colors color;

    // Constructor por omision.

    rbnode () {
    };

    // Constructor por copia del nodo.

    rbnode (const rbnode<T> * obj, const rbnode<T> * objNil, rbnode<T> * parent, rbnode<T> * nilPtr) {
    }

    // Inicializacion de datos miembro.

    rbnode (const T& k, rbnode<T> *w = NULL, rbnode<T> *y = NULL,
            rbnode<T> *z = NULL, enum colors c = RED) :
    key (k), p (w), left (y), right (z), color (c) {
    };

    ~rbnode () {

    }
};

// Arbol:

template <typename T>
class rbtree {
public:

    rbtree () {
    };
    // Constructor (crea un arbol vacio)

    rbtree (const rbtree<T>& obj) {
    };
    // Constructor copia

    ~rbtree () {
    };
    // Destructor (borra el arbol)

    void inorderTreeWalk (rbnode<T>* x, std::stack<T> & pila) {
    };
    // Efectua un recorrido en orden del subarbol cuya raz es apuntada
    // por x. En cada visita apila la llave de cada nodo y su color.
    // Es decir, cada vez que se llega a un nodo se ejecutan las 
    // instrucciones pila.push(x->key); y luego pila.push(colorDeX).
    // Para efectos de la tarea, si el color del nodo es rojo, 
    // ponga en la pila un 0, y si es negro, ponga un 1.
    // Si se hace correctamente, al finalizar el mtodo la pila debera 
    // contener las llaves de los nodos del subrbol (y su color) 
    // ordenadas de mayor a menor.

    rbnode<T>* treeSearch (const T& k) {
    };
    // Busca la llave recursivamente, si la encuentra devuelve un 
    // puntero al nodo que la contiene, sino devuelve NULL.

    rbnode<T>* iterativeTreeSearch (const T& k) {
    };
    // Igual que en el anterior pero usa un procedimiento iterativo.

    rbnode<T>* treeMinimum () {
    };
    // Devuelve el nodo con la llave menor.
    // Si el arbol esta vacio devuelve NULL.

    rbnode<T>* treeMaximum () {
    };
    // Devuelve el nodo con la llave mayor.
    // Si el arbol esta vacio devuelve NULL.

    rbnode<T>* treeSuccessor (const rbnode<T>* x) {
    };
    // Devuelve el nodo cuya llave es la siguiente mas grande que 
    // la del nodo x. Si no existe tal nodo devuelve NULL.

    void treeInsert (rbnode<T>* z) { //aux es y, actual es x.
    };
    // Inserta el nodo z en la posicion que le corresponde en el arbol.

    node<T>* treeDelete (node<T>* z) {
    };
    // Saca del arbol la llave contenida en el nodo apuntado por z.
    // Devuelve la direccion del nodo eliminado para que se pueda 
    // disponer de el.

    rbnode<T> * getRoot () const {
        return this->root;
    };

    // Devuelve la raiz del arbol. (Para efectos de revision de la tarea).

    rbnode<T> * getNil () const {
        return this->nil;
    };
    // Devuelve T.nil. (Para efectos de revision de la tarea).

private:

    rbnode<T> *root; // raiz del arbol
    rbnode<T> *nil; // nodo nil (hoja) del arbol

};

#endif // RED_BLACK_rbtree