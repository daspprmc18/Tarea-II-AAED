#include <cstdlib>
#include <time.h>

#include "llist.h"
#include "bstree.h"

typedef long int Integer;
void printList(const llist<Integer> &list);

int main(int argc, char** argv) {

    srand(time(NULL));
    Integer n = 100000000;
    Integer mulFactor = 2 * n;
    llist<Integer> list;

    for (Integer i = 0; i < n; ++i) {

        llnode<Integer> * node = new llnode<Integer>((rand() % mulFactor), nullptr, nullptr);
        list.listInsert(node);
        node = nullptr;
    }
    return 0;
}

void printList(const llist<Integer> &list) {
    llnode<Integer> * p = new llnode<Integer>();
    p = list.getNil()->next;
    int cantNodos = 0;

    while (p != list.getNil()) {
        std::cout << "Nodo " << ++cantNodos << ": " << p->key << std::endl << std::endl;
        p = p->next;
    }
    std::cout << std::endl << std::endl;
    p = nullptr;
}



