#pragma once
#include "NodoBPlusBase.h"
#include "NodoGrafo.h"

class NodoBHoja : public NodoBPlusBase {
private:
    NodoGrafo** datos;
    NodoBHoja* siguiente_hoja;
public:
    NodoBHoja(int orden);
    ~NodoBHoja();
};