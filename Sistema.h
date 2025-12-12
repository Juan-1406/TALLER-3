#pragma once
#include "ArbolBPlus.h"
#include "NodoDirectorio.h"
#include "NodoArchivo.h"
#include <iostream>
#include <vector>
using namespace std;


class Sistema {
private:
    ArbolBPlus* arbol;
    int siguienteID;

public:
    Sistema(int ordenArbol);
    ~Sistema();

    void insertar_nodo_grafo(int clave, NodoGrafo* nodo_grafo);
    NodoGrafo* buscar_nodo_grafo(int clave);
    void crearNodo(int id_padre);
    void eliminar_archivo(int id_archivo, int id_directorio_padre);
    void listar_contenido(int id_directorio);
    vector<string> obtener_rutas_completas(int id_archivo);
    int calcular_espacio_ocupado(int id_directorio);
};
