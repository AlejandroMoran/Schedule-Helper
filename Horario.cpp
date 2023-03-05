//
// Created by Moran on 7/29/2022.
// TODO Redefine Horario and eliminate the need to use a vector of vector of classes to store the final versions of the schedules
// TODO change the implementation of puntuacion (void imprimir and limpiarcopias)

#include "Horario.h"
#include <iostream>
#include <algorithm>

Horario::Horario() = default;
void Horario::recursive(int depth){
    if(depth<=clases.size()-1){
        for(auto & grupo : clases[depth].grupos){
            vector<bool> memo (196);
            for( int x=0;x<7;x++) {
                if (grupo.hora_inicio[x] != INT16_MAX){
                    for(int z=0;z<(grupo.duracion[x])*2;z++){
                        memo[(x*28)+((grupo.hora_inicio[x])*2)+z]=true;
                    }
                }
            }
            mem.push_back(memo);
            memclas.push_back(grupo);
            memo.clear();
            recursive(depth+1);
        }
    }
    int flag=0;
    if(mem.size()==clases.size()){
        for(auto i : mem){
            for(int x=0;x<i.size(); x++) {
                if (i[x] && flag != 1) {
                    int y=0;
                    int z=x;
                    if(x>27){
                        y=x/28;
                        z=x-(y*28);
                    }
                    if (!matriz[y][z])
                        matriz[y][z] = true;
                    else{
                        flag=1;
                        break;
                    }
                }
            }
        }
        //printf("Clases y grupos del horario:\n");
        //for (int x = 0; x < mem.size(); x++) {
            //cout << "Clase: "<< clases[x].getNombre();
            //printf(" , grupo: %d\n", memclas[x].getNumero());
        //}
        if(flag==1){
            //printf("Conflicto de horario \n");
            flag=0;
        }
        else {
            //printf("Exitoso");
            vector<Clase> horariotemp;
            for(int x=0;x<mem.size();x++){
                Clase classtemp(clases[x].getClave(),clases[x].getNombre());
                classtemp.Agregar_grupo(memclas[x]);
                horariotemp.push_back(classtemp);
            }
            resultado.push_back(horariotemp);
            //for (int x = 0; x < 28; x++) {
                //for (auto & y : matriz)
                    //printf("%d ", y[x]);
               // printf("\n");
            //}
        }
        memset(matriz,false,sizeof(matriz));

        //printf("\n");
    }
    if(!mem.empty()){
        mem.pop_back();
        memclas.pop_back();
    }

}
 vector<vector<Clase>> Horario::generatePossibleComb() {
    vector<int> permutations;
    permutations.reserve(organizer.size());
    for(int x=0;x<organizer.size();x++)
        permutations.push_back(x);
    do{
        for(auto i:permutations){
            //printf("%d ",i);
            clases.push_back(organizer[i]);
        }
        //printf("\n");
        recursive(0);
        clases.clear();

    }while(next_permutation(permutations.begin(), permutations.end()));
    //printf("Combinaciones con copias: %d\n",resultado.size());
    limpiarCopias();
    //printf("Combinaciones sin copias: %d\n",resultado.size());
    return resultado;
 }
void Horario::agregarClase(const Clase& nuevaClase) {
    organizer.push_back(nuevaClase);
}

void Horario::limpiarCopias() {
    bool flag=false;
    vector<vector<Clase>> resultadotemp;
    vector<vector<int>> horas;
    for(auto & x : resultado){
        vector<int> horastemp(196);
        for(auto clase:x){
            for( int y=0;y<7;y++) {
                if (clase.grupos[0].hora_inicio[y] != INT16_MAX){
                    for(int z=0;z<(clase.grupos[0].duracion[y])*2;z++){
                        string s1 = to_string(clase.getClave());
                        string s2 = to_string(clase.grupos[0].getNumero());
                        string s = s1 + s2;
                        int c = stoi(s);
                        horastemp[(y*28)+((clase.grupos[0].hora_inicio[y])*2)+z]=c;
                    }
                }
            }
        }
        for(const auto& i:horas) {
            if (i == horastemp)
                flag = true;
        }
        if(!flag) {
            horas.push_back(horastemp);
            resultadotemp.push_back(x);
        }
        horastemp.clear();
    }
    resultado=resultadotemp;
}

void Horario::imprimir(const vector<vector<Clase>>& final) {
    double temporal=0;
    for(int i=0;i<final.size();i++){
        printf("Opcion:%d \n",i+1);
        for(auto clase: final[i]) {
            cout << "Clase: "<< clase.getNombre()<< " " << clase.getClave() <<endl;
            clase.grupos[0].Imprimir();
            temporal+=clase.grupos[0].getPuntuacion();
        }
        printf("Puntuacion promedio: %.1f\n\n",temporal/final[0].size());
        temporal=0;
    }

}
