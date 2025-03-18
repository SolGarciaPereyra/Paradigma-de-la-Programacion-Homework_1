#include "ejercicio_2_registro_de_errores.hpp"

void logMensaje(string mensaje, int NivelSeveridad){
    //Creo y/o abro mi archivo de texto en el que llego registro de los eventos. Uso ios::app para no sobreescribir mi archivo.
    ofstream archivo("sistema_log.txt", ios::app);   

    if(archivo.is_open()){  //Verifico que se abrio bien el archivo
        //Comparo el int que recibio mi funcion, con el int que representa cada leyenda perteneciente al enum definido en .hpp.
        //Esto lo hago para saber que leyendo escribo en mi sistema log.
        //Repito break en cada case para que, una vez macheado con alguna de las leyendas, no siga intentado con las demas. 
        switch(NivelSeveridad){   
            case DEBUG:
                archivo << "[DEBUG] < " << mensaje << " >\n";
                archivo.close();
                break; 
            case INFO:
                archivo << "[INFO] < " << mensaje << " >\n";
                archivo.close();
                break;
            case WARNING:
                archivo << "[WARNING] < " << mensaje << " >\n";
                archivo.close();
                break;
            case ERROR:
                archivo << "[ERROR] < " << mensaje << " >\n";  
                archivo.close(); 
                break;
            default:
                archivo << "[CRITICAL] < " << mensaje << " >\n"; 
                archivo.close();
                break;
        }
    }
    else{
        cout << "Hubo un error al intentar abrir el archivo." << endl;
    }  
}