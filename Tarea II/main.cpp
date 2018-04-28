#include <cstdlib>
#include <time.h>

#include "llist.h"
#include "bstree.h"

typedef long int Integer;
void printList(const llist<Integer> &list);

int main(int argc, char** argv) {

    srand(time(NULL));
    Integer n = 20;
    Integer mulFactor = 2 * n;
    llist<Integer> list;
    llnode<Integer> * node = nullptr;

    for (Integer i = 0; i < n; ++i) {

        node = new llnode<Integer>((rand() % mulFactor), nullptr, nullptr);
        list.listInsert(node);
        node = nullptr;
    }

    printList(list);

    llist<Integer> list2(list);

    std::cout << "Constructor copia\n\n";
    printList(list2);

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



