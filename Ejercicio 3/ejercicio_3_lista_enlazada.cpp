#include "ejercicio_3_lista_enlazada.hpp"

lista create_list(){
    lista nueva_lista;
    //Comienzo a inicializar mi lista vacia:
    nueva_lista.nodo_cabeza = nullptr;  //Indico que el puntero esta vacio
    nueva_lista.nodo_cola = nullptr; //Indico que el puntero esta vacio
    nueva_lista.tamaño = 0;   //Lo igualo a cero porque mi lista esta vacia.
    return nueva_lista;
}

shared_ptr<nodo> create_node(){
    shared_ptr<nodo> nuevo_nodo = make_shared<nodo>();  //Declaro una nueva variable, la cual es un puntero shared a un nodo (sin tener valores inicializados).
    return nuevo_nodo; 
}
 
void push_front(lista& lista_a_modificar){
    shared_ptr<nodo> nuevo_nodo = create_node();   //Creo un nodo vacio
    nuevo_nodo->valor = 11; //Inicializo el valor de mi nodo (eleccion arbitraria)

    if(lista_a_modificar.tamaño == 0){
        //Si mi lista esta vacia, para insertarlo nomas me tengo que asegurar que el puntero de cabeza y cola apunten al nuevo nodo
        lista_a_modificar.nodo_cabeza = nuevo_nodo;   
        lista_a_modificar.nodo_cola = lista_a_modificar.nodo_cabeza;   //Al ser share pointers, pueden compartir direcciones
        lista_a_modificar.nodo_cola->siguiente_nodo = nullptr;  //Indico que el nodo no apunta a ningun otro.
        lista_a_modificar.tamaño = lista_a_modificar.tamaño + 1;  //Actualizo el tamaño de la lista. 
    }
    else{
        /*Si mi lista no esta vacia, para insertarlo correctamente me tengo que asegurar de que el puntero de cabeza apunte
        al nuevo nodo, este tenga su puntero de "siguiente_nodo" apuntando al que era previamente primer nodo.*/
        lista_a_modificar.nodo_cabeza = nuevo_nodo;
        lista_a_modificar.nodo_cabeza->siguiente_nodo = lista_a_modificar.nodo_cola;
        lista_a_modificar.tamaño = lista_a_modificar.tamaño + 1;
    }
}

void push_back(lista& lista_a_modificar){
    shared_ptr<nodo> nuevo_nodo = create_node();   //Creo un nodo vacio
    nuevo_nodo->valor = 12; //Inicializo el valor de mi nodo (eleccion arbitraria)

    if(lista_a_modificar.tamaño == 0){
        //Si mi lista esta vacia, para insertarlo nomas me tengo que asegurar que el puntero de cabeza y cola apunten al nuevo nodo
        lista_a_modificar.nodo_cabeza = nuevo_nodo;   
        lista_a_modificar.nodo_cola = lista_a_modificar.nodo_cabeza;   //Al ser share pointers, pueden compartir direcciones
        lista_a_modificar.nodo_cola->siguiente_nodo = nullptr;  //Indico que el nodo no apunta a ningun otro.
        lista_a_modificar.tamaño = lista_a_modificar.tamaño + 1;  //Actualizo el tamaño de la lista. 
    }
    else{
        /*Si mi lista no esta vacia, para insertarlo correctamente me tengo que asegurar de que el puntero de cola apunte
        al nuevo nodo. Y tambien de que el previamente ultimo nodo, tenga su puntero "siguiente_nodo" apuntando al nuevo.*/
        lista_a_modificar.nodo_cola->siguiente_nodo = nuevo_nodo;
        lista_a_modificar.nodo_cola = nuevo_nodo;
        nuevo_nodo->siguiente_nodo = nullptr;  //Indico que el nodo no apunta a ningun otro.
        lista_a_modificar.tamaño = lista_a_modificar.tamaño + 1;
    }
}

void insert(int posicion, lista& lista_a_modificar){
    //Aclaración: Personalmente considero que las opciones de posiciones deben arrancar desde 1.
    if(!(posicion >= 1)){
        cout << "El numero de posicion indicado no es valido." << endl;
    }
    else if(posicion > lista_a_modificar.tamaño){  //Condicion exigida por la consigna del trabajo.
        cout << "El numero de posicion indicado es mayor al largo total de la lista. Por lo tanto, se lo va a insertar al final de la lista." << endl;
        push_back(lista_a_modificar);  //Lo inserto al final de la lista.
        print_list(lista_a_modificar);
    }
    else if(posicion == 1){  //Osea que lo quieren insertar en la primera posicion de la lista (en la cabeza).
        push_front(lista_a_modificar);
        print_list(lista_a_modificar);
    }
    else{
        int index_actual = 2;  //Lo voy a usar para poder llevar referencia acerca de la parte/posicion de la lista que estoy recorriendo.
        //Arranco index_actual desde 2 ya que, gracias a la estructra de la lista y los nodos que defini, puedo acceder directamente al segundo nodo, ahorrandome una iteracion del bucle.
        shared_ptr<nodo> nodo_previo = lista_a_modificar.nodo_cabeza; //Me guardo el nodo que se encuentra posicionado antes que el nodo_actual en la lista.
        shared_ptr<nodo> nodo_actual = lista_a_modificar.nodo_cabeza->siguiente_nodo;  //Es el nodo que se encuentra en la posicion numero index_actual de la lista.
        shared_ptr<nodo> nodo_siguiente = lista_a_modificar.nodo_cabeza->siguiente_nodo->siguiente_nodo; //Me guardo el nodo que se encuentra posicionado despues que el nodo_actual en la lista.
        while(index_actual != posicion){
            /*La idea de este bucle es ir avanzando a lo largo de la lista, guardando las referencias a los punteros mencionados arriba, para que, cuando llegue a 
            la posicion deseada, ya tenga guardada los punteros que voy a tener que actualizar para poder realizar la insercion exitosamente.*/
            nodo_previo = nodo_actual;
            nodo_actual = nodo_siguiente;  
            nodo_siguiente = nodo_siguiente->siguiente_nodo;
            index_actual = index_actual + 1; //Actualizo la posicion en la que me encuentro parada en nodo_actual, dentro de la lista.
        }

        shared_ptr<nodo> nuevo_nodo = create_node();   //Creo un nodo vacio (el cual voy a insertar)
        nuevo_nodo->valor = 13; //Inicializo el valor de mi nodo (eleccion arbitraria)  
        
        //Realizo la insercion, actualizando los punteros de los nodos como corresponde:
        nodo_previo->siguiente_nodo = nuevo_nodo;
        nuevo_nodo->siguiente_nodo = nodo_actual;  //Mando el nodo que se encontraba en la posicion deseada, una posicion mas adelante en la lista.

        lista_a_modificar.tamaño = lista_a_modificar.tamaño + 1;  //Actualizo el tamaño de la lista.
        print_list(lista_a_modificar);
    }
}

void erase(int posicion, lista& lista_a_modificar){
    //Aclaración: Personalmente considero que las opciones de posiciones deben arrancar desde 1.
    if(!(posicion >= 1)){
        cout << "El numero de posicion indicado no es valido." << endl;
    }
    /*El siguiente else if considera tanto la condicion exigida por la consigna del trabajo, como el caso en el que la posicion deseada sea igual 
    a la ultima posicion en la lista. A estas dos situaciones las resuelvo de manera conjunta (comparten solucion), ya que en ambos casos 
    lo que se deberia hacer es eliminar el ultimo nodo en la lista.*/
    else if((posicion > lista_a_modificar.tamaño) || (posicion == lista_a_modificar.tamaño)){
        if(posicion > lista_a_modificar.tamaño){  //Establezco este condicional ya que, si se cumple lo de posicion == lista_a_modificar.tamaño, no hay que imprimir el mensaje de abajo.  
            cout << "El numero de posicion indicado es mayor al largo total de la lista. Por lo tanto, se va a eliminar el ultimo nodo." << endl; 
        }
        
        //Elimino el ultimo nodo:
        /*Aclaracion: como estoy trbajando con shared ptrs, no necesito usar free() o delte para vaciar la memoria utilizada.
        Simplemente con asegurarme de que el numero de referencias del puntero que quiero eliminar llegue a cero, ya se va a eliminar
        por si mismo.*/
        int index_actual = 2;  //Lo voy a usar para poder llevar referencia acerca de la parte/posicion de la lista que estoy recorriendo.
        //Arranco index_actual desde 2 ya que, gracias a la estructra de la lista y los nodos que defini, puedo acceder directamente al segundo nodo, ahorrandome una iteracion del bucle.
        shared_ptr<nodo> nodo_previo = lista_a_modificar.nodo_cabeza; //Me guardo el nodo que se encuentra posicionado antes que el nodo_actual en la lista.
        shared_ptr<nodo> nodo_actual = lista_a_modificar.nodo_cabeza->siguiente_nodo;  //Es el nodo que se encuentra en la posicion numero index_actual de la lista.
        shared_ptr<nodo> nodo_siguiente = lista_a_modificar.nodo_cabeza->siguiente_nodo->siguiente_nodo; //Me guardo el nodo que se encuentra posicionado despues que el nodo_actual en la lista.
        while(index_actual != lista_a_modificar.tamaño){
            /*La idea de este bucle es ir avanzando a lo largo de la lista, guardando las referencias a los punteros mencionados arriba, para que, cuando llegue a 
            la posicion deseada, ya tenga guardada los punteros que voy a tener que actualizar para poder realizar la eliminacion exitosamente.*/
            nodo_previo = nodo_actual;
            nodo_actual = nodo_siguiente;  
            nodo_siguiente = nodo_siguiente->siguiente_nodo;
            index_actual = index_actual + 1; //Actualizo la posicion en la que me encuentro parada en nodo_actual, dentro de la lista.
        }
        
        //Me aseguro de anular las referencias existentes hacia el nodo que deseo eliminar (nodo_actual):
        nodo_previo->siguiente_nodo = nullptr;  //Como se esta por convertir en la nueva cola de la lista, su "siguiente_nodo" no tiene que tener referencia a ningun otro nodo.
        lista_a_modificar.nodo_cola = nodo_previo;  //Actualizo la cola de la lista.
        nodo_actual->siguiente_nodo = nullptr;  //Para que el nodo que quiero eliminar ya no posea referencia a ningun otro nodo.

        lista_a_modificar.tamaño = lista_a_modificar.tamaño - 1;  //Actualizo el nuevo tamaño de la lista
        print_list(lista_a_modificar);
    }
    else if(posicion == 1){  //Osea que quieren eliminar el primer nodo en la lista (en la cabeza).
        //Elimino el primer nodo:
        /*Aclaracion: como estoy trbajando con shared ptrs, no necesito usar free() o delte para vaciar la memoria utilizada.
        Simplemente con asegurarme de que el numero de referencias del puntero que quiero eliminar llegue a cero, ya se va a eliminar
        por si mismo.*/
        shared_ptr<nodo> nodo_a_eliminar = lista_a_modificar.nodo_cabeza;
        lista_a_modificar.nodo_cabeza = lista_a_modificar.nodo_cabeza->siguiente_nodo;  //Actualizo la cabeza de la lista, la cual ahora es el nodo que se encuentra despues del que quiero eliminar, en la lista.
        nodo_a_eliminar->siguiente_nodo = nullptr;  //Para que el nodo que quiero eliminar ya no posea referencia a ningun otro nodo.

        lista_a_modificar.tamaño = lista_a_modificar.tamaño - 1;  //Actualizo el nuevo tamaño de la lista
        print_list(lista_a_modificar);
    }
    else{
        //Elimino el nodo:
        /*Aclaracion: como estoy trbajando con shared ptrs, no necesito usar free() o delte para vaciar la memoria utilizada.
        Simplemente con asegurarme de que el numero de referencias del puntero que quiero eliminar llegue a cero, ya se va a eliminar
        por si mismo.*/
        int index_actual = 2;  //Lo voy a usar para poder llevar referencia acerca de la parte/posicion de la lista que estoy recorriendo.
        //Arranco index_actual desde 2 ya que, gracias a la estructra de la lista y los nodos que defini, puedo acceder directamente al segundo nodo, ahorrandome una iteracion del bucle.
        shared_ptr<nodo> nodo_previo = lista_a_modificar.nodo_cabeza; //Me guardo el nodo que se encuentra posicionado antes que el nodo_actual en la lista.
        shared_ptr<nodo> nodo_actual = lista_a_modificar.nodo_cabeza->siguiente_nodo;  //Es el nodo que se encuentra en la posicion numero index_actual de la lista.
        shared_ptr<nodo> nodo_siguiente = lista_a_modificar.nodo_cabeza->siguiente_nodo->siguiente_nodo; //Me guardo el nodo que se encuentra posicionado despues que el nodo_actual en la lista.
        while(index_actual != posicion){
            /*La idea de este bucle es ir avanzando a lo largo de la lista, guardando las referencias a los punteros mencionados arriba, para que, cuando llegue a 
            la posicion deseada, ya tenga guardada los punteros que voy a tener que actualizar para poder realizar la eliminacion exitosamente.*/
            nodo_previo = nodo_actual;
            nodo_actual = nodo_siguiente;  
            nodo_siguiente = nodo_siguiente->siguiente_nodo;
            index_actual = index_actual + 1; //Actualizo la posicion en la que me encuentro parada en nodo_actual, dentro de la lista.
        }
        
        //Me aseguro de anular las referencias existentes hacia el nodo que deseo eliminar (nodo_actual):
        nodo_previo->siguiente_nodo = nodo_siguiente;
        nodo_actual->siguiente_nodo = nullptr;  //Para que el nodo que quiero eliminar ya no posea referencia a ningun otro nodo.
        
        lista_a_modificar.tamaño = lista_a_modificar.tamaño - 1;  //Actualizo el nuevo tamaño de la lista
        print_list(lista_a_modificar);
    }
}

void print_list(lista& lista_a_imprimir){
    if(lista_a_imprimir.tamaño == 0){  //Chequeo en caso de que este vacia
        cout << "La lista se encuentra vacia, no hay nada para imprimir." << endl;
    }
    else{   
        int contador = lista_a_imprimir.tamaño;  //Inicializo esta variable para llevar registro de cuantas veces mas me falta imprimir.
        shared_ptr<nodo> nodo_a_imprimir = lista_a_imprimir.nodo_cabeza;  //Me guardo el primer nodo de la lista
        //
        while(contador > 0){  
            if(contador == 1){  //Me fijo si es el ultimo, para no imrpimir una flecha al final.
                cout << nodo_a_imprimir->valor << endl;  //Imprimo el valor de "nodo_a_imprimir"
            }
            else{
                //Imprimo el valor de "nodo_a_imprimir" (no le puse "endl" al final, para que el siguiente nodo se me imprima en el mismo renglon)
                cout << nodo_a_imprimir->valor << " -> "; 
            }

            nodo_a_imprimir = nodo_a_imprimir->siguiente_nodo;  //Actualizo "nodo_a_imprimir", ya que pasa a ser el siguiente en la lista.
            contador = contador - 1;  //Actualizo cuantos nodos me quedan por imprimir
        }
    }
}