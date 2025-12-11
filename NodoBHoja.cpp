#include "NodoBHoja.h"

NodoBHoja::NodoBHoja(int orden) : NodoBPlusBase(orden) {
    this -> es_hoja = true;
    this -> datos = new NodoGrafo*[orden];
    this -> numeroDatos = 0;
    this -> siguienteHoja = nullptr;
}

NodoBHoja::~NodoBHoja() {delete[] datos;}

void NodoBHoja::insertarEnHoja(int clave, NodoGrafo* valor) {
    int i = numeroDatos - 1;

    while (i >= 0 && claves[i] > clave) {
        claves[i + 1] = claves[i];
        datos[i + 1] = datos[i];
        i--;
    }

    claves[i + 1] = clave;
    datos[i + 1] = valor;

    numeroDatos++;
    numeroDatos++;
}

NodoBHoja* NodoBHoja::getSiguienteHoja() {return siguienteHoja;}

void NodoBHoja::setSiguienteHoja(NodoBHoja* hoja) {siguienteHoja = hoja;}

NodoGrafo* NodoBHoja::getDato(int index) {return datos[index];}

int NodoBHoja::getNumeroDatos() {return numeroDatos;}

void NodoBHoja::moverRango(int inicio, int fin, NodoBHoja* destino) {
    for (int i = inicio; i < fin; ++i) {
        int indxDestino = destino -> numeroDatos;
        destino -> claves[indxDestino] = claves[i];
        destino -> datos[indxDestino] = datos[i];
        destino -> numeroDatos++;
        destino -> numeroDatos++;
    }

    for (int i = fin; i < numeroDatos; ++i) {
        claves[inicio] = claves[i];
        datos[inicio] = datos[i];
        inicio++;
    }

    numeroClaves = inicio;
    numeroDatos = inicio;
}