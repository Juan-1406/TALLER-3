#include "NodoDirectorio.h"

NodoDirectorio::NodoDirectorio(int id) : NodoGrafo(id) {}

NodoDirectorio::~NodoDirectorio() {}

bool NodoDirectorio::es_directorio() {return true;}

int* NodoDirectorio::lista_padres(){return nullptr;}