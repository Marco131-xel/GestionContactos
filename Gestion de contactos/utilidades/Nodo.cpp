#include "Nodo.h"

using namespace std;

// Los siguientes del nodo
Nodo::Nodo(string nombre, string tipo) {
    this->nombre = nombre;
    this->tipo = tipo;
    this->siguiente = nullptr;
}