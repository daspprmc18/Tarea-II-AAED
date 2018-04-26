#include <cstdlib>
#include "llist.h"
#include "bstree.h"

typedef int DataType;

void printList(const llist<DataType> &list);

int main(int argc, char** argv)
{
	llist<DataType> * list = new llist<DataType>();
	llnode<DataType> * element = new llnode<DataType>(5, nullptr, nullptr);
	llnode<DataType> * element2 = new llnode<DataType>(-1, nullptr, nullptr);
	llnode<DataType> * element3 = new llnode<DataType>(30, nullptr, nullptr);
	list->listInsert(element);
	list->listInsert(element2);
	list->listInsert(element3);

	printList(*list);


	llist<DataType> * list2 = new llist<DataType>(*list);
	printList(*list2);

	delete list;
	delete list2;
	delete element;
	delete element2;

	return 0;
}

void printList(const llist<DataType> &list)
{
	llnode<DataType> * p = new llnode<DataType>();
	p = list.getNil()->next;
	int cantNodos = 0;

	while (p != list.getNil()) {
		std::cout << "Nodo " << ++cantNodos << ": " << p->key << std::endl << std::endl;
		p = p->next;
	}
	std::cout << std::endl << std::endl;
}



