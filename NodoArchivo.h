#pragma once
#include "NodoGrafo.h"

class NodoArchivo : NodoGrafo {
private:
    int tamaño;
    int tipo;
public:
    NodoArchivo(int id, int tamaño, int tipo);
    ~NodoArchivo();

    bool es_directorio();
};

