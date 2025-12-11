#pragma once

class NodoGrafo {

private:
    int id;
public:

    NodoGrafo(int id);
    virtual ~NodoGrafo();

    virtual bool es_directorio();
    virtual int* lista_padres();
};