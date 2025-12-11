#include "NodoBPlusBase.h"

NodoBPlusBase::NodoBPlusBase(int orden) {
    this -> orden = orden;
    this -> claves = new int[orden];
    this -> numeroClaves = 0;
    this -> es_hoja = false;
}

NodoBPlusBase::~NodoBPlusBase() {delete[] claves;}

bool NodoBPlusBase::esHoja() {return es_hoja;}

int NodoBPlusBase::getNumeroClaves() {return numeroClaves;}

int NodoBPlusBase::getClave(int indx) {return claves[indx];}

void NodoBPlusBase::setClave(int indx, int val) {claves[indx] = val;}