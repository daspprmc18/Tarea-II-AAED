#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <stack>
#include <time.h>

#include "bstree.h"
#include "hasht.h"
#include "llist.h"
#include "rbtree.h"

using std::cout;
typedef long int Integer;

// Funciones Auxiliares:

void printList(const llist<Integer> &list);
void printStack(stack<Integer> &stk);

// Funciones de pruebas:

void testRandomRedBlackTree(std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n);
void testSequientialRedBlackTree(std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n);
void testRandomHashT(std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n);

tree<Integer> * buildSequentialTree(const Integer& n);

int main(int argc, char** argv) {

    Integer n    = 1000000;
    Integer * np = &n;
    Integer min  = 0;
    Integer max  = (2 * n) - 1;

    std::random_device rd; // Produce semilla para el generador Mersenne Twister.
    std::mt19937 engine(rd()); // Generador de números aleatorios "Mersenne Twister 19937"
    std::uniform_int_distribution<Integer> distribution(min, max); // Rango distribución uniforme: [0,2n-1].

    // testRandomHashT(engine, distribution, *(np));

    //testRandomRedBlackTree(engine, distribution, n);
    testSequientialRedBlackTree(engine, distribution, n); // Si lo corro solo hace más búsquedas que cuando corrí previamente la búsqueda de aleatorios...

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

void testRandomRedBlackTree(std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer & n) {

    // Árbol Rojinegro: Elementos aleatorios.

    rbtree<Integer> randomRedBlackTree;

    rbnode<Integer> * redBlackNode = nullptr;

    for (Integer i = 0; i < n; ++i) {

        redBlackNode = new rbnode<Integer>(distribution(engine));
        randomRedBlackTree.treeInsert(redBlackNode);
    }

    std::cout << "----> Arból Rojinegro Aleatorio <----\n\n";
    Integer count = 0;
    std::chrono::seconds elapsed(0);
    std::chrono::system_clock::time_point finish;
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    while (elapsed.count() < 10) {

        randomRedBlackTree.iterativeTreeSearch(distribution(engine));
        ++count;
        finish = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
    }

    std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
    std::cout << "Número de búsquedas realizadas: Árbol Rojinegro Aleatorio: " << count << "\n\n";

}

void testSequientialRedBlackTree(std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer & n) {

    // Árbol Rojinegro : Elementos secuenciales.

    rbtree<Integer> redBlackTree;
    redBlackTree.buildSequentialTree(n);

    std::cout << "----> Arból Rojinegro Secuencial <----\n\n";
    Integer count = 0;

    std::chrono::seconds elapsed(0); // Tiempo transcurrido.
    std::chrono::system_clock::time_point finish; // Tiempo final.
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); // Tiempo inicial.

    while (elapsed.count() < 10) {

        redBlackTree.iterativeTreeSearch( distribution(engine));
        ++count;
        finish  = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
    }
    std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
    std::cout << "Número de búsquedas realizadas: Árbol Rojinegro Secuencial " << count << "\n\n";
}

void testRandomHashT(std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n) {

    // Tabla de dispersión elementos aleatorios.

    hasht<Integer> hashTable(n);

    for (Integer i = 0; i < n; ++i)
        hashTable.insert( distribution(engine) );

    cout << "Factor de carga: " << hashTable.loadFactor() << "\n\n";

    std::cout << "----> Tabla de Dispersión Aleatoria <----\n\n";
    Integer count = 0;

    std::chrono::seconds elapsed(0);
    std::chrono::system_clock::time_point finish;
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    while (elapsed.count() < 10) {

        hashTable.search(distribution(engine));
        ++count;
        finish  = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
    }

    std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
    std::cout << "Número de búsquedas realizadas: Tabla de dispersión: " << count << "\n\n";
}