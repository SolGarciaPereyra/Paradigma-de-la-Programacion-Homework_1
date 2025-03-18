#include "ejercicio_1_matrices.hpp"

array<array<int, N>, N> crear_mi_matriz(){
    //Declaro mi matriz, la cual esta fromada con un array de arrays. El tamaño de mi matriz lo declaro y defino en mi archivo .hpp.
    array<array<int, N>, N> mi_matriz;

    int numerador = 1;  //Variable que voy a usar como elemento para completar mi matriz. 
    for(int position = 0; position < N; position++){   //Itero para acceder a cada array dentro de mi array principal. 
        for(int index = 0; index < N; index++){   //Itero para poder acceder a cada posicion de mi matriz (cada completar las posiciones del subarray).
            mi_matriz[position][index] = numerador;  //Agrego el elemento a mi matriz.
            numerador++;  //Incremento mi variable en una unidad, para que la siguiente posicion en mi matriz se complete con el numero esperado (arrrancando desde 1 hasta N^2).
        }
    }

    return mi_matriz;
}