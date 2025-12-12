#include "NodoArchivo.h"

NodoArchivo::NodoArchivo(int id, int tamaño, int tipo) : NodoGrafo(id) {
    this -> tamaño = tamaño;
    this -> tipo = tipo;
}

NodoArchivo::~NodoArchivo(){}

bool NodoArchivo::es_directorio() {return false;}

int NodoArchivo::getTamaño() {return tamaño;}

int NodoArchivo::getTipo() {return tipo;}