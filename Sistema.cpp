#include "Sistema.h"
#include <iostream>
using namespace std;

Sistema::Sistema(int ordenArbol) {
    this -> arbol = new ArbolBPlus(ordenArbol);
    this -> siguienteID = 1;
}

Sistema::~Sistema() {delete arbol;}

void Sistema::crearNodo(int id_padre) {}

void Sistema::eliminar_archivo(int id_archivo, int id_directorio_padre) {}

void Sistema::listar_contenido(int id_directorio) {}

vector<string> Sistema::obtener_rutas_completas(int id_archivo) {}

int Sistema::calcular_espacio_ocupado(int id_directorio) {}