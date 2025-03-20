#include "ejercicio_3_lista_enlazada.hpp"

int main(){
    //Verifico el funcionamiento de mis funciones (los incisos 3i y 3vi los verifico/utilizo multiples veces a lo largo del trabajo):
    lista nueva_lista = create_list();  //Creo una lista vacia
    shared_ptr<nodo> nuevo_nodo = create_node();   //Creo un nodo vacio
    //Inicializo el valor de mi nodo (eleccion arbitraria):
    nuevo_nodo->valor = 10;
    nuevo_nodo->siguiente_nodo = nullptr; //Indico que el nodo no apunta a ningun otro.
    
    //Inicializo los punteros de mi lista con el nuevo nodo creado y actualizo el tamaño: 
    nueva_lista.nodo_cabeza = nuevo_nodo;   
    nueva_lista.nodo_cola = nueva_lista.nodo_cabeza;  //Al ser share pointers, pueden compartir direcciones
    nueva_lista.tamaño = nueva_lista.tamaño + 1;

    //Verifico inciso 3ii:
    push_front(nueva_lista);
    print_list(nueva_lista);

    //Verifico inciso 3iii:
    push_back(nueva_lista);
    print_list(nueva_lista);

    //Verifico inciso 3iv:
    //1º Caso: La posicion es igual a cero.
    int posicion_c1 = 0;
    insert(posicion_c1, nueva_lista);
    //2º Caso: La posicion es mayor al largo de la lista.
    int posicion_c2 = 4;
    insert(posicion_c2, nueva_lista);
    //3º Caso: La posicion esta entre 1 y el largo de la lista
    int posicion_c3 = 2;
    insert(posicion_c3, nueva_lista);

    //Verifico inciso 3v:
    //1º Caso: La posicion es igual a cero.
    int c1_posicion = 0;
    erase(c1_posicion, nueva_lista);
    //2º Caso: La posicion es mayor al largo de la lista.
    int c2_posicion = 6;
    erase(c2_posicion, nueva_lista);
    //3º Caso: La posicion esta entre 1 y el largo de la lista
    int c3_posicion = 2;
    erase(c3_posicion, nueva_lista);

    return 0;
}