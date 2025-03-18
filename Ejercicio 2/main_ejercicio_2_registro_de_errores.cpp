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


    return 0;
}