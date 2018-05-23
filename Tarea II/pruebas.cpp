
#include "pruebas.h"

// -------------------------------------------------------------> Funciones Auxiliares <-------------------------------------------------------------

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



// -------------------------------------------------------------> Lista Enlazada <-------------------------------------------------------------

void testRandomList (std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n) {

    llist<Integer>    list;
    llnode<Integer> * node = nullptr;

    for (Integer i = 0; i < n; ++i) {

        node = new llnode<Integer>( distribution(engine), nullptr, nullptr );
        list.listInsert(node);
    }

    std::cout << "----> Lista Enlazada Aleatoria <----\n\n";
    Integer count = 0;

    std::chrono::seconds elapsed(0); // Tiempo transcurrido.
    std::chrono::system_clock::time_point finish; // Tiempo final.
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); // Tiempo inicial.

    while (elapsed.count() < 10) {

        list.listSearch( distribution(engine) );
        ++count;
        finish  = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
    }

    std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
    std::cout << "Número de búsquedas realizadas: Lista aleatoria: " << count << "\n\n";
}

void testSequentialList (std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n) {

    llist<Integer> list;
    llnode<Integer> * node = nullptr;

    for (Integer i = 0; i < n; ++i) {

        node = new llnode<Integer>(i, nullptr, nullptr);
        list.listInsert(node);
    }

    std::cout << "----> Lista Enlazada Secuencial <---- \n\n";
    Integer count = 0;

    std::chrono::seconds elapsed(0);
    std::chrono::system_clock::time_point finish;
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    while (elapsed.count() < 10) {

        list.listSearch(distribution(engine));
        ++count;
        finish  = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
    }

    std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
    std::cout << "Número de búsquedas realizadas: Lista secuencial: " << count << "\n\n";

}

// -------------------------------------------------------------> Árbol Binario de Búsqueda <-------------------------------------------------------------

void testRandomBinarySearchTree (std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n) {

    // Árbol Binario Búsqueda: Elementos aleatorios.

    tree<Integer> randomTree;
    node<Integer> * randomNode = nullptr;

    for (Integer i = 0; i < n; ++i) {

        randomNode = new node<Integer>(distribution(engine), nullptr, nullptr, nullptr);
        randomTree.treeInsert(randomNode);
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

void testSequientialBinaySearchTree (std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n) {

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

    sequentialTree.deleteSequentialTree();
}

// -------------------------------------------------------------> Árbol Rojinegro <-------------------------------------------------------------

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

    rbtree<Integer> tree;
    tree.buildSequentialTree(n);

    std::cout << "----> Arból Rojinegro Secuencial <----\n\n";
    Integer count = 0;

    std::chrono::seconds elapsed(0); // Tiempo transcurrido.
    std::chrono::system_clock::time_point finish; // Tiempo final.
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); // Tiempo inicial.

    while (elapsed.count() < 10) {

        tree.iterativeTreeSearch( distribution(engine));
        ++count;
        finish  = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
    }
    std::cout << "Tiempo transcurrido: " << elapsed.count() << " segundos\n\n";
    std::cout << "Número de búsquedas realizadas: Árbol Rojinegro Secuencial " << count << "\n\n";

    tree.deleteSequentialTree(); // Elude desbordamiento de pila.

}

// -------------------------------------------------------------> Tabla de dispersión <-------------------------------------------------------------

void testRandomHashT(std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n) {

    // Tabla de dispersión elementos aleatorios.

    hasht<Integer> hashTable(n);

    for (Integer i = 0; i < n; ++i)
        hashTable.insert( distribution(engine) );

    //cout << "Factor de carga: " << hashTable.loadFactor() << "\n\n";

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
    std::cout << "Número de búsquedas realizadas: Tabla de dispersión Aleatoria: " << count << "\n\n";
}

void testSequentialHashT(std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n) {

    // Tabla de dispersión elementos aleatorios.

    hasht<Integer> hashTable(n);

    for (Integer i = 0; i < n; ++i)
        hashTable.insert( i);

    std::cout << "----> Tabla de Dispersión Secuencial <----\n\n";
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
    std::cout << "Número de búsquedas realizadas: Tabla de dispersión Secuencial: " << count << "\n\n";
}