#pragma once

class NodoBPlusBase {
protected:
    int* claves;
    int orden;
    bool es_hoja;
    int numeroClaves;

public:
    NodoBPlusBase(int orden);
    virtual ~NodoBPlusBase();
    bool esHoja();
};