#include <iostream>

#include "Sistema.h"
using namespace std;

void menu() {
    cout << "--- MENU ---" << endl;
    cout << "1. Insertar nodo en Arbol B+" << endl;
    cout << "2. Buscar nodo en Arbol B+" << endl;
    cout << "3. Crear nodo" << endl;
    cout << "4. Eliminar archivo (referencia)" << endl;
    cout << "5. Listar contenido de un directorio" << endl;
    cout << "6. Obtener rutas completas de un archivo" << endl;
    cout << "7. Calcular espacio ocupado de un directorio" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion:";
}

int main() {

    int opcion, orden;

    cout << "Ingrese el orden del Arbol B+: "; cin >> orden;
    Sistema sistema(orden);

    do {
        menu();  cin >> opcion;
        int idPadre, idArchivo, idDirectorio;
        switch (opcion) {
            case 0:
                cout << "Saliste con Exito!" << endl;
                break;
            case 1:
                cout << "Ingrese ID del directorio padre: "; cin >> idPadre;
                cout<< endl;
                break;
            case 2:
                cout << endl;
                break;
            case 3:
                cout << endl;
                break;
            case 4:
                cout << "ID del archivo a eliminar: "; cin >> idArchivo;
                cout << "ID del directorio padre: "; cin >> idPadre;
                sistema.eliminar_archivo(idArchivo, idPadre);
                cout << endl;
                break;
            case 5:
                cout << "ID del directorio a listar: "; cin >> idDirectorio;
                sistema.listar_contenido(idDirectorio);
                cout << endl;
                break;
            case 6:
                cout << "ID del archivo: "; cin >> idArchivo;
                cout << endl;
                break;
            case 7: {
                cout << "ID del directorio: "; cin >> idDirectorio;
                int espacio = sistema.calcular_espacio_ocupado(idDirectorio);
                cout << "El directorio ocupa: " << espacio << " unidades" << endl;
                cout << endl;
                break;
            }
            default:
                cout << "Opcion invalida. Intentalo nuevamente" << endl << endl;

        }
    } while (opcion != 0);
    return 0;
}