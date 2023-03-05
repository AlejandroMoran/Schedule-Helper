//
// Created by Moran on 7/29/2022.
//

#include "Grupo.h"
#include <iostream>
#include <utility>

Grupo::Grupo(int numero, string profesor, const int hora_inicio[7] , const int duracion[7], double puntuacion) {
    this->numero=numero;
    this->profesor=std::move(profesor);
    for(int i=0; i<7;i++){
        this->hora_inicio[i]=hora_inicio[i];
        this->duracion[i]=duracion[i];
    }
    this->puntuacion=puntuacion;
}

void Grupo::Imprimir() {
    string dias[7]={"Lunes","Martes","Miercoles","Jueves","Viernes", "Sabado","Domingo"};
    std::cout << "Grupo numero:"<< numero << std::endl;
    std::cout << "profesor:" << profesor << std::endl;
    std::cout << "Puntuacion:" << puntuacion << std::endl;
    for(int i=0; i<7;i++) {
        if(hora_inicio[i]!=INT16_MAX)
            std::cout << dias[i] << " de " << hora_inicio[i]+7 << " a "<<(hora_inicio[i]+duracion[i]+7) << std::endl;
    }
    std::cout << std::endl;
}

Grupo::~Grupo() = default;

int Grupo::getNumero() const {
    return numero;
}

void Grupo::setNumero(int numero) {
    Grupo::numero = numero;
}

const string &Grupo::getProfesor() const {
    return profesor;
}

void Grupo::setProfesor(const string &profesor) {
    Grupo::profesor = profesor;
}

const int *Grupo::getHoraInicio() const {
    return hora_inicio;
}

const int *Grupo::getDuracion() const {
    return duracion;
}

double Grupo::getPuntuacion() const {
    return puntuacion;
}

void Grupo::setPuntuacion(double puntuacion) {
    Grupo::puntuacion = puntuacion;
}

int Grupo::getCupo() const {
    return cupo;
}

void Grupo::setCupo(int cupo) {
    Grupo::cupo = cupo;
}
