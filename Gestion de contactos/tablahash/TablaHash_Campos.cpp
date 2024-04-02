#include "TablaHash_Campos.h"
#include <iostream>

using namespace std;
// Nuevos campos para la tabla
TablaHashCampos::TablaHashCampos() : elementos(0) {
    tabla.resize(capacidad);
}

size_t TablaHashCampos::hash(string nombre) const {
    size_t hash = 0;
    for (char c : nombre) {
        hash += c;
    }
    return hash % tabla.size();
}

void TablaHashCampos::rehash() {
    int nuevaCapacidad = tabla.size() * 2;
    vector<vector<Campo>>nuevaTabla(nuevaCapacidad);

    for (const auto& lista : tabla) {
        for (const auto& campo : lista) {
            size_t indice = hash(campo.nombre);
            nuevaTabla[indice].push_back(campo);
        }
    }

    tabla = move(nuevaTabla);
}

void TablaHashCampos::agregarCampo(string nombre, string tipo) {
    if (elementos >= capacidad * 0.6) {
        rehash();
    }

    Campo nuevoCampo(nombre, tipo);
    size_t indice = hash(nombre);
    tabla[indice].push_back(nuevoCampo);
    ++elementos;
    cout<<"Campo: "<<nombre<<" asignado al indice: "<<indice<<endl;
}

bool TablaHashCampos::buscarCampo(string nombre, string tipo) const {
    size_t indice = hash(nombre);
    for (const auto& campo : tabla[indice]) {
        if (campo.nombre == nombre && campo.tipo == tipo) {
            return true;
        }
    }
    return false;
}
