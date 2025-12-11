#pragma once
#include "NodoBPlusBase.h"

class NodoBInterno : public NodoBPlusBase {
private:
    NodoBPlusBase** punteros;
public:
    NodoBInterno(int orden);
    ~NodoBInterno();

    int buscar_siguiente();
};