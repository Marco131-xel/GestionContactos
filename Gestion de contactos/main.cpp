#include <iostream>
#include <regex>
#include "grupos/Grupo.h"
#include "tablas/TablaHash.h"
#include "tablahash/TablaHash_Campos.h"

using namespace std;

int main() {
    // Expresiones regulares
    regex nuevoGrupo("ADD NEW-GROUP (\\w+) FIELDS \\((.*)\\);");
    regex nuevoContacto(R"(ADD CONTACT IN (\w+) FIELDS \(([\w, -]+)\);)");
    regex buscarContacto(R"(FIND\s+CONTACT\s+IN\s+(\w+)\s+CONTACT-FIELD\s+(\w+)=(\w+);)");

    // Tabla hash para almacenar grupos
    TablaHash tabla;
    // Tabla hash para campos
    TablaHashCampos tablaCampos;

    // Variables para entrada del usuario
    string input;
    char opcion;
    bool continuar = true;
    // Ciclo para ingresar entradas del usuario
    while (continuar) {
        cout<<"\n\t *MENU*"<<endl;
        cout<<"1. Terminal"<<endl;
        cout<<"2. Reportes"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        switch (opcion) {
            case '1': {
                cout << "Terminal M4" << endl;
                cout << "M4> ";
                cin.ignore();
                getline(cin, input);

                // Verificar la entrada del usuario
                // Si la entrada coincide con alguna expresión regular, ejecutar la acción correspondiente
                if (regex_match(input, nuevoGrupo)) {
                    // Procesar nuevo grupo
                    smatch matches;
                    if (regex_match(input, matches, nuevoGrupo)) {
                        Grupo *nuevo_grupo = new Grupo(matches[1].str());

                        // Parsear campos
                        string campos_str = matches[2].str();
                        regex campo_regex("([\\w-]+)\\s+(STRING|INTEGER|CHAR)");
                        auto campos_begin = sregex_iterator(campos_str.begin(), campos_str.end(), campo_regex);
                        auto campos_end = sregex_iterator();
                        for (sregex_iterator i = campos_begin; i != campos_end; ++i) {
                            string nombre = (*i)[1].str();
                            string tipo = (*i)[2].str();
                            nuevo_grupo->agregarCampo(nombre, tipo);
                            tablaCampos.agregarCampo(nombre, tipo);
                        }

                        // Agregar nuevo grupo a la tabla hash
                        tabla.agregarGrupo(nuevo_grupo);
                        cout<<"Porcentaje usado en la tablahash por grupos: "<<tabla.porcentajeOcupacion()<<"%"<<endl;
                    } else {
                        cout<<"Entrada no valida."<<endl;
                    }
                } else if (regex_match(input, nuevoContacto)) {
                    // Procesar nuevo contacto
                    smatch matches;
                    if (regex_match(input, matches, nuevoContacto)) {
                        string nombreGrupo = matches[1].str();
                        string nuevoContacto = matches[2].str();

                        // Buscar el grupo correspondiente en la tabla hash
                        Grupo *grupo = tabla.buscarGrupo(nombreGrupo);

                        // Verificar si se encontró el grupo
                        if (grupo != nullptr) {
                            // Agregar el nuevo contacto al grupo
                            grupo->agregarContacto(nuevoContacto);
                        } else {
                            cout<<"El grupo: "<< nombreGrupo <<" no existe" << endl;
                        }
                    } else {
                        cout<<"Entrada no valida."<<endl;
                    }
                } else if (regex_match(input, buscarContacto)) {
                    // Procesar búsqueda de contacto
                    smatch matches;
                    if (regex_match(input, matches, buscarContacto)) {
                        string nombreGrupo = matches[1].str();
                        string campo = matches[2].str();

                        // Buscar el grupo correspondiente en la tabla hash
                        Grupo *grupo = tabla.buscarGrupo(nombreGrupo);

                        // Verificar si se encontró el grupo
                        if (grupo != nullptr) {
                            // Buscar contactos en el campo especificado
                            grupo->buscarContacto(campo);
                        } else {
                            cout<<"El grupo: "<<nombreGrupo<<" no existe"<<endl;
                        }
                    } else {
                        cout<<"Entrada no valida."<<endl;
                    }
                } else {
                    cout << "Comando no reconocido." << endl;
                }
                break;
            }
            case '2': {
                tabla.mostrarGrupos();
                break;
            }
            case '3': {
                continuar = false;
                // Liberar la memoria asignada a los grupos
                for (int i = 0; i < TablaHash::capacidad_inicial; ++i) {
                    for (Grupo *grupo: *tabla.obtenerTabla()) {
                        delete grupo;
                    }
                }
            }
            default:
                cout<<"Opcion no valida"<<endl;
        }
    }
    return 0;
}
