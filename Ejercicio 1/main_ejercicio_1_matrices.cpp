#include "ejercicio_1_matrices.hpp"

int main(){
    array<array<int, N>, N> mi_matriz = crear_mi_matriz();

    int contador = N - 1;
    int seguimiento = N - 1;
    int tracker = 0;
    while(contador >=0){
        if(tracker <= N){
            if(seguimiento >= 0){
                cout << "Matriz" << N << "[" << contador << "][" << seguimiento << "] = " << mi_matriz[contador][seguimiento] << endl; 
                seguimiento--;  
            }
            else{
                contador--;
                seguimiento = N - 1;
                tracker++;
                continue;
            }
        }
        else{
            break;
        }
    }
}