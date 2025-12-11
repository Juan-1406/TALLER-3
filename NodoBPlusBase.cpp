#include "NodoBPlusBase.h"

NodoBPlusBase::NodoBPlusBase(int ord, bool hoja) {
    this -> es_hoja = hoja;
    this -> orden = ord;
    this -> claves = nullptr;
}

NodoBPlusBase::~NodoBPlusBase() {delete[] claves;}