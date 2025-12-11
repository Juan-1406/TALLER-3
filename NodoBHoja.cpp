#include "NodoBHoja.h"

NodoBHoja::NodoBHoja(int orden) : NodoBPlusBase(orden, true) {
    this -> datos = nullptr;
    this -> siguiente_hoja = nullptr;
}

NodoBHoja::~NodoBHoja() {delete[] datos;}