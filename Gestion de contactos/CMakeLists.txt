cmake_minimum_required(VERSION 3.27)
project(Gestion_de_contactos)

set(CMAKE_CXX_STANDARD 17)

add_executable(Gestion_de_contactos main.cpp
        campos/Campo.h
        campos/Campo.cpp
        grupos/Grupo.h
        utilidades/Nodo.h
        utilidades/Nodo.cpp
        grupos/Grupo.cpp
        tablas/TablaHash.h
        tablas/TablaHash.cpp
        tablahash/TablaHash_Campos.h
        tablahash/TablaHash_Campos.cpp)
