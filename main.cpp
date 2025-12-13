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

    int opcion, orden, clave;

    cout << "Ingrese el orden del Arbol B+: "; cin >> orden;
    Sistema sistema(orden);

    do {
        menu();  cin >> opcion;
        int idPadre, idArchivo, idDirectorio;

        switch (opcion) {
            case 0:
                cout << "Saliste con Exito!" << endl;
                break;

            case 1: {
                cout << "Clave del nodo a insertar:"; cin >> clave;
                NodoGrafo* nodo = new NodoGrafo(clave);
                sistema.Insertar_nodo_grafo(clave, nodo);
                cout << "Nodo insertado en Arbol B+" << endl;
                cout<< endl;
                break;
            }

            case 2: {
                cout << "Clave a buscar:"; cin >> clave;
                NodoGrafo* nodo = sistema.Buscar_nodo_grafo(clave);
                if (nodo) {
                    cout << "Nodo encontrado" << endl;
                } else {
                    cout << "Nodo no encontrado" << endl;
                }
                cout << endl;
                break;
            }

            case 3:
                cout << "ID del directorio padre:"; cin >> idPadre;

                int tipo;
                cout << "Seleccione que desea crear:" << endl << "1. Directorio" << endl << "2. Archivo" << endl;
                cout << "Ingrese la opcion: "; cin >> tipo;

                if (tipo == 1) {
                    sistema.crearNodo(idPadre);
                } else if (tipo == 2) {
                    sistema.crearEsDirectorio = false;
                    cout << "Tamaño del archivo: "; cin >> sistema.crearTamaño;
                    cout << "Tipo del archivo: "; cin >> sistema.crearTipo;

                    sistema.crearNodo(idPadre);
                }


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