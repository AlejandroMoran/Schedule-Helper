//
// Created by Moran on 7/29/2022.
//
#include <vector>
#include <string>
#include "Grupo.h"
using namespace std;

#ifndef HORARIO_CLASE_H
#define HORARIO_CLASE_H


class Clase {
public:
    Clase(int clave, string nombre);
    void imprimir();
    void Agregar_grupo(Grupo);

    const string &getNombre() const;

    int getClave() const;

    vector<Grupo> grupos;
private:
    int clave;
    string nombre;
};


#endif //HORARIO_CLASE_H
