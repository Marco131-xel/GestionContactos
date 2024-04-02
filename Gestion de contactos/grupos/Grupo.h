#ifndef GESTION_DE_CONTACTOS_GRUPO_H
#define GESTION_DE_CONTACTOS_GRUPO_H

#include <string>
#include <list>
#include "..//utilidades/Nodo.h"

using namespace std;

// Clase para grupo
class Grupo{
public:
    string nombre;
    Nodo* contenido;
    Grupo();
    Grupo(string nombre);
    void agregarCampo(string nombre, string tipo);
    void agregarContacto(string contacto);
    void buscarContacto(const string& campo) const;
    // agregar hash a mi grupo
    ~Grupo();

private:
    list<string> contactos;
};
#endif //GESTION_DE_CONTACTOS_GRUPO_H
