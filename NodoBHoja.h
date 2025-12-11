#pragma once
#include "NodoBPlusBase.h"
#include "NodoGrafo.h"

class NodoBHoja : public NodoBPlusBase {
private:
    NodoGrafo** datos;
    NodoBHoja* siguienteHoja;
    int numeroDatos;
public:
    NodoBHoja(int orden);
    ~NodoBHoja();

    void insertarEnHoja(int clave, NodoGrafo* valor);

    NodoBHoja* getSiguienteHoja();
    void setSiguienteHoja(NodoBHoja* hoja);
    NodoGrafo* getDato(int index);
    int getNumeroDatos();

    void moverRango(int inicio, int fin, NodoBHoja* destino);
};