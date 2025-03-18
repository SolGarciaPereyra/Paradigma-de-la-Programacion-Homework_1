#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Defino mi enum con las leyendas esperadas, para que coincida con el parametro de entrada exigido por la funcion definida en la consigna.
//Arbitrariamente arranco en 1, ya que personalmente considero que un nivel de severidad deberia arrancar desde 1, no 0.
enum NivelSeveridad {DEBUG = 1, INFO, WARNING, ERROR, CRITICAL};  

/*
    Es una funcion que sirve para crear un sistema log: se usa para agregar entradas a un archivo, 
    en las cuales se aclara el evento relevante sucedido, acompañados de un mensaje que explique
    un poco acerca del evento. Es util para llevar registro de todos los eventos relevantes ocurridos.
*/
void logMensaje(string mensaje, int NivelSeveridad);