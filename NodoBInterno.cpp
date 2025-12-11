#include "NodoBInterno.h"

NodoBInterno::NodoBInterno(int orden) : NodoBPlusBase(orden){
    this -> es_hoja = false;
    this -> punteros = new NodoBPlusBase*[orden + 1];
    this -> numeroPunteros = 0;
}

NodoBInterno::~NodoBInterno() {delete[] punteros;}

int NodoBInterno::buscarSiguiente(int clave) {
    int i = 0;

    while (i < numeroClaves && clave >= claves[i]) {
        i++;
    }
    return i;
}

void NodoBInterno::insertarEnInterno(int clave, NodoBPlusBase* hijoDerecho) {
    int i = numeroClaves - 1;

    while (i >= 0 && claves[i] > clave) {
        claves[i + 1] = claves[i];
        punteros[i + 2] = punteros[i + 1];
        i--;
    }

    claves[i + 1] = clave;
    punteros[i + 2] = hijoDerecho;

    numeroClaves++;
    numeroPunteros++;
}