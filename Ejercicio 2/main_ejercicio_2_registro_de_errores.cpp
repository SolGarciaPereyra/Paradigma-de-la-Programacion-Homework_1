#include "ejercicio_2_registro_de_errores.hpp"

int main(){
    //Verifico el funcionameinto de mi funcion logMensaje para el inciso a:
    //Los mensajes de cada leyenda son arbitrarios.
    NivelSeveridad primera_leyenda = DEBUG;
    string primera_leyenda_mensaje = "Error: valor negativo detectado";
    logMensaje(primera_leyenda_mensaje, primera_leyenda);

    NivelSeveridad segunda_leyenda = INFO;
    string segunda_leyenda_mensaje = "El programa inicio correctamente";
    logMensaje(segunda_leyenda_mensaje, segunda_leyenda);

    NivelSeveridad tercera_leyenda = WARNING;
    string tercera_leyenda_mensaje = "La memoria esta apunto de llenarse";
    logMensaje(tercera_leyenda_mensaje, tercera_leyenda);

    NivelSeveridad cuarta_leyenda = ERROR;
    string cuarta_leyenda_mensaje = "No se pudo abrir exitosamente el archivo";
    logMensaje(cuarta_leyenda_mensaje, cuarta_leyenda);

    NivelSeveridad quinta_leyenda = CRITICAL;
    string quinta_leyenda_mensaje = "No se pudo asignar la memoria requerida";
    logMensaje(quinta_leyenda_mensaje, quinta_leyenda);

    //Verifico el funcionameinto de mi funcion logMensaje para el inciso bii:
    //Tanto el mensaje de error, el nombre del archivo y la linea de codigo fueron elegidos de manera arbitraria.
    string mensaje_de_error = "segfault";
    string archivo = "guia_de_ejercicios.cpp";
    int linea_de_codigo = 7;
    logMensaje(mensaje_de_error, archivo, linea_de_codigo);

    //Verifico el funcionameinto de mi funcion logMensaje para el inciso biii:
    string mensaje_de_acceso = "CORRECTO";
    string nombre_de_usuario = "sgarciapereyra";
    logMensaje(mensaje_de_acceso, nombre_de_usuario);

    //Verifico el funcionameinto de mi funcion logMensaje para el inciso biv:
    //Uso el try para ejecutar el throw, el cual escribi con la intencion de generar un error y, por lo tanto, lanzar una excepcion en el programa.
    try{  
        throw runtime_error("Hubo un problema durante la ejecucion");
    }
    catch(runtime_error& e){  //Lo uso para atrapar la excepcion generada previamente y poder registrarla en el sistema log.
        //Defino una variable para poder guardar en ella el mensaje de error relacionado a la excepcion, el cual obtuve mediante el uso de e.what().
        string problema_de_ejecucion_mensaje = e.what();  
        bool es_runtime_error = true;
        logMensaje(problema_de_ejecucion_mensaje, es_runtime_error);
    }

    return 0;
}