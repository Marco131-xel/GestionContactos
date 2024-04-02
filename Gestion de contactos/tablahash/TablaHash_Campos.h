#ifndef GESTION_DE_CONTACTOS_TABLAHASH_CAMPOS_H
#define GESTION_DE_CONTACTOS_TABLAHASH_CAMPOS_H

#include <vector>
#include "../campos/Campo.h"

using namespace std;

// Clase para unir tabla con con los campos
class TablaHashCampos {
private:
    static const int capacidad = 5;
    vector<vector<Campo>> tabla;
    int elementos;

    size_t hash(string nombre) const;
    void rehash();

public:
    TablaHashCampos();
    void agregarCampo(string nombre, string tipo);
    bool buscarCampo(string nombre, string tipo) const;
};
#endif //GESTION_DE_CONTACTOS_TABLAHASH_CAMPOS_H
