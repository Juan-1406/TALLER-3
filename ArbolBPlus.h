#pragma once

#include "NodoBPlusBase.h"
#include "NodoBHoja.h"
#include "NodoGrafo.h"
#include "NodoBInterno.h"

class ArbolBPlus {
private:
    NodoBPlusBase* raiz;
    int orden;
    int maximoClaves;
    int contadorAccesos;

    NodoBHoja* encontrarHoja(int clave);
    void dividirHoja(NodoBHoja* hoja);
    void insertarEnPadre(NodoBPlusBase* izquierda, int clave, NodoBPlusBase* derecha);
    void dividirInterno(NodoBInterno* nodo);

public:
    ArbolBPlus(int orden);
    ~ArbolBPlus();

    void insertar_nodo_grafo(int clave, NodoGrafo* nodo_grafo);
    NodoGrafo* buscar_nodo_grafo(int clave);
    int getContadorAccesos();
};

