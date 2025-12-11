#pragma once
#include "NodoBPlusBase.h"
#include "NodoGrafo.h"

class NodoBHoja : public NodoBPlusBase {
public:
    NodoGrafo** datos;
    NodoBHoja* siguiente;
    int* claves;

    NodoBHoja(int orden);
    ~NodoBHoja();
};