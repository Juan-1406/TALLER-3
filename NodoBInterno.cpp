#include "NodoBInterno.h"

NodoBInterno::NodoBInterno(int orden) : NodoBPlusBase(orden, false){
    this -> punteros = nullptr;
}

NodoBInterno::~NodoBInterno() {delete[] punteros;}

int NodoBInterno::buscar_siguiente() {
    return 0;
}