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

//Para el inciso bii, biii y biv, realizo una sobrecarga de la funcion logMensaje.

/*
    Funcion que posibilita el registro de errores al sistema log, indicando el mensaje de error, el archivo
    y la linea de codigo donde sucedio el error. 
*/
void logMensaje(string Mensaje_de_Error, string Archivo, int Linea_de_Codigo);

/*
    Funcion que posibilita el registro de accesos de usuarios a la aplicacion.
*/
void logMensaje(string Mensaje_de_Acceso, string Nombre_de_Usuario);

/*
    Funcion que posibilita el registro de errores en tiempo de ejecucion, detener la ejecucion del 
    programa y salir del mismo con un codigo de error. 
    Le agrego el parametro de entrada Es_Runtime_Error porque, o si no, no me deja realizar la 
    sobrecarga de funcion, ya que no se termina de diferenciar de las demas. 
*/
int logMensaje(string Mensaje_de_Error, bool Es_Runtime_Error);