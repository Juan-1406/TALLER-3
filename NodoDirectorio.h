#pragma once
#include "NodoGrafo.h"

class NodoDirectorio : public NodoGrafo
{
private:
    int* hijos;
    int totalHijos;
    int capacidadHijos;

public:
    NodoDirectorio(int id);
    ~NodoDirectorio();

    bool es_directorio();

    int* lista_hijos();
    int getTotalHijos();

    void agregarHijo(int idHijo);
    void eliminarHijo(int idHijo);
};
