#include "ArbolBPlus.h"

#include <functional>

ArbolBPlus::ArbolBPlus(int orden) {
    this -> raiz = nullptr;
    this -> orden = orden;
    this -> maximoClaves = orden - 1;
    this -> contadorAccesos = 0;
}

ArbolBPlus::~ArbolBPlus() {delete raiz;}

int ArbolBPlus::getContadorAccesos() {return contadorAccesos;}

NodoBHoja* ArbolBPlus::encontrarHoja(int clave) {
    if (raiz == nullptr) {return nullptr;}

    NodoBPlusBase* actual = raiz;
    contadorAccesos++;

    while (!actual -> esHoja()) {
        NodoBInterno* interno = (NodoBInterno*) actual;
        int indx = interno -> buscarSiguiente(clave);
        actual = interno -> getPuntero(indx);

        contadorAccesos++;
    }
    return (NodoBHoja*) actual;
}

void ArbolBPlus::dividirHoja(NodoBHoja* hoja) {
    int total = hoja -> getNumeroClaves();
    int mitad = total / 2;

    NodoBHoja* nueva = new NodoBHoja(orden);
    hoja -> moverRango(mitad,total, nueva);
    nueva -> setSiguienteHoja(hoja -> getSiguienteHoja());
    hoja -> setSiguienteHoja(nueva);

    int clavePromovida = nueva -> getClave(0);
    insertarEnPadre(hoja, clavePromovida, nueva);
}

void ArbolBPlus::insertarEnPadre(NodoBPlusBase* izquierda, int clave, NodoBPlusBase* derecha) {
    if (izquierda == raiz) {
        NodoBInterno* nuevaRaiz = new NodoBInterno(orden);

        nuevaRaiz -> setPuntero(0, izquierda);
        nuevaRaiz -> setPuntero(1, derecha);
        nuevaRaiz -> setNumeroPunteros(2);

        nuevaRaiz -> setClave(0, clave);
        nuevaRaiz -> setNumeroClaves(1);

        raiz = nuevaRaiz;
    }

    NodoBPlusBase* actual = raiz;
    NodoBInterno* padre = nullptr;

    while (!actual -> esHoja()) {
        NodoBInterno* interno = (NodoBInterno*) actual;

        for (int i = 0; i < interno -> getNumeroPunteros(); i++) {
            if (interno -> getPuntero(i) == izquierda) {
                padre = interno;
                break;
            }
        }
        if (padre != nullptr) {
            int indx = interno -> buscarSiguiente(clave);
            actual = interno -> getPuntero(indx);
        }
    }

    if (padre == nullptr) {
        NodoBInterno* nuevaRaiz = new NodoBInterno(orden);

        nuevaRaiz -> setPuntero(0, izquierda);
        nuevaRaiz -> setPuntero(1, derecha);
        nuevaRaiz -> setNumeroPunteros(2);

        nuevaRaiz -> setClave(0, clave);
        nuevaRaiz -> setNumeroClaves(1);

        raiz = nuevaRaiz;
        return;
    }

    if (padre -> getNumeroClaves() < maximoClaves) {
        padre -> insertarEnInterno(clave, derecha);
        return;
    }

    padre -> insertarEnInterno(clave, derecha);

    if (padre -> getNumeroClaves() > maximoClaves) {
        dividirInterno(padre);
    }
}

void ArbolBPlus::dividirInterno(NodoBInterno* nodo) {
    int total = nodo -> getNumeroClaves();
    int mitad = total / 2;

    int clave = nodo -> getClave(mitad);
    NodoBInterno* nuevo = new NodoBInterno(orden);
    int indxNuevo = 0;

    for (int i = mitad + 1; i < total; i++) {
        nuevo -> setClave(indxNuevo, nodo -> getClave(i));
        indxNuevo++;
    }

    nuevo -> setNumeroClaves(indxNuevo);

    int total2 = nodo -> getNumeroPunteros();
    int inicioPtr = mitad + 1;
    int indxNuevo2 = 0;

    for (int j = inicioPtr; j < total2; j++) {
        nuevo -> setPuntero(indxNuevo2, nodo -> getPuntero(j));
        indxNuevo2++;
    }

    nuevo -> setNumeroPunteros(indxNuevo2);

    nodo -> setNumeroClaves(mitad);
    nodo -> setNumeroPunteros(mitad + 1);

    insertarEnPadre(nodo, clave, nuevo);
}

void ArbolBPlus::insertar_nodo_grafo(int clave, NodoGrafo* nodo_grafo) {
    if (raiz == nullptr) {
        NodoBHoja* hoja = new NodoBHoja(orden);
        hoja -> insertarEnHoja(clave, nodo_grafo);
        raiz = hoja;
        return;
    }

    NodoBHoja* hoja = encontrarHoja(clave);
    if (!hoja) {return;}

    hoja -> insertarEnHoja(clave, nodo_grafo);

    if (hoja -> getNumeroClaves() > maximoClaves) {
        dividirHoja(hoja);
    }
}

NodoGrafo* ArbolBPlus::buscar_nodo_grafo(int clave) {
    contadorAccesos++;

    NodoBHoja* hoja = encontrarHoja(clave);
    if (!hoja) {return nullptr;}

    for (int i = 0; i < hoja -> getNumeroClaves(); i++) {
        if (hoja -> getClave(i) == clave) {
            return hoja -> getDato(i);
        }
    }
    return nullptr;
}