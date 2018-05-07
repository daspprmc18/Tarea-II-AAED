#include <cstdlib>
#include <iomanip>
#include <stack>
#include <time.h>

#include "bstree.h"
#include "llist.h"

typedef long int Integer;
void printList(const llist<Integer> &list);
void printStack(stack<Integer> &stk);

int main(int argc, char** argv) {

    int option = 1;

    srand(time(NULL));
    Integer n = 1000000;
    Integer mulFactor = 2 * n;

    // Código de prueba para Lista enlazada.
    if (!option) {

        /*
         *  Inserte en una lista vacía n = 1 000 000 de nodos cuyas llaves sean enteros seleccio-
         *  nados aleatoriamente en el rango [0, 2n). Seleccione elementos al azar en el mismo
         *  rango [0, 2n) y búsquelos en la lista (estén o no en ella) registrando el número de
         *  búsquedas realizadas en un lapso de diez segundos.
         */
        {
            llist<Integer> randomList;
            llnode<Integer> * randomNode = nullptr;

            for (Integer i = 0; i < n; ++i) {

                randomNode = new llnode<Integer>((rand() % mulFactor), nullptr, nullptr);
                randomList.listInsert(randomNode);
                randomNode = nullptr;
            }

            for (int i = 0; i < 10; ++i) {

                randomList.listSearch((rand() % mulFactor));
            }
        }

        /*
         *  Inserte en una lista vacía las llaves 0, 1, ..., n − 1, en ese orden. Seleccione elementos
         *  al azar en el rango [0, 2n), y registre el número de búsquedas que se logró hacer en
         *  un lapso de 10 segundos. 
         */
        {
            llist<Integer> sequentialList;
            llnode<Integer> * sequentialNode = nullptr;

            for (Integer i = 0; i < n; ++i) {

                sequentialNode = new llnode<Integer>(i, nullptr, nullptr);
                sequentialList.listInsert(sequentialNode);
                sequentialNode = nullptr;
            }

            for (int i = 0; i < 10; ++i) {

                sequentialList.listSearch((rand() % mulFactor));
            }
        }

        /*
         *  Indique si en alguno de los dos casos (inserción de números aleatorios o inserción
         *  de números secuenciales) se realizó una cantidad de búsquedas (exitosas o fallidas,
         *  no importa) sustancialmente mayor que en el otro (más del doble), e indique si
         *  esto corresponde a lo esperado.
         */
    } else { // Código de prueba para Árbol binario.

        tree<Integer> t1;

        node<Integer> * node1 = new node<Integer>(15, nullptr, nullptr, nullptr);
        node<Integer> * node2 = new node<Integer>(6, nullptr, nullptr, nullptr);
        node<Integer> * node3 = new node<Integer>(18, nullptr, nullptr, nullptr);
        node<Integer> * node4 = new node<Integer>(3, nullptr, nullptr, nullptr);
        node<Integer> * node5 = new node<Integer>(2, nullptr, nullptr, nullptr);
        node<Integer> * node6 = new node<Integer>(4, nullptr, nullptr, nullptr);
        node<Integer> * node7 = new node<Integer>(7, nullptr, nullptr, nullptr);
        node<Integer> * node8 = new node<Integer>(13, nullptr, nullptr, nullptr);
        node<Integer> * node9 = new node<Integer>(9, nullptr, nullptr, nullptr);
        node<Integer> * node10 = new node<Integer>(20, nullptr, nullptr, nullptr);
        node<Integer> * node11 = new node<Integer>(17, nullptr, nullptr, nullptr);

        t1.treeInsert(node1);
        t1.treeInsert(node2);
        t1.treeInsert(node3);
        t1.treeInsert(node4);
        t1.treeInsert(node5);
        t1.treeInsert(node6);
        t1.treeInsert(node7);
        t1.treeInsert(node8);
        t1.treeInsert(node9);
        t1.treeInsert(node10);
        t1.treeInsert(node11);
    }

    return 0;
}

void printList(const llist<Integer> &list) {

    llnode<Integer> * p = nullptr;
    p = list.getNil()->next;
    int cantNodos = 0;

    while (p != list.getNil()) {
        std::cout << "Nodo " << ++cantNodos << ": " << p->key << std::endl << std::endl;
        p = p->next;
    }
    std::cout << std::endl << std::endl;
    p = nullptr;
}

void printStack(stack<Integer> &stk) {

    std::cout << "Pila: Recorrido en Orden \n\n";
    while (!stk.empty()) {

        std::cout << "|" << std::setw(8) << stk.top() << " |\n";
        stk.pop();
    }
    std::cout << " _ _ _ _ _  \n\n";
}