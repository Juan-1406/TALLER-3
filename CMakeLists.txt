cmake_minimum_required(VERSION 4.0)
project(TALLER_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(TALLER_3 main.cpp
        NodoGrafo.cpp
        NodoGrafo.h
        NodoDirectorio.cpp
        NodoDirectorio.h
        NodoArchivo.cpp
        NodoArchivo.h
        NodoBPlusBase.cpp
        NodoBPlusBase.h
        NodoBInterno.cpp
        NodoBInterno.h
        NodoBHoja.cpp
        NodoBHoja.h
        ArbolBPlus.cpp
        ArbolBPlus.h
        Sistema.cpp
        Sistema.h
)
