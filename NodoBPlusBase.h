#pragma once

class NodoBPlusBase {
protected:
    int orden;
    bool es_hoja;
    int* claves;

public:
    NodoBPlusBase(int orden);
    virtual ~NodoBPlusBase();
    bool esHoja();
};