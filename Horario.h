//
// Created by Moran on 7/29/2022.
//
// TODO Redefine Horario and eliminate the need to use a vector of vector of classes to store the final versions of the schedules
// TODO change the implementation of puntuacion (void imprimir and limpiarcopias)
#include <string.h>
#include "Clase.h"
using namespace std;

#ifndef HORARIO_HORARIO_H
#define HORARIO_HORARIO_H

class Horario{
public:
    Horario();
    void agregarClase(const Clase&);
    vector<vector<Clase>> generatePossibleComb();
    void recursive(int depth);
    static void imprimir(const vector<vector<Clase>>& final);
private:
    bool matriz[7][28]={false};
    vector<vector<bool>> mem;
    vector<Grupo> memclas;
    vector<Clase> clases;
    vector<Clase> organizer;
    vector<vector<Clase>> resultado;
    void limpiarCopias();
};

#endif //HORARIO_HORARIO_H
