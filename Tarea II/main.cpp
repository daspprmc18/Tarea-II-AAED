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

    /*for (Integer i = 0; i < n; ++i) {

        node = new llnode<Integer>((rand() % mulFactor), nullptr, nullptr);
        list.listInsert(node);
        node = nullptr;
    }*/

    for (Integer i = 0; i < n; ++i) {

        node = new llnode<Integer>(i, nullptr, nullptr);
        list.listInsert(node);
        node = nullptr;
    }

    printList(list);

    llnode<Integer>* p = list.listSearch(0);
    llnode<Integer>* q = list.listSearch(5);
    llnode<Integer>* r = list.listSearch(19);
    llnode<Integer>* s = list.listSearch(1);
    llnode<Integer>* t = list.listSearch(3);
    llnode<Integer>* u = list.listSearch(7);
    llnode<Integer>* v = list.listSearch(2);
    llnode<Integer>* w = list.listSearch(6);



    std::cout << "Eliminando " << 19 << "\n\n";
    list.listDelete(r);
    printList(list);

    std::cout << "Eliminando " << 3 << "\n\n";
    list.listDelete(t);
    printList(list);

    std::cout << "Eliminando " << 5 << "\n\n";
    list.listDelete(q);
    printList(list);

    std::cout << "Eliminando " << 1 << "\n\n";
    list.listDelete(s);
    printList(list);

    std::cout << "Eliminando " << 0 << "\n\n";
    list.listDelete(p);
    printList(list);

    std::cout << "Eliminando " << 2 << "\n\n";
    list.listDelete(v);
    printList(list);

    std::cout << "Eliminando " << 7 << "\n\n";
    list.listDelete(u);
    printList(list);

    std::cout << "Eliminando " << 6 << "\n\n";
    list.listDelete(w);
    printList(list);

    delete p;
    q = nullptr;
    r = nullptr;
    s = nullptr;
    t = nullptr;
    u = nullptr;
    v = nullptr;
    w = nullptr;

    printList(list);
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



