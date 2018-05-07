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

    for (int j = 0; j < 10; ++j)
        std::cout << rand() % mulFactor << "\n\n";

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

            printList(randomList);
            return 0;

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

        tree<Integer> randomTree;
        node<Integer> * randomNode = nullptr;

        for (Integer i = 0; i < n; ++i) {
            randomNode = new node<Integer>((rand() % mulFactor), nullptr, nullptr, nullptr);
            randomTree.treeInsert(randomNode);
            randomNode = nullptr;
        }

        /*tree<Integer> sequentialTree;
        node<Integer> * sequentialNode = nullptr;

        for (Integer i = 0; i < n; ++i) {
            sequentialNode = new node<Integer>(i, nullptr, nullptr, nullptr);
            sequentialTree.treeInsert(sequentialNode);
            sequentialNode = nullptr;
        }*/
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