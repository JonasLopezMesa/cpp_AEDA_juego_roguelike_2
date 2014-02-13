//
//  Amuleto.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Amuleto.h"

Amuleto::Amuleto(Mazmorra& m) : Objetos(m.get_largo(), 3, 0){
    int x,y,colocado=0;
    while (colocado == 0) {
        //for (int i = 0; i < 3; i++) {
            //if (habitacion == i) {
                x = m.get_habitacion(2).inicio.x+1+rand()%((m.get_habitacion(2).inicio.x+m.get_habitacion(2).largo-2)-(m.get_habitacion(2).inicio.x+1));
                y = m.get_habitacion(2).inicio.y+1+rand()%((m.get_habitacion(2).inicio.y+m.get_habitacion(2).alto-2)-(m.get_habitacion(2).inicio.y+1));
                if (m.get_vector_arquitectura(x, y) != '*' && m.get_vector_arquitectura(x, y) != '+' && m.get_vector_arquitectura(x, y) != '#' && m.get_vector_arquitectura(x, y) != 'X' && m.get_vector_personajes(x, y) != '@' && m.get_vector_personajes(x, y) != 'D' && m.get_vector_personajes(x, y) != 'T') {
                    colocado = 1;
                    set_habitacion_actual(2);
                    set_posicion(x, y);
                    m.set_vector_objetos(x, y, 'A');
                    encontrado = false;
                }
            //}
        //}
    }
}

bool Amuleto::get_encontrado(){
    return encontrado;
}

void Amuleto::set_encontrado(bool e){
    encontrado = e;
}

void Amuleto::controlar_personaje(Mazmorra& m, Protagonista& p){
    if (encontrado == false) {
        if (p.get_posicion() == get_posicion()) {
            encontrado = true;
            p.set_beneficio(p.get_beneficio()+get_beneficio());
            m.set_vector_objetos(get_posicion()%get_largo(), get_posicion()/get_largo(), ' ');
        }
    }
}