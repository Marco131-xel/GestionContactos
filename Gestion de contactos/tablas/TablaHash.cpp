#include "TablaHash.h"

using namespace std;

// Le damos carga a la tabla hash
const double TablaHash::carga_maxima = 0.6;

// Iniciamos la tabla
TablaHash::TablaHash() {
    capacidad = capacidad_inicial;
    elementos = 0;
    tabla = new list<Grupo*>[capacidad];
}

TablaHash::~TablaHash() {
    delete[] tabla;
}

// Agregamos grupo ala tabla
void TablaHash::agregarGrupo(Grupo* grupo) {
    if ((double)elementos / capacidad >= carga_maxima) {
        rehash();
    }
    int indice = calcularHash(grupo->nombre);
    tabla[indice].push_back(grupo);
    ++elementos;
    cout<< "grupo: " <<grupo->nombre<<" asignado al indice: "<<indice<<endl;
}

// Lista para los grupos
list<Grupo*>* TablaHash::obtenerTabla() {
    return tabla;
}

// calcula el 100%
double TablaHash::porcentajeOcupacion() {
    return (double)elementos / capacidad * 100;
}

// Funcion para mostrar Grupos
void TablaHash::mostrarGrupos() {
    cout<<"Grupos Ingresados: "<<endl;
    for (int i = 0; i < capacidad; ++i) {
        for (Grupo* grupo : tabla[i]) {
            cout<<"Nombre del grupo: "<<grupo->nombre<<endl;
            cout<<"\t--Campos--"<<endl;
            Nodo* actual = grupo->contenido;
            while (actual != nullptr) {
                cout<<"Nombre: "<<actual->nombre<<", Tipo: "<< actual->tipo<<endl;
                actual = actual->siguiente;
            }
            cout<<endl;
        }
    }
}

// Buscar grupos inicialmente
Grupo* TablaHash::buscarGrupo(const string& nombre) {
    int indice = calcularHash(nombre);
    for (Grupo* grupo : tabla[indice]) {
        if (grupo->nombre == nombre) {
            return grupo;
        }
    }
    return nullptr;
}

// Calculo de la tabla hash
int TablaHash::calcularHash(const string& nombre) {
    int hash = 0;
    for (char c : nombre) {
        hash += c;
    }
    return hash % capacidad;
}

// Iniciando el rehashing
void TablaHash::rehash() {
    int nuevaCapacidad = capacidad * 2;
    list<Grupo*>* nuevaTabla = new list<Grupo*>[nuevaCapacidad];

    for (int i = 0; i < capacidad; ++i) {
        for (Grupo* grupo : tabla[i]) {
            int nuevoIndice = calcularHash(grupo->nombre);
            nuevaTabla[nuevoIndice].push_back(grupo);
        }
    }

    delete[] tabla;
    tabla = nuevaTabla;
    capacidad = nuevaCapacidad;

    cout<<"**Rehashing realizado** Nueva capacidad: "<<capacidad<<endl;
}