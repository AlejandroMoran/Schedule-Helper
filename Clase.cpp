//
// Created by Moran on 7/29/2022.
//

#include "Clase.h"

Clase::Clase(int clave, string nombre){
    this->clave=clave;
    this-> nombre=nombre;
}

void Clase::Agregar_grupo(Grupo nuevo) {
    grupos.push_back(nuevo);
}
void Clase::imprimir() {
    for(Grupo i: grupos){
        i.Imprimir();
    }
}

const string &Clase::getNombre() const {
    return nombre;
}

int Clase::getClave() const {
    return clave;
}
