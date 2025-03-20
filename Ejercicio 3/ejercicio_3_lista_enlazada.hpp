#include <iostream>
#include <memory>
using namespace std;

struct nodo {    //Defino la estructura de mi nodo.
    int valor;   //Elemento que posee el nodo.
    shared_ptr<nodo> siguiente_nodo;   //Puntero al nodo siguiente en la lista
};

struct lista {  //Defino la estructura de mi lista.
    int tamaño;  //Valor que indica el largo de la lista 
    shared_ptr<nodo> nodo_cabeza; //Puntero a la cabeza de la lista
    shared_ptr<nodo> nodo_cola; // Puntero a la cola de la lista 
};

/*
    Inicializa una lista y te la devuelve.
*/
lista create_list();

/*
    Devuelve un nodo.
*/
shared_ptr<nodo> create_node();

/*
    Inserta un nodo al frente de la lista.
    Utilizo como parametro de entrada una referencia a la lista que quiero modificar (por eso uso el &).
*/
void push_front(lista& lista_a_modificar);

/*
    Inserta un nodo al final de la lista.
    Utilizo como parametro de entrada una referencia a la lista que quiero modificar (por eso uso el &).
*/
void push_back(lista& lista_a_modificar);

/*
    Inserta un nodo en la posicion que se le pasa como parametro de entrada a la funcion.
    Si se le pasa una posición mayor al largo de la lista, se indica lo ocurrido y se 
    agrega el nodo al final de la lista. 
    Aclaración: Personalmente considero que las opciones de posiciones deben arrancar desde 1.
*/
void insert(int posicion, lista& lista_a_modificar);

/*
    Borra el nodo que se encuentra en la posicion que se le pasa como parametro de entrada a la funcion.
    Si se le pasa una posición mayor al largo de la lista, se indica lo ocurrido y se elimina el nodo al 
    final de la lista. 
    Aclaración: Personalmente considero que las opciones de posiciones deben arrancar desde 1.
*/
void erase(int posicion, lista& lista_a_modificar);

/*
    Imprime la lista completa.
*/
void print_list(lista& lista_a_imprimir);