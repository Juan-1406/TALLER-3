#include "NodoBHoja.h"

NodoBHoja::NodoBHoja(int orden) : NodoBPlusBase(orden, true) {
    this -> siguiente = nullptr;

    int capacidadClaves = orden - 1;
    claves = new int[capacidadClaves];
    datos = new NodoGrafo*[capacidadClaves];

    for (int i = 0; i < capacidadClaves; i++) {
        claves[i]  = 0;
        datos[i] = nullptr;
    }

    numeroClaves = 0;
}

NodoBHoja::~NodoBHoja() {
    delete[] datos;
    delete[] claves;
}