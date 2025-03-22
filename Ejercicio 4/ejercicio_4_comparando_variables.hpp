#include <iostream>
#include <string>
#include <chrono>
using namespace std;

//Para el inciso 4c:
//Defino mis variables con "constexpr" para que mi compilador conozca sus valores en tiempo de compilacion, y pueda entonces tambien realizar la funcion en tiempo de compilacion.
constexpr const char variable1[] = "Se requiere el código de una función recursiva que compare dos variables que contengan texto e indique mediante una variable bool si son iguales.";
constexpr const char variable2[] = "Se requiere el código de una función recursiva que compare dos variables que contengan texto e indique mediante una variable bool si son.";
constexpr int index_2 = 0;   //Lo inicializo en ese valor ya que un arrays de chars se comienza a contar desde el cero.

/*
    Sirve para comparar dos variables strings e indicar si son iguales o no.
*/
bool comparar_variables(string primera_variable, string segunda_variable);

/*
    Sirve para comparar dos variables const char* e indicar si son iguales o no.
*/
bool comparar_variables(const char* primera_variable, const char*segunda_variable, int index);


/*
    Sirve para comparar dos variables const char* e indicar si son iguales o no.
    Realiza la comparación en tiempo de compilacion. 
    Es una modificacion de la funcion de arriba, la cual elegi en el inciso 4a, para
    realizar el inciso 4c.
*/
constexpr bool comparar_variables_compilacion(const char* primera_variable, const char* segunda_variable, int index){
    //Primer caso base: ambos arrays estan vacios.
    if((primera_variable[index] == '\0') && (segunda_variable[index] == '\0')){
        return true;
    }
    //Comparo los chars apartados anteriormente:
    if(!(primera_variable[index] == segunda_variable[index])){ 
        return false;
    }
    /*Si son iguales, aumento el valor de index en una unidad, para poder comparar el siguiente char en el array, cuando 
    realice la recursividad.*/
    return comparar_variables_compilacion(primera_variable, segunda_variable, index + 1);
}