#include "ejercicio_4_comparando_variables.hpp"

int main(){
    //Mando a correr mi funcion que compara dos variables string, para ver cuanto tiempo tarda:
    //Declaro y defino las variables que voy a comparar (eleccion arbitraria):
    string primera_variable = "Se requiere el código de una función recursiva que compare dos variables que contengan texto e indique mediante una variable bool si son iguales.";
    string segunda_variable = "Se requiere el código de una función recursiva que compare dos variables que contengan texto e indique mediante una variable bool si son iguales.";
    //Uso el codigo proporcionado por la consigna para poder calcular el tiempo de ejecucion de mi funcion:
    auto startTime1 = std::chrono::high_resolution_clock::now();
    bool resultado_string = comparar_variables(primera_variable, segunda_variable);   //Reemplazo miProcesoAMedir() por comparar_variables().
    auto endTime1 = std::chrono::high_resolution_clock::now();
    auto elapsedTime1 = std::chrono::duration_cast<std::chrono::nanoseconds>(
    endTime1 - startTime1);
    std::cout << "A comparar_variables le tomó: " << elapsedTime1.count() << " nanosegundos" << std::endl;
    //Utilizo un condicional para mostrar en la terminal si mis dos variables son o no iguales:
    if(resultado_string){
        cout << "Son iguales las variables" << endl;
    }
    else{
        cout << "No son iguales" << endl;
    }

    //Mando a correr mi funcion que compara dos variables const char*, para ver cuanto tiempo tarda:
    //Declaro y defino las variables que voy a comparar (eleccion arbitraria):
    /*Aparte, declaro la variable index, ya que me va a ser util a la hora de comparar mis dos variables, aplicando el metodo de 
    recursividad. Me va a resultar util a la hora de indexar mi arrays de chars.*/
    const char* pri_variable = "Se requiere el código de una función recursiva que compare dos variables que contengan texto e indique mediante una variable bool si son iguales.";
    const char* seg_variable = "Se requiere el código de una función recursiva que compare dos variables que contengan texto e indique mediante una variable bool si son.";
    int index = 0;   //Lo inicializo en ese valor ya que un arrays de chars se comienza a contar desde el cero.
    //Uso el codigo proporcionado por la consigna para poder calcular el tiempo de ejecucion de mi funcion:
    auto startTime2 = std::chrono::high_resolution_clock::now();
    bool resultado_char = comparar_variables(pri_variable, seg_variable, index);
    auto endTime2 = std::chrono::high_resolution_clock::now();
    auto elapsedTime2 = std::chrono::duration_cast<std::chrono::nanoseconds>(
    endTime2 - startTime2);
    std::cout << "A comparar_variables le tomó: " << elapsedTime2.count() << " nanosegundos" << std::endl;
    //Utilizo un condicional para mostrar en la terminal si mis dos variables son o no iguales:
    if(resultado_char){
        cout << "Son iguales las variables" << endl;
    }
    else{
        cout << "No son iguales" << endl;
    }

    /* Termino eligiendo la opcion de const char* ya que, usando esa opcion, comparar_variables corre muchisimo mas rapido.
    Supongo que esto sucede debido a que, cuando uso strings, al tener que guardar copias de substrings para realizar la 
    recursividad, estoy volviendo mas lento mi programa. Ademas, en el caso base donde comparo las longitudes de mis strings, 
    el uso de .length() puede aportar un poco a esa diferencia en nanosegundos. Por ultimo, considero tambien que la diferencia 
    se puede dar debido a que const char* es un puntero, por lo que es mucho mas rapido acceder a los valores guardados en memoria.*/



    return 0;
}