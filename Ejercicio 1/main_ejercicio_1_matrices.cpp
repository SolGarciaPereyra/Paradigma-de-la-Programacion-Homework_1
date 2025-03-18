#include "ejercicio_1_matrices.hpp"

int main(){
    array<array<int, N>, N> mi_matriz = crear_mi_matriz(); //Invoco mi funcion para crear la matriz de tamaño N.

    /*La siguiente seccion de codigo la implemente para poder imprimir la matriz, siguiendo la estructura pedida en la consigna. 
    Como la tarea indica que solamente se puede usar un solo bucle, pense en una alternativa para el que habria sido el segundo 
    bucle o bulce interno. Entonces, use un bucle del tipo "while" para asegurarme de que no estaba tratando de acceder a un numero de
    subarray inexistente. Para eso, declare una variable llamada "contador" para, como su nombre lo indica, llevar conteo, y no pasarme, 
    del numero de array que estoy accediendo en cada iteracion. Luego, como nuestra matriz es cuadrada, sabemos que contiene N filas y 
    que cada una de ellas tiene N elementos. Ademas, habia que tener en cuenta que la consigna pide desde el mayor valor al menor. 
    Entonces, en vez de usar un segudno bucle, decidi declarar la variable "tracker", la cual me sirve para llevar registro de la cantidad
    de filas que voy recorriendo e imprimiendo. Para eso, necesite declarar una tercera varibale, "seguimiento", e implementar un doble
    condicional. Utilice "seguimiento" para poder indexar cada subarray y poder imprimir los elementos. A medida que imprimia un valor, 
    disminuia "seguimiento" en una unidad (empezando desde N-1 por lo de "desde el mayor al menor", y porque para indexar se arranca a 
    contar desde 0, entonces termina en una unidad menor al tamaño). Chequeaba si la varibale seguia siendo mayor o igual a cero (para 
    mantenerme en el rango permitido) y, de no serlo, significaba que ya habia termiando de imprimir todos los numeros en esa fila, 
    y por lo tanto, pasaba a la siguiente fila disminuyendo "contador" en una unidad, restablecinedo "seguimiento" a su valor oginal: N -1.
    Al igual que con la varibale "seguimiento", inicialice "contador" en N - 1 para complir con lo de "de mayor a menor".*/
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