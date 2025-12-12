#include "Sistema.h"
#include <iostream>
using namespace std;

Sistema::Sistema(int ordenArbol) {
    this -> arbol = new ArbolBPlus(ordenArbol);
    this -> siguienteID = 1;
}

Sistema::~Sistema() {delete arbol;}

void Sistema::crearNodo(int id_padre) {}

void Sistema::eliminar_archivo(int id_archivo, int id_directorio_padre) {
    NodoGrafo* padre = arbol -> buscar_nodo_grafo(id_directorio_padre);
    NodoGrafo* archivo = arbol -> buscar_nodo_grafo(id_archivo);

    if (!padre || !padre -> es_directorio()) {
        cout << "El directorio padre no existe" << endl;
        return;
    }

    if (!archivo || archivo -> es_directorio()) {
        cout << "No corresponde a un archivo" << endl;
        return;
    }

    padre -> eliminarHijo(id_archivo);
    archivo -> eliminarPadre(id_directorio_padre);
    cout << "Archivo eliminado del directorio" << endl;
}

void Sistema::listar_contenido(int id_directorio) {
    NodoGrafo* directorio = arbol -> buscar_nodo_grafo(id_directorio);
    if (!directorio || !directorio -> es_directorio()) {
        cout << "No es un directorio" << endl;
        return;
    }

    cout << "Contenido del directorio" << endl;

    int* hijos = directorio -> lista_hijos();
    int cantidad = directorio -> cantidadHijos();

    for (int i = 0; i < cantidad; i++) {
        NodoGrafo* hijo = arbol -> buscar_nodo_grafo(hijos[i]);
        cout << " - " << hijos[i];
        if (hijo -> es_directorio()) {
            cout << " (Directorio)";
        } else {
            cout << " (Archivo)";
        }
        cout << endl;
    }
}

vector<string> Sistema::obtener_rutas_completas(int id_archivo) {}

int Sistema::calcular_espacio_ocupado(int id_directorio) {
    NodoGrafo* directorio = arbol -> buscar_nodo_grafo(id_directorio);

    if (!directorio || !directorio -> es_directorio()) {
        cout << "No es un directorio" << endl;
        return 0;
    }

    int total = 0;
    vector<int> pila;
    pila.push_back(id_directorio);

    while (!pila.empty()) {
        int actual = pila.back();
        pila.pop_back();

        NodoGrafo* nodo = arbol -> buscar_nodo_grafo(actual);

        if (!nodo -> es_directorio()) {
            NodoArchivo* arch = (NodoArchivo*) nodo;
            total += arch -> getTamaño();
        } else {
            int* hijos = ((NodoDirectorio*) nodo) -> lista_hijos();
            int cant = ((NodoDirectorio*) nodo) -> cantidadHijos();

            for (int i = 0; i < cant; i++) {
                pila.push_back(hijos[i]);
            }
        }
    }

    return total;
}