#include "Campo.h"

using namespace std;

Campo::Campo(string nombre, string tipo) :
nombre(nombre), tipo(tipo){}

size_t Campo::hashCampo() const {
    // Funcion hash
    size_t hash = 0;
    // El nombre de los campos
    for (char c : nombre){
        hash += c;
    }
    // Tipos de campos
    for (char c : tipo){
        hash += c;
    }
    return hash;
}