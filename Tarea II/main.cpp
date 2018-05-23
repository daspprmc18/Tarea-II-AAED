#include <chrono>
#include <cstdlib>
#include <random>
#include <stack>

#include "pruebas.h"

int main(int argc, char** argv) {

    Integer n    = 1000000;
    Integer min  = 0;
    Integer max  = (2 * n) - 1;

    std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count()); // Generador de números aleatorios "Mersenne Twister 19937"
    std::uniform_int_distribution<Integer> distribution(min, max); // Rango distribución uniforme: [0,2n-1].

    /*testRandomList(engine, distribution, n);
    testSequentialList(engine, distribution, n);

    testSequientialBinaySearchTree(engine, distribution, n);
    testRandomBinarySearchTree(engine, distribution, n);

    // Recordar ejecutar secuencial solo, para obtener resultaos reales...
    testSequientialRedBlackTree(engine, distribution, n); // Si lo corro solo hace más búsquedas que cuando corrí previamente la búsqueda de aleatorios...
    testRandomRedBlackTree(engine, distribution, n);

    testRandomHashT(engine, distribution, n);
    testSequentialHashT(engine, distribution, n);*/

    rbtree<Integer> rbTree;

    rbnode<Integer> * node1 = new rbnode<Integer>(7);
    rbnode<Integer> * node2 = new rbnode<Integer>(3);
    rbnode<Integer> * node3 = new rbnode<Integer>(18);
    rbnode<Integer> * node4 = new rbnode<Integer>(10);
    rbnode<Integer> * node5 = new rbnode<Integer>(22);
    rbnode<Integer> * node6 = new rbnode<Integer>(26);
    rbnode<Integer> * node7 = new rbnode<Integer>(8);
    rbnode<Integer> * node8 = new rbnode<Integer>(11);

    rbnode<Integer> * node9 = new rbnode<Integer>(15);

    rbTree.treeInsert(node1);
    rbTree.treeInsert(node2);
    rbTree.treeInsert(node3);
    rbTree.treeInsert(node4);
    rbTree.treeInsert(node5);
    rbTree.treeInsert(node6);
    rbTree.treeInsert(node7);
    rbTree.treeInsert(node8);
    rbTree.treeInsert(node9);

    std::stack<Integer> stck;
    rbTree.inorderTreeWalk(rbTree.getRoot(), stck);
    printStack(stck);

    rbtree<Integer> rbTreeCopy(rbTree);

    std::cout << "Prueba constructor de copia: \n\n";
    std::stack<Integer> stckCopy;
    rbTreeCopy.inorderTreeWalk(rbTreeCopy.getRoot(), stckCopy);
    printStack(stckCopy);

    return 0;
}