#ifndef PRUEBAS_H
#define PRUEBAS_H

#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <stack>

#include "bstree.h"
#include "hasht.h"
#include "llist.h"
#include "rbtree.h"

typedef long int Integer;

// Funciones Auxiliares:

void printList (const llist<Integer> &list);
void printStack (stack<Integer> &stk);

// Funciones de pruebas:

void testRandomRedBlackTree (std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n);
void testSequientialRedBlackTree (std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n);
void testRandomHashT (std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n);
void testSequentialHashT (std::mt19937 &engine, std::uniform_int_distribution<Integer> &distribution, Integer &n);

#endif /* PRUEBAS_H */

