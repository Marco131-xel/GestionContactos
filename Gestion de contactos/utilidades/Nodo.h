#ifndef GESTION_DE_CONTACTOS_NODO_H
#define GESTION_DE_CONTACTOS_NODO_H

#include <string>

using namespace std;

// Clase para nodos
class Nodo{
public:
    string nombre;
    string tipo;
    Nodo* siguiente;

    Nodo(string nombre, string tipo);

};
#endif //GESTION_DE_CONTACTOS_NODO_H
