#pragma once
#include "NodoBPlusBase.h"

class NodoBInterno : public NodoBPlusBase {
private:
    NodoBPlusBase** punteros;
        int numeroPunteros;
public:
    NodoBInterno(int orden);
    ~NodoBInterno();

    int buscarSiguiente(int clave);
    void insertarEnInterno(int clave, NodoBPlusBase* hijoDerecho);
};