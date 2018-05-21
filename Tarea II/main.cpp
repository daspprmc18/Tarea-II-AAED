#include <chrono>
#include <cstdlib>
#include <random>

#include "pruebas.h"

int main(int argc, char** argv) {

    Integer n    = 1000000;
    Integer min  = 0;
    Integer max  = (2 * n) - 1;

    std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count()); // Generador de números aleatorios "Mersenne Twister 19937"
    std::uniform_int_distribution<Integer> distribution(min, max); // Rango distribución uniforme: [0,2n-1].



    testRandomList(engine, distribution, n);
    testSequentialList(engine, distribution, n);

    testSequientialBinaySearchTree(engine, distribution, n);
    testRandomBinarySearchTree(engine, distribution, n);

    testSequientialRedBlackTree(engine, distribution, n); // Si lo corro solo hace más búsquedas que cuando corrí previamente la búsqueda de aleatorios...
    testRandomRedBlackTree(engine, distribution, n);

    testRandomHashT(engine, distribution, n);
    testSequentialHashT(engine, distribution, n);

    return 0;
}