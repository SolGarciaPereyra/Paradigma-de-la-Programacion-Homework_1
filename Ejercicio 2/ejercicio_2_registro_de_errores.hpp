#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
    Es una funcion que sirve para crear un sistema log: se usa para agregar entradas a un archivo, 
    en las cuales se aclara el evento relevante sucedido, acompañados de un mensaje que explique
    un poco acerca del evento. 
*/
void logMensaje(string mensaje, int NivelSeveridad);