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

    llist () : nil (new llnode<T>( )) { // El nodo siguiente y al anterior apuntan al nodo centinela.
        nil->prev = nil;
        nil->next = nil;
    };
    // Constructor (crea una lista vacia)

    llist (const llist<T> &obj) : nil (new llnode<T>( )) {

        nil->prev = nil;
        nil->next = nil;

        /*// 1) Copia los elementos de la lista original secuencialmente, empezando por el primero hasta llegar a NIL.

        llnode<T> * p = obj.nil->next; // Puntero "p" utilizado para recorrer obj.

        llnode<T> * q = this->nil; // Puntero "q" utilizado para recorrer *this.

        llnode<T> * temp = nullptr; // Puntero "temp" utilizado para alojar temporalmente un nuevo nodo.

        while ( p != obj.nil ) { // Mientras no se haya recorrido completamente a obj.

            temp = new llnode<T>( p->key, nullptr, nullptr );
            temp->prev = q; // Conecta el nuevo nodo con el último actual de *this. Q <---- TEMP
            q->next = temp; // Conecta el último actual de *this con el nuevo nodo. Q ----> TEMP
            temp->next = nil; // Conecta el nodo siguiente de TEMP con NIL. TEMP ----> NIL
            nil->prev = temp; // Conecta el nodo anterior de NIL con el nuevo nodo. NIL ----> TEMP
            p = p->next; // Avanza al siguiente elemento de obj.          
            q = q->next; // Avanza al siguiente elemento de *this.
        }
        temp = nullptr; // No se hace delete pues, eliminaría el nodo apuntado por TEMP, que es el último elemento de *this.*/


        // 2) Copia los elementos de la lista original secuencialmente, empezando por el primero hasta llegar a NIL, pero utiliza un puntero menos.
        // Inserción al FINAL.

        llnode<T> * p = obj.nil->next; // Puntero "p" utilizado para recorrer obj.
        llnode<T> * temp = nullptr; // Puntero "temp" utilizado para alojar temporalmente un nuevo nodo.

        while ( p != obj.nil ) {

            temp = new llnode<T>( p->key, nullptr, nullptr );
            temp->prev = nil->prev; // Conecta el nuevo nodo con el último actual de *this.  ÚLTIMO ELEMENTO <---- TEMP
            nil->prev->next = temp; // Conecta el último actual de *this con el nuevo nodo. ÚLTIMO ELEMENTO ----> TEMP
            temp->next = nil; // Conecta el nuevo nodo, con NIL. TEMP ----> NIL
            nil->prev = temp; // Conecta el nodo anterior de NIL con el nuevo nodo. NIL ----> TEMP
            p = p->next; // Avanza al siguiente elemento de obj.
            temp = nullptr;
        }
        temp = nullptr;



        // 3) Copia los elementos de la lista original secuencialmente, empezando por el último elemento hasta llegar a NIL, utiliza el método insertar.     
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

        x->next = nil->next;
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