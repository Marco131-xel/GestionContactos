#include <iostream>
#include "Grupo.h"

using namespace std;
// Constructor Grupo
Grupo::Grupo(string nombre) {
    this->nombre = nombre;
    this->contenido = nullptr;
}

// Metodo para agregar un nuevo nodo ala lista
void Grupo::agregarCampo(string nombre, string tipo) {
    Nodo* nuevo_nodo = new Nodo(nombre,tipo);
    if (contenido == nullptr){
        contenido = nuevo_nodo;
    } else {
        Nodo* actual = contenido;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }
}

void Grupo::agregarContacto(string contacto) {
    contactos.push_back(contacto);
    cout<<"Nuevo Contacto agrega al Grupo "<<nombre<<": "<<contacto<<endl;
}

void Grupo::buscarContacto(const string& campo) const {
    list<string> contactosEncontrados;
    for (const auto& contacto : contactos) {
        if (contacto == campo) {
            contactosEncontrados.push_back(contacto);
        }
    }

    // Mostrar resultados
    if (!contactosEncontrados.empty()) {
        cout<<"Contactos encontrados en el campo "<<campo<<":"<<endl;
        for (const auto& contacto : contactosEncontrados) {
            cout<<contacto<<endl;
        }
    } else {
        cout<<"No se encontraron contactos con el dato "<<campo<<endl;
    }
}

// Destructor
Grupo::~Grupo() {
    Nodo* actual = contenido;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}