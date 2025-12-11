#include "NodoGrafo.h"

NodoGrafo::NodoGrafo(int id) {
    this -> id = id;

    this -> padres = new int[2];
    this -> totalPadres = 0;
    this -> capacidadPadres = 2;
}

NodoGrafo::~NodoGrafo() {delete[] padres;}

int NodoGrafo::getId(){return id;}

bool NodoGrafo::es_directorio() {return false;}

int* NodoGrafo::lista_padres(){return padres;}

int NodoGrafo::getTotalPadres(){return totalPadres;}

void NodoGrafo::agregarPadre(int idPadre) {
    if (totalPadres == capacidadPadres) {
        int nuevaCapacidad = capacidadPadres * 2;
        int* nuevo = new int[nuevaCapacidad];

        for (int i = 0; i < totalPadres; i++) {
            nuevo[i] = padres[i];
        }

        delete[] padres;
        padres = nuevo;
        capacidadPadres = nuevaCapacidad;
    }
    padres[totalPadres] = idPadre;
    totalPadres++;
}

void NodoGrafo::eliminarPadre(int idPadre) {
    int index = -1;

    for (int i = 0; i < totalPadres; i++) {
        if (padres[i] == idPadre) {
            index = i;
            break;
        }
    }

    if (index == -1) {return;}

    for (int j = index; j < totalPadres - 1; j++) {
        padres[j] = padres[j + 1];
    }
    totalPadres--;
}
