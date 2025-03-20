#include "ejercicio_4_comparando_variables.hpp"

bool comparar_variables(string primera_variable, string segunda_variable){
    //Primer caso base: si mis dos strings no tienen la misma longitud, definitivamente no son iguales.
    if(!(primera_variable.length() == segunda_variable.length())){   
        return false;
    }
    //Segundo caso base: si ambos strings estan vacios, son iguales.
    if((primera_variable == "") && (segunda_variable == "")){
        return true;
    }
    //Tercer caso base: que la longitud de mis strings sean igual a 1
    /*Elegi usar el largo de primera_variable, pero podria haber usado el de segunda_variable ya que, como no entro en el primer 
    condicional, signfica que ambos strings comparten la misma longitud.*/
    if(primera_variable.length() == 1){ 
        if(primera_variable == segunda_variable){
            return true;
        }
        else{
            return false;
        }
    }
    //En el caso de que ambos strings tengan la misma longitud y esta sea mayor a 1:
    int longitud_de_las_variables = primera_variable.length();  //Me guardo el valor de sus longitudes.
    int index = 0;  //Variable que voy a usar para acceder al caracter index-esimo de ambos strings.
    if(primera_variable.at(index) == segunda_variable.at(index)){  //Si coinciden en el caracter index-esimo
        /*La idea es ir comparando las variables y a medida que vayan coincidiendo los caracteres, achicamos las variables, quedandonos 
        con los caracteres que aun no fueron comparados. Esto lo hacemos hasta que los strings queden vacios (segundo caso base), lo 
        que indica que las variables si son iguales.*/
        string nueva_primera_variable = primera_variable.substr(index + 1, longitud_de_las_variables - 1);  //Me guardo un substring de la variable, empezando por el caracter posicionado en el index+1-esimo lugar.
        string nueva_segunda_variable = segunda_variable.substr(index + 1, longitud_de_las_variables - 1);  //En ambos substrings termino en longitud - 1 ya que, como se empieza a contar desde cero, se termina en uno menor a la longitud total.
        return comparar_variables(nueva_primera_variable, nueva_segunda_variable);  //Aplico recursividad para seguir comparando, pasando como parametros de entrada a los dos substrings.
    }
    else{  //En caso de que primera_variable no sea igual a segunda_variable en el caracter index-esimo.
        return false;
    }

}

bool comparar_variables(const char* primera_variable, const char*segunda_variable, int index){
    //Indexo ambos arrays de chars, para obtener su char encontrado en la posicion index.
    char caracter_a_comparar_pv = primera_variable[index];
    char caracter_a_comparar_sv = segunda_variable[index];
    //Primer caso base: ambos arrays estan vacios.
    if((caracter_a_comparar_pv == '\0') && (caracter_a_comparar_sv == '\0')){
        return true;
    }
    //Comparo los chars apartados anteriormente:
    if(caracter_a_comparar_pv == caracter_a_comparar_sv){ 
        /*Si son iguales, aumento el valor de index en una unidad, para poder comparar el siguiente char en el array, cuando 
        realice la recursividad.*/
        index = index + 1;
        return comparar_variables(primera_variable, segunda_variable, index);
    }
    else{
        return false;
    }
}