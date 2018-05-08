#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <stack>
#include <time.h>

#include "bstree.h"
#include "llist.h"

typedef long int Integer;
typedef std::mt19937 RandomNumberGenerator;

void printList(const llist<Integer> &list);
void printStack(stack<Integer> &stk);

int main(int argc, char** argv) {

    int option = 1;
    Integer n = 100;
    Integer mulFactor = (2 * n) - 1;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // Reloj del sistema.
    RandomNumberGenerator generator(seed); // Generador 
    std::uniform_int_distribution<uint32_t> distribution(0, mulFactor); // Rango [0 2n[.

    // Código de prueba para Lista enlazada.
    if (!option) {

        /*
         *  Inserte en una lista vacía n = 1 000 000 de nodos cuyas llaves sean enteros seleccio-
         *  nados aleatoriamente en el rango [0, 2n[. Seleccione elementos al azar en el mismo
         *  rango [0, 2n[ y búsquelos en la lista (estén o no en ella) registrando el número de
         *  búsquedas realizadas en un lapso de diez segundos.
         */
        {
            llist<Integer> randomList;
            llnode<Integer> * randomNode = nullptr;

            for (Integer i = 0; i < n; ++i) {

                randomNode = new llnode<Integer>(distribution(generator), nullptr, nullptr);
                randomList.listInsert(randomNode);
                randomNode = nullptr;
            }

            return 0;

            for (int i = 0; i < 10; ++i) {

                randomList.listSearch(distribution(generator));
            }
        }

        /*
         *  Inserte en una lista vacía las llaves 0, 1, ..., n − 1, en ese orden. Seleccione elementos
         *  al azar en el rango [0, 2n[, y registre el número de búsquedas que se logró hacer en
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

                sequentialList.listSearch(distribution(generator));
            }
        }

        /*
         *  Indique si en alguno de los dos casos (inserción de números aleatorios o inserción
         *  de números secuenciales) se realizó una cantidad de búsquedas (exitosas o fallidas,
         *  no importa) sustancialmente mayor que en el otro (más del doble), e indique si
         *  esto corresponde a lo esperado.
         */
    } else { // Código de prueba para Árbol binario.

        { // Árbol Binario Búsqueda: Elementos aleatorios.
            tree<Integer> randomTree;
            node<Integer> * randomNode = nullptr;

            for (Integer i = 0; i < n; ++i) {
                randomNode = new node<Integer>(distribution(generator), nullptr, nullptr, nullptr);
                randomTree.treeInsert(randomNode);
                randomNode = nullptr;
            }

            Integer count = 0;
            std::chrono::seconds elapsed(0);
            std::chrono::system_clock::time_point finish;
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

            while (elapsed.count() < 10) {

                randomTree.treeSearch(distribution(generator));
                ++count;
                finish = std::chrono::system_clock::now();
                elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
            }

            std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
            std::cout << "Número de búsquedas realizadas: " << count << "\n\n";
        }

        { // Árbol Binario Búsqueda: Elementos secuenciales.
            tree<Integer> sequentialTree;
            node<Integer> * sequentialNode = nullptr;

            for (Integer i = 0; i < n; ++i) {

                sequentialNode = new node<Integer>(i, nullptr, nullptr, nullptr);
                sequentialTree.treeInsert(sequentialNode);
                sequentialNode = nullptr;
            }
        }
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