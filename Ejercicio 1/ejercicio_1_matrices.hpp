#include <iostream>
#include <array>
using namespace std;

constexpr int N = 3;  //Tamaño de mi matriz (lo elegi arbitrariamente)

/*
    Crea una matriz cuadrada, con valores que empiezan desde 1 hasta N^2, usando un valor entero positivo 
    "N" (mayor a 1), el cual fue definido anteriormente.
*/
array<array<int, N>, N> crear_mi_matriz();