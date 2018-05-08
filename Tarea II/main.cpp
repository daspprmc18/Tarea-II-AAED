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
tree<Integer> * buildSequentialTree(const Integer& n);

int main(int argc, char** argv) {

    int option = 1;
    Integer n = 1000000;
    Integer mulFactor = (2 * n) - 1;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // Reloj del sistema.
    RandomNumberGenerator generator(seed); // Generador 
    std::uniform_int_distribution<uint32_t> distribution(0, mulFactor); // Rango [0 2n[.

    // Código de prueba para Lista enlazada.
    if (!option) {

        { // Lista Enlazada: Elementos aleatorios.

            llist<Integer> randomList;
            llnode<Integer> * randomNode = nullptr;

            for (Integer i = 0; i < n; ++i) {

                randomNode = new llnode<Integer>(distribution(generator), nullptr, nullptr);
                randomList.listInsert(randomNode);
                randomNode = nullptr;
            }

            std::cout << "----> Lista Enlazada Aleatoria <----:\n\n";
            Integer count = 0;
            std::chrono::seconds elapsed(0);
            std::chrono::system_clock::time_point finish;
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

            while (elapsed.count() < 10) {

                randomList.listSearch(distribution(generator));
                ++count;
                finish = std::chrono::system_clock::now();
                elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
            }

            std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
            std::cout << "Número de búsquedas realizadas: Lista aleatoria: " << count << "\n\n";
        }

        { // Lista Enlazada: Elementos secuenciales.

            llist<Integer> sequentialList;
            llnode<Integer> * sequentialNode = nullptr;

            for (Integer i = 0; i < n; ++i) {

                sequentialNode = new llnode<Integer>(i, nullptr, nullptr);
                sequentialList.listInsert(sequentialNode);
                sequentialNode = nullptr;
            }

            std::cout << "----> Lista Enlazada Secuencial <---- :\n\n";
            Integer count = 0;
            std::chrono::seconds elapsed(0);
            std::chrono::system_clock::time_point finish;
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

            while (elapsed.count() < 10) {

                sequentialList.listSearch(distribution(generator));
                ++count;
                finish = std::chrono::system_clock::now();
                elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
            }

            std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
            std::cout << "Número de búsquedas realizadas: Lista secuencial: " << count << "\n\n";
        }
    } else { // Código de prueba para Árbol binario.

        /*{ // Árbol Binario Búsqueda: Elementos aleatorios.

            tree<Integer> randomTree;
            node<Integer> * randomNode = nullptr;

            for (Integer i = 0; i < n; ++i) {
                randomNode = new node<Integer>(distribution(generator), nullptr, nullptr, nullptr);
                randomTree.treeInsert(randomNode);
                randomNode = nullptr;
            }

            std::cout << "----> Arból Binario Aleatorio <----\n\n";
            Integer count = 0;
            std::chrono::seconds elapsed(0);
            std::chrono::system_clock::time_point finish;
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

            while (elapsed.count() < 10) {

                randomTree.iterativeTreeSearch(distribution(generator));
                ++count;
                finish = std::chrono::system_clock::now();
                elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
            }

            std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
            std::cout << "Número de búsquedas realizadas: Árbol aleatorio: " << count << "\n\n";
        }*/

        { // Árbol Binario Búsqueda: Elementos secuenciales.

            tree<Integer> sequentialTree;
            sequentialTree.buildTreeSequential(n);

            /*std::cout << "----> Arból Binario Secuencial <----\n\n";
            Integer count = 0;
            std::chrono::seconds elapsed(0); // Tiempo transcurrido.
            std::chrono::system_clock::time_point finish; // Tiempo final.
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); // Tiempo inicial.

            while (elapsed.count() < 10) {

                sequentialTree.iterativeTreeSearch(distribution(generator));
                ++count;
                finish = std::chrono::system_clock::now();
                elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
            }

            std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
            std::cout << "Número de búsquedas realizadas: Árbol secuencial " << count << "\n\n";*/
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