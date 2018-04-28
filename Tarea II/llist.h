#ifndef LINKED_LIST_llist
#define LINKED_LIST_llist
#include <iostream>

// Nodos de la lista:

template <typename T>
class llnode {
public:
    // Esta clase es para ser usada por otras clases.
    // Por eficiencia los atributos se dejan publicos.
    T key;
    llnode<T> *prev, *next;
    //enum colors color;

    // Constructor por omision.

    llnode () {
    };

    // Inicializacion de los datos miembro.

    llnode (const T& k, llnode<T> *w = NULL, llnode<T> *y = NULL) : key (k), prev (w), next (y) {
    };

    ~llnode () {
        std::cout << "Nodo " << key << " eliminado" << std::endl << std::endl;
    }
};

// Lista enlazada con nodo centinela:

template <typename T>
class llist {
public:

    llist () : nil (new llnode<T>( )) { // Lista vacía, nodo siguiente y anterior de NIL apuntan a NIL.
        nil->prev = nil;
        nil->next = nil;
    };
    // Constructor (crea una lista vacia)

    llist (const llist<T> &obj) : nil (new llnode<T>( )) {

        nil->prev = nil;
        nil->next = nil;

        //Copia los elementos de la lista original secuencialmente, empezando por el último elemento hasta llegar a NIL, utiliza el método insertar.

        llnode<T> * p = obj.nil->prev; // Puntero "p" utilizado para recorrer obj.
        llnode<T> * temp = nullptr; // Puntero "temp" utilizado para alojar temporalmente un nuevo nodo.

        while ( p != obj.nil ) {

            temp = new llnode<T>( p->key, nullptr, nullptr );
            listInsert( temp ); // Inserta el nuevo nodo a *this.
            p = p->prev; // Retrocede al siguiente elemento de obj.
            temp = nullptr;
        }

    };
    // Constructor copia

    ~llist () { // Elimina los elementos de *this empezando por el último elemento hasta llegar al nodo centinela.

        llnode<T> * p = nullptr;
        p = nil->prev->prev; // Ubica el puntero p en el penúltimo nodo de *this.

        while ( p != nil ) { // Repite lo siguiente hasta que p apunte al nodo centinela.

            delete p->next; // Elimina el nodo siguiente de p.
            p = p->prev; // Actualiza p al nodo anterior.
        }

        delete p->next; // Elimina el nodo siguiente al centinela.
        delete p; // Elimina el nodo centinela.

    };
    // Destructor (borra la lista)

    llnode<T>* listSearch (const T& k) {
    };
    // Busca la llave iterativamente. Si la encuentra, devuelve un 
    // apuntador al nodo que la contiene; sino devuelve NULL.

    void listInsert (llnode<T>* x) {

        x->next = nil->next; // 
        nil->next->prev = x;
        nil->next = x;
        x->prev = nil;
    };
    // Inserta el nodo x en la lista.

    llnode<T>* listDelete (llnode<T>* x) {
    };
    // Saca de la lista la llave contenida en el nodo apuntado por x.
    // Devuelve la direccion del nodo eliminado para que se pueda 
    // disponer de el.

    llnode<T> * getNil () const {
        return this->nil;
    };
    // Devuelve el nodo centinela. (Para efectos de revision de la tarea).

private:

    llnode<T> *nil; // nodo centinela

};
#endif // LINKED_LIST_llist