#include "NodoBPlusBase.h"

NodoBPlusBase::NodoBPlusBase(int orden) {
    this -> orden = orden;
    this -> claves = new int[orden];
    this -> numeroClaves = 0;
    this -> es_hoja = false;
}

NodoBPlusBase::~NodoBPlusBase() {delete[] claves;}