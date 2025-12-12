#pragma once

class NodoGrafo {
protected:
    int id;

    int* padres;
    int totalPadres;
    int capacidadPadres;

    int* hijos;
    int numeroHijos;

public:

    NodoGrafo(int id);
    virtual ~NodoGrafo();

    int getId();
    virtual bool es_directorio();

    int* lista_padres();
    int getTotalPadres();
    void agregarPadre(int idPadre);
    void eliminarPadre(int idPadre);

    int* lista_hijos();
    int cantidadHijos();
    void agregarHIjo(int idHijo);
    void eliminarHijo(int idHijo);
};