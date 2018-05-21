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

        p     = nullptr;
        left  =  nullptr;
        right = nullptr;
        key   = 0;
    }
} ;

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

    node<T>* treeMinimum (node<T>* x) const {

        node<T>* current = x;

        while ( current->left != nullptr ) // Mientras el nodo apuntado por C tenga hijo izquierdo.
            current = current->left; // Avanza C al hijo izquierdo de C.

        return current;
    };

    void treeTransplant (node<T> * u, node<T> * v) {

        if ( !u->p ) // Si U no tiene padre, U es la raíz del árbol.
            root = v; // V reemplaza a U como la raíz del árbol T.

        else if ( u == u->p->left ) // Si U es subárbol izquierdo ( hijo izquierdo ) de su padre.
            u->p->left = v; // V reemplaza a U como subárbol izquierdo del padre de U.

        else u->p->right = v; // V reemplaza a U como subárbol derecho del padre de U.

        if ( v ) // Si V no es NULL ( V reemplazó a U )
            v->p = u->p; // V y U deben tener el mismo padre.( Ahora el padre de V es el padre de U )
    };

    void copyTree (node<T>* c) {

        if ( c ) { // Si C es distinto de NULL

            node<T> * temp = new node<T>( c->key, nullptr, nullptr, nullptr );
            treeInsert( temp );
            copyTree( c->left ); // Copia subárbol izquierdo de C.
            copyTree( c->right ); // Copia subárbol derecho de C.
        }
    };

    void buildSequentialTree (const T& n) {

        node<T> * current = nullptr;
        node<T> * temp = nullptr;
        root = new node<T>( 0, nullptr, nullptr, nullptr );
        current = root;

        for ( T i = 1; i < n; ++i ) {

            temp = new node<T>( i, current, nullptr, nullptr );
            current->right = temp;
            current = current->right;
            temp = nullptr;
        }
    };

    void eraseTree (node<T> * r) {

        if ( r->left != nullptr )
            eraseTree( r->left );
        if ( r->right != nullptr )
            eraseTree( r->right );
        delete r;
    }

    void treeDeleteSequential () { // Si el árbol secuencial no se elimina de esta forma, se produce un desbordamiento de pila y el programa colapsa.

        node<T> * previous = root;             // p: nodo que se va a elminar
        node<T> * current  = previous->right;  // c: hijo derecho de p.

        while ( current != nullptr ) {

            delete previous;                    // Elimina   p en                        la iteración t.
            previous = current;                 // Actualiza p a c para                  la iteración t+1.
            current  = current->right;          // Actualiza c al hijo derecho de c para la iteración t+1.
        }

        root = nullptr; // Evita violación de segmento en destructor.
    };

public:

    void buildTreeSequential (const T& n) {
        buildSequentialTree( n );
    }

public:

    tree () : root (nullptr) {
    };
    // Constructor. Crea un arbol vacio

    tree (const tree<T>& obj) {

        copyTree( obj.root );
    };
    // Constructor copia

    ~tree () {
        if ( root )
            eraseTree( root );
    };
    // Destructor (borra el arbol)

    void inorderTreeWalk (node<T>* x, stack<T> & pila) {

        if ( x ) { // Si el subárbol actual no está vació.

            inorderTreeWalk( x->left, pila ); // Recorre en orden: subárbol izquierdo.
            pila.push( x->key ); // Apila el elemento apuntado por X.
            inorderTreeWalk( x->right, pila ); // Recorre en orden: subárbol derecho.
        }
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

        node<T>* y = nullptr;

        if ( x->right != nullptr ) // Si el subárbol derecho de X no está vacío
            return treeMinimum( x->right ); // El sucesor de X es el mínimo del subárbol derecho de X. 

        y = x->p; // Y, padre del nodo apuntado por X. 

        while ( y != nullptr && x == y->right ) { // Mientras Y no sea NULL y X sea hijo derecho de Y.

            x = y; // Suba X un nivel ----> Ahora X apunta a su padre.
            y = y->p; // Suba Y un nivel ----> Ahora Y apunta al abuelo de X / Padre de Y.

        } // Finaliza cuando encuentra el primer ancestro en dirección noreste. " Es decir X es hijo izquierdo de Y".

        return y;
    };
    // Devuelve el nodo cuya llave es la que le sigue a la
    // del nodo x. Si no existe tal nodo devuelve NULL. (NULL intento de acceso a llave ----> Violación de segmento.)

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

        node<T> * y = nullptr;

        if ( !z->left ) // Si Z no tiene subárbol izquierdo; Z puede o no tener subárbol derecho.
            //  Si, Z es hijo derecho de su padre, el padre de Z reemplaza su subárbol derecho por el subárbol derecho de Z.
            //  Si, Z es hijo izquierdo de su padre, el padre de Z reemplaza su subárbol izquierdo por el subárbol derecho de Z.
            //  Finalmente el padre del subárbol derecho de Z es reemplazado por el padre de Z.
            treeTransplant( z, z->right );

        else if ( !z->right ) // Si Z no tiene subárbol derecho y Z tiene subárbol izquierdo ( condicional anterior ).
            // Si, Z es hijo derecho de su padre, el padre de Z reemplaza su hijo derecho por el subárbol izquierdo de Z.
            // Si, Z es hijo izquierdo de su padre, el padre de Z reemplaza su hijo izquierdo por el subárbol izquierdo de Z.
            // Finalmente, el padre del subárbol izquierdo de Z es reemplazado por el padre de Z
            treeTransplant( z, z->left );

        else { // Z tiene subárbol derecho e izquierdo.

            // Como el subárbol derecho de Z no está vacío, su sucesor es el mínimo del subárbol derecho de Z.
            y = treeMinimum( z->right );

            if ( y->p != z ) { // Si el padre del sucesor de Z no es Z.

                // Asumimos que el subárbol izquierdo del sucesor de Z está vacío.
                // Si, el sucesor de Z es hijo izquierdo de su padre, el padre del sucesor de Z reemplaza su hijo izquierdo por el subárbol derecho del sucesor de Z.
                // Si, el sucesor de Z es hijo derecho de su padre, el padre del sucesor de Z reemplaza su hijo derecho por el subárbol derecho del sucesor de Z.
                // El padre del subárbol derecho del sucesor de Z es reemplazado, por el padre del sucesor de Z.
                treeTransplant( y, y->right );

                // El subárbol derecho del sucesor de Z, es reemplazado por el subárbol derecho de Z. ( Conexión padre-hijo ) ( En ejemplo Conexión Y ----> R )
                y->right = z->right;
                // El padre del subárbol derecho del sucesor de Z, es reemplazado por el sucesor de Z.( Conexión hijo-padre )
                y->right->p = y;
            }

            // Lo del condicional anterior aplica de forma similar a lo siguiente:

            // El padre del sucesor de Z es Z.

            // Caso raíz árbol: donde se cumpla que el padre del sucesor de la raíz(Z) es Z: 
            // La raíz del árbol es reemplazada por el sucesor de Z.
            // El padre del sucesor de Z es reemplazado por NULL.
            // El subárbol izquierdo del sucesor de Z es reemplazado por el subárbol izquierdo de Z. ( El sucesor de Z no tiene subárbol izquierdo ).

            // Otro casos:
            // El padre del sucesor de Z es Z y el sucesor de Z solo tiene subárbol derecho.

            treeTransplant( z, y );
            y->left = z->left;
            y->left->p = y;
        }

        return z;
    };
    // Saca del arbol la llave contenida en el nodo apuntado por z.
    // Devuelve la direccion del nodo eliminado para que se pueda 
    // disponer de ella.

    void deleteSequentialTree () {
        treeDeleteSequential ( );
    } // Elimina el árbol secuencial: Evita desbordamiento de pila.

    node<T> * getRoot () const {
        return this->root;
    };
    // Devuelve la raiz del arbol. (Para efectos de revisión de la tarea).

private:
    node<T> *root; // root of the Tree

} ;
#endif // BINARY_SEARCH_Tree