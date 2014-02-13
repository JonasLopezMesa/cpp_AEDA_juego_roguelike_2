//
//  Objetos.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Objetos.h"

Objetos::Objetos(int l, int b, int a){
    largo = l;
    beneficio = b;
    aumento_fuerza = a;
}
int Objetos::get_posicion(){
    return pos.y*largo+pos.x;
}
char Objetos::get_simbolo(){
    return simbolo;
}
int Objetos::get_habitacion_actual(){
    return habitacion_actual;
}
int Objetos::get_largo(){
    return largo;
}
int Objetos::get_beneficio(){
    return beneficio;
}
int Objetos::get_aumento_fuerza(){
    return aumento_fuerza;
}


void Objetos::set_posicion(int x, int y){
    pos.x = x;
    pos.y = y;
}
void Objetos::set_simbolo(char s){
    simbolo = s;
}
void Objetos::set_habitacion_actual(int h){
    habitacion_actual = h;
}
void Objetos::set_beneficio(int b){
    beneficio = b;
}
void Objetos::set_aumento_fuerza(int a){
    aumento_fuerza = a;
}