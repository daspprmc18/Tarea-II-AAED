#ifndef RED_BLACK_rbtree
#define RED_BLACK_rbtree

#include <stdio.h>
#include <stack>
#include <stdlib.h>

#include "bstree.h"

using std::stack;

enum colors {
    RED,  // 0
    BLACK // 1
} ;

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

        delete left;
        delete right;
    }
} ;

// Arbol:

template <typename T>
class rbtree {
private:

    rbnode<T> *root; // raiz del arbol
    rbnode<T> *nil; // nodo nil (hoja) del arbol

private:

    // Caso #2.1
    // Color: NEGRO: Abuelo, Tio
    //         ROJO: Padre , Yo                    
    //                                                   _ _ _ _ _ _ _ _ _ _ _ _ _ _
    //                                               
    //                     ( Abuelo ) <---- A           |                (A)        |
    //                    /          \                  |               /   \       |
    //     X ----> (Padre)            (Tio) <---- T     | Zig-Zag:   (X)            |
    //            /       \                             |           /   \           |
    //                     (Yo) <---- Y                 |                (Y)        |    
    //                                                   _ _ _ _ _ _ _ _ _ _ _ _ _ _

    void leftRotate (rbnode<T> * x) {  // Rotación izquierda porque X se va a convertir en hijo izquierdo de Y.

        rbnode<T> * y = x->right;      // Nodo en violación ( Y ).
        x->right      = y->left;       // Convirte el subárbol izquierdo del nodo Y en el subárbol derecho del nodo X.

        if ( y->left != nil )
            y->left.p = x;             // Enlaza el padre del hijo izquierdo de Y con X.

        y->p = x.p;                    // Enlaza el padre de X con Y.

        if ( x.p == nil )
            root = y;
        else if ( x == x->p->left )
            x->p->left  = y;
        else
            x->p->right = y;

        y->left = x;                  // Posiciona a X como hijo izquierdo de Y.
        x.p     = y;

    } // AL finalizar se produjo un cambio de paternidad entre X y Y.


    // Caso #2.2
    // Color: NEGRO: Abuelo, Tio
    //         ROJO: Padre , Yo
    //                                                       _ _ _ _ _ _ _ _ _ _ _ _ _ _    
    //    
    //                     ( Abuelo ) <---- A               |            (A)            |
    //                    /          \                      |           /   \           |
    //       T ----> (Tio)            (Padre) <---- X       | Zig-Zag:       (X)        |
    //                               /       \              |               /   \       |
    //                   Y ----> (Yo)                       |             (Y)           |
    //                                                       _ _ _ _ _ _ _ _ _ _ _ _ _ _

    void rightRotate (rbnode<T> * x) {  // Rotación derecha porque X se va a convertir en hijo derecho de Y.

        rbnode<T> * y = x->left;        // Nodo en violación ( Y ).
        x->left       = y->right;       // Convierte el subárbol izquierdo del nodo X, en el subárbol derecho del nodo Y.

        if ( y->right != nil )
            y->right->p = x;            // Enlaza el padre del hijo derecho de Y con X.

        y->p = x->p;                    // Enlaza el padre de X con Y.

        if ( x.p == nil )
            root = y;
        else if ( x == x->p->right )
            x->p->right = y;
        else
            x->p->left  = y;

        y->right = x;                  // Posiciona a X como hijo derecho de Y.
        x.p      = y;

    } // AL finalizar se produjo un cambio de paternidad entre X y Y.

    void insertFixup (rbnode<T> * z) {

        rbnode<T> * y = nullptr;
        while ( z->p->color == RED ) { // El padre de Z es rojo.

            if ( z->p == z->p->p->left ) { // El padre de Z es hijo izquierdo del abuelo de Z.

                y = z->p->p->right; // Tío de Z.

                if ( y->color == RED ) { // Tío de Z es rojo.
                    // Itercambio de color generacional.
                    z->p->color    = BLACK;       // Caso #1
                    y->color       = BLACK;       // Caso #1
                    z->p->p->color = RED;         // Caso #1
                    z              = z->p->p;     // Caso #1

                } else if ( z == z->p->right ) { // Z es hijo derecho de su padre. (Tío negro)
                    // Intercambio paternidad entre Z y su padre.
                    z = z->p;                     // Caso #2
                    leftRotate( z );              // Caso #2

                    // Intercambio de paternidad y de color generacional entre el padre de Z y su abuelo.
                    z->p->color    = BLACK;       // Caso #3
                    z->p->p->color = RED;         // Caso #3
                    rightRotate( z->p->p );       // Caso #3

                }

            } else { // El padre de Z es hijo derecho del abuelo de Z.

                y = z->p->p->left; // Tío de Z.

                if ( y->color == RED ) { // Tío de Z es rojo.
                    // Itercambio de color generacional.
                    z->p->color    = BLACK;       // Caso #1
                    y->color       = BLACK;       // Caso #1
                    z->p->p->color = RED;         // Caso #1
                    z              = z->p->p;     // Caso #1

                } else if ( z == z->p->left ) { // Z es hijo izquierdo de su padre. (Tío negro)
                    // Intercambio paternidad entre Z y su padre.
                    z = z->p;                     // Caso #2
                    rightRotate( z );             // Caso #2

                    // Intercambio de paternidad y de color generacional entre el padre de Z y su abuelo.
                    z->p->color    = BLACK;       // Caso #3
                    z->p->p->color = RED;         // Caso #3
                    leftRotate( z->p->p );        // Caso #3
                }
            }
        }
        root->color = BLACK;
    }

    node<T>* treeSearch (node<T>* c, const T& k) {

        if ( c == nil || c->key == k )        // C es NIL o el elemento en el nodo apuntado por C es el que se busca.
            return c;

        if ( k < c->key )                     // K es menor que el elemento en el nodo apuntado por C.
            return treeSearch( c->left, k );  // Buscar K en subárbol izquierdo.
        else
            return treeSearch( c->right, k ); // Buscar K en el subárbol derecho.
    };

    node<T>* treeMinimum (node<T>* x) const {

        node<T>* current = x;

        while ( current->left != nil )        // Mientras el nodo apuntado por C tenga hijo izquierdo  ( Nodo interno ).
            current = current->left;          // Avanza C al hijo izquierdo de C.

        return current;
    };

    void copyTree (node<T>* root) {

        if ( root != nil ) {         // C es distinto de NIL.

            node<T> * temp = new node<T>( root->key, nullptr, nullptr, nullptr, RED );
            treeInsert( temp );
            copyTree( root->left );  // Copia subárbol izquierdo de C.
            copyTree( root->right ); // Copia subárbol derecho de C.
        }
    };

public:

    rbtree () {
    };
    // Constructor (crea un arbol vacio)

    rbtree (const rbtree<T>& obj) {
        copyTree( obj.root );
    };
    // Constructor copia

    ~rbtree () {
        delete root;
    };
    // Destructor (borra el arbol)

    void inorderTreeWalk (rbnode<T>* x, stack<T> & pila) const {

        if ( x != nil ) { // Si el subárbol actual no está vació.

            inorderTreeWalk( x->left, pila ); // Recorre en orden: subárbol izquierdo.
            pila.push( x->key ); // Apila el elemento apuntado por X.
            ( x->color == RED ) ? pila.push( RED ) : pila.push( BLACK );
            inorderTreeWalk( x->right, pila ); // Recorre en orden: subárbol derecho.
        }
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

    rbnode<T>* treeSearch (const T& k) const {
        return treeSearch( root, k );
    };
    // Busca la llave recursivamente, si la encuentra devuelve un 
    // puntero al nodo que la contiene, sino devuelve NULL.

    rbnode<T>* iterativeTreeSearch (const T& k) const {

        node<T> * current = root;

        while ( current != nil && current->key != k ) {   // Mientras C sea distinto de NIL ( Nodo interno ) y el elemento en el nodo apuntado por C no es K.

            if ( k < current->key )                       // K es menor que el elemento en el nodo apuntado por C
                current = current->left;                  // Buscar K en subárbol izquierdo.
            else
                current = current->right;                 // Buscar K en el subárbol derecho.
        }
        return current;
    };
    // Igual que en el anterior pero usa un procedimiento iterativo.

    rbnode<T>* treeMinimum () const {

        node<T>* current = root;

        while ( current->left != nil )  // Mientras el nodo apuntado por C tenga hijo izquierdo ( Nodo interno ).
            current = current->left;    // Avanza C al hijo izquierdo de C.

        return current;
    };
    // Devuelve el nodo con la llave menor.
    // Si el arbol esta vacio devuelve NULL.

    rbnode<T>* treeMaximum () const {

        node<T> * current = root;

        while ( current->right != nil )  // Mientras el nodo apuntado por C tenga hijo derecho ( Nodo interno ).
            current = current->right;    // Avanza C al hijo derecho de C.

        return current;
    };
    // Devuelve el nodo con la llave mayor.
    // Si el arbol esta vacio devuelve NULL.

    rbnode<T>* treeSuccessor (const rbnode<T>* x) const {

        node<T>* y = nil;

        if ( x->right != nil ) // Subárbol derecho de X no está vacío
            return treeMinimum( x->right ); // El sucesor de X es el mínimo del subárbol derecho de X. 

        y = x->p; // Y, padre del nodo apuntado por X. 

        while ( y != nil && x == y->right ) { // Mientras Y no sea NIL y X sea hijo derecho de Y.

            x = y; // Suba X un nivel ----> Ahora X apunta a su padre.
            y = y->p; // Suba Y un nivel ----> Ahora Y apunta al abuelo de X / Padre de Y.

        } // Finaliza cuando encuentra el primer ancestro en dirección noreste. " Es decir X es hijo izquierdo de Y".

        return y;
    };
    // Devuelve el nodo cuya llave es la siguiente mas grande que 
    // la del nodo x. Si no existe tal nodo devuelve NULL.

    void treeInsert (rbnode<T>* z) {

        rbnode<T> * trailing = nil;
        rbnode<T> * current = root;

        while ( current != nil ) {

            trailing = current;      // T referencia al padre de C.

            if ( z->key < current->key )
                current = current->left;
            else
                current = current->right;
        } // Finaliza cuando encuentra la posición adecuada para insertar el nodo Z.

        z->p  = trailing;           // El padre de Z es el nodo al cual apunta T actualmente.

        if ( trailing == nil )      // Árbol vacío.
            root      = z;
        else if ( z->key < trailing->key )
            trailing->left   = z;   // Z es hijo izquierdo de T.
        else
            trailing->right  = z;   // Z es hijo derecho de T.

        z->left  = nil;
        z->right = nil;
        z->color = RED;
        insertFixup( z );
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

} ;

#endif // RED_BLACK_rbtree