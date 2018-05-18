#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <stack>
#include <time.h>

#include "bstree.h"
#include "llist.h"
#include "hasht.h"

typedef long int Integer;

void printList(const llist<Integer> &list);
void printStack(stack<Integer> &stk);
tree<Integer> * buildSequentialTree(const Integer& n);

int main(int argc, char** argv) {

    // int option = 1;
    Integer n = 1000000;
    Integer min = 0;
    Integer max = (2 * n) - 1;

    std::random_device rd; // Produce semilla para el generador Mersenne Twister.
    std::mt19937 engine(rd()); // Generador de números aleatorios "Mersenne Twister 19937"
    std::uniform_int_distribution<Integer> distribution(min, max); // Rango distribución uniforme: [0,2n-1].

    // Código de prueba para Lista enlazada.
    /*if (!option) {

        { // Lista Enlazada: Elementos aleatorios.

            llist<Integer> randomList;
            llnode<Integer> * randomNode = nullptr;

            for (Integer i = 0; i < n; ++i) {

                randomNode = new llnode<Integer>(distribution(engine), nullptr, nullptr);
                //std::cout << "Nodo: " << i << "----> K: " << randomNode->key << "\n\n";
                randomList.listInsert(randomNode);
                randomNode = nullptr;
            }

            std::cout << "----> Lista Enlazada Aleatoria <----\n\n";
            Integer count = 0;
            std::chrono::seconds elapsed(0); // Tiempo transcurrido.
            std::chrono::system_clock::time_point finish; // Tiempo final.
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); // Tiempo inicial.

            while (elapsed.count() < 10) {

                randomList.listSearch(distribution(engine));
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

            std::cout << "----> Lista Enlazada Secuencial <---- \n\n";
            Integer count = 0;
            std::chrono::seconds elapsed(0);
            std::chrono::system_clock::time_point finish;
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

            while (elapsed.count() < 10) {

                sequentialList.listSearch(distribution(engine));
                ++count;
                finish = std::chrono::system_clock::now();
                elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
            }

            std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
            std::cout << "Número de búsquedas realizadas: Lista secuencial: " << count << "\n\n";
        }
    } else { // Código de prueba para Árbol binario.

        { // Árbol Binario Búsqueda: Elementos aleatorios.

            tree<Integer> randomTree;
            node<Integer> * randomNode = nullptr;

            for (Integer i = 0; i < n; ++i) {
                randomNode = new node<Integer>(distribution(engine), nullptr, nullptr, nullptr);
                randomTree.treeInsert(randomNode);
                randomNode = nullptr;
            }

            std::cout << "----> Arból Binario Aleatorio <----\n\n";
            Integer count = 0;
            std::chrono::seconds elapsed(0);
            std::chrono::system_clock::time_point finish;
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

            while (elapsed.count() < 10) {

                randomTree.iterativeTreeSearch(distribution(engine));
                ++count;
                finish = std::chrono::system_clock::now();
                elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
            }

            std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
            std::cout << "Número de búsquedas realizadas: Árbol aleatorio: " << count << "\n\n";
        }

        { // Árbol Binario Búsqueda: Elementos secuenciales.

            tree<Integer> sequentialTree;
            sequentialTree.buildTreeSequential(n);

            std::cout << "----> Arból Binario Secuencial <----\n\n";
            Integer count = 0;
            std::chrono::seconds elapsed(0); // Tiempo transcurrido.
            std::chrono::system_clock::time_point finish; // Tiempo final.
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); // Tiempo inicial.

            while (elapsed.count() < 10) {

                sequentialTree.iterativeTreeSearch(distribution(engine));
                ++count;
                finish = std::chrono::system_clock::now();
                elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
            }

            std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
            std::cout << "Número de búsquedas realizadas: Árbol secuencial " << count << "\n\n";
        }
    }*/

    hasht<Integer> hashTable1(10);
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