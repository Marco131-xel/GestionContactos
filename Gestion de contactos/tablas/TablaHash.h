#ifndef GESTION_DE_CONTACTOS_TABLAHASH_H
#define GESTION_DE_CONTACTOS_TABLAHASH_H

#include <list>
#include <string>
#include <iostream>
#include "../grupos/Grupo.h"

using namespace std;

class TablaHash {
private:
    static const double carga_maxima;
    list<Grupo*>* tabla;
    int capacidad;
    int elementos;

    int calcularHash(const string& nombre);
    void rehash();

public:
    TablaHash();
    ~TablaHash();

    void agregarGrupo(Grupo* grupo);
    list<Grupo*>* obtenerTabla();
    double porcentajeOcupacion();
    void mostrarGrupos();
    Grupo* buscarGrupo(const string& nombre);

    static const int capacidad_inicial = 5;
};

#endif //GESTION_DE_CONTACTOS_TABLAHASH_H
