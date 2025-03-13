#include "ejercicio_1_matrices.hpp"

array<array<int, N>, N> crear_mi_matriz(){
    array<array<int, N>, N> mi_matriz;

    int numerador = 1;
    for(int position = 0; position < N; position++){
        for(int index = 0; index < N; index++){
            mi_matriz[position][index] = numerador;
            numerador++;
        }
    }

    return mi_matriz;
}