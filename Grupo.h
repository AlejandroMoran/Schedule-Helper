//
// Created by Moran on 7/29/2022.
//
#include <string>
using namespace std;

#ifndef HORARIO_GRUPO_H
#define HORARIO_GRUPO_H


class Grupo {
public:
    Grupo(int numero,string profesor ,const int hora_inicio[7], const int duracion[7],double puntuacion);
    void Imprimir();

    int getNumero() const;

    void setNumero(int numero);

    const string &getProfesor() const;

    void setProfesor(const string &profesor);

    const int *getHoraInicio() const;

    const int *getDuracion() const;

    double getPuntuacion() const;

    void setPuntuacion(double puntuacion);

    int getCupo() const;

    void setCupo(int cupo);

    virtual ~Grupo();

    int hora_inicio[7]{};
    int duracion[7]{};
private:
    int numero;
    string profesor;
    double puntuacion;
    int cupo{};
};


#endif //HORARIO_GRUPO_H
