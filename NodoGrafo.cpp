#include "NodoGrafo.h"

NodoGrafo::NodoGrafo(int id) {
    this->id = id;
}

NodoGrafo::~NodoGrafo() {}

bool NodoGrafo::es_directorio() {return false;}

int* NodoGrafo::lista_padres(){return nullptr;}