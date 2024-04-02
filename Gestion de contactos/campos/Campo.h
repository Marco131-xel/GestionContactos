#ifndef GESTION_DE_CONTACTOS_CAMPO_H
#define GESTION_DE_CONTACTOS_CAMPO_H

#include <string>

using namespace std;

// Clase para crear campos
class Campo{
public:
    string nombre;
    string tipo;

    Campo(string nombre, string tipo);
    size_t hashCampo() const;
};

#endif //GESTION_DE_CONTACTOS_CAMPO_H
