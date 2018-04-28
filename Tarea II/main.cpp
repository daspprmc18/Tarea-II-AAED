#include <cstdlib>
#include <time.h>

#include "llist.h"
#include "bstree.h"

typedef long int Integer;
void printList(const llist<Integer> &list);

int main(int argc, char** argv) {

    srand(time(NULL));
    Integer n = 1000000;
    Integer mulFactor = 2 * n;

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



