#include "NodoDirectorio.h"

NodoDirectorio::NodoDirectorio(int id) : NodoGrafo(id) {
    this -> hijos = new int[2];
    this -> totalPadres = 0;
    this -> capacidadPadres = 2;
}

NodoDirectorio::~NodoDirectorio() {delete[] hijos;}

bool NodoDirectorio::es_directorio() {return true;}

int* NodoDirectorio::lista_hijos(){return hijos;}

int NodoDirectorio::getTotalHijos(){return totalHijos;}

void NodoDirectorio::agregarHijo(int idHijo) {
    if (totalHijos == capacidadPadres) {
        int nuevaCapacidad = capacidadHijos * 2;
        int* nuevo = new int[nuevaCapacidad];

        for (int i = 0; i < nuevaCapacidad; i++) {
            nuevo[i] = hijos[i];
        }

        delete[] hijos;
        hijos = nuevo;
        capacidadHijos = nuevaCapacidad;
    }

    hijos[totalHijos] = idHijo;
    totalHijos++;
}

void NodoDirectorio::eliminarHijo(int idHijo) {
    int index = -1;

    for (int i = 0; i < totalHijos; i++) {
        if (hijos[i] == idHijo) {
            index = i;
            break;
        }
    }

    if (index == -1) {return;}

    for (int j = index; j < totalHijos - 1; j++) {
        hijos[j] = hijos[j + 1];
    }

    totalHijos--;
}