//
//  Personajes.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Personajes.h"


Personajes::Personajes(int l){
    largo = l;
}

int Personajes::get_posicion(){
    return pos.y*largo+pos.x;
}
int Personajes::get_vidas(){
    return vidas;
}
int Personajes::get_fuerza(){
    return Fuerza;
}
char Personajes::get_simbolo(){
    return simbolo;
}
int Personajes::get_habitacion_actual(){
    return habitacion_actual;
}
int Personajes::get_largo(){
    return largo;
}

void Personajes::set_posicion(int x, int y){
    pos.x = x;
    pos.y = y;
}
void Personajes::set_vidas(int v){
    vidas = v;
}
void Personajes::set_fuerza(int f){
    Fuerza = f;
}
void Personajes::set_simbolo(char s){
    simbolo = s;
}
void Personajes::set_habitacion_actual(int h){
    habitacion_actual = h;
}

int Personajes::lucha(int fuerza1, int fuerza2){
    if (fuerza1 <= fuerza2) {
        return 1;
    } else {
        return 0;
    }
}