//
//  Trol.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Trol.h"

Trol::Trol(Mazmorra& m, int i) : Monstruos(3, 10, m, 'T'){
    int x,y,colocado = 0;
    while (colocado == 0) {
        //for (int i = 0; i < 3; i++) {
            if (colocado == 0) {
                x = m.get_habitacion(i).inicio.x+1+rand()%((m.get_habitacion(i).largo-2)-(m.get_habitacion(i).inicio.x+1));
                y = m.get_habitacion(i).inicio.y+1+rand()%((m.get_habitacion(i).alto-2)-(m.get_habitacion(i).inicio.y+1));
                if (m.get_vector_arquitectura(x, y) != '*' && m.get_vector_arquitectura(x, y) != '+' && m.get_vector_arquitectura(x, y) != '#' && m.get_vector_arquitectura(x, y) != 'X' && m.get_vector_personajes(x, y) != '@' && m.get_vector_personajes(x, y) != 'D' && m.get_vector_personajes(x, y) != 'T') {
                    colocado = 1;
                    set_habitacion_actual(i);
                    set_posicion(x, y);
                    m.set_vector_personajes(x, y, 'T');
                    direccion = 'd';
                }
            }
        //}
    }
}

/*void Trol::modificar_posicion(Mazmorra& m){
    if (direccion == 'd') {
        if (m.get_vector_arquitectura((get_posicion()%get_largo())+1, get_posicion()/get_largo()) == ' ') {
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), ' ');
            set_posicion((get_posicion()%get_largo())+1, get_posicion()/get_largo());
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
        } else if (m.get_vector_arquitectura((get_posicion()%get_largo())+1, get_posicion()/get_largo()) == '*' || m.get_vector_arquitectura((get_posicion()%get_largo())+1, get_posicion()/get_largo()) == '+') {
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), ' ');
            set_posicion((get_posicion()%get_largo())-1, get_posicion()/get_largo());
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
            direccion = 'i';
        }
    }
    else if (direccion == 'i') {
        if (m.get_vector_arquitectura((get_posicion()%get_largo())-1, get_posicion()/get_largo()) == ' ') {
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), ' ');
            set_posicion((get_posicion()%get_largo())-1, get_posicion()/get_largo());
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
        } else if (m.get_vector_arquitectura((get_posicion()%get_largo())-1, get_posicion()/get_largo()) == '*' || m.get_vector_arquitectura((get_posicion()%get_largo())-1, get_posicion()/get_largo()) == '+') {
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), ' ');
            set_posicion((get_posicion()%get_largo())+1, get_posicion()/get_largo());
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
            direccion = 'd';
        }
    }
}*/

void Trol::detectar_protagonista(Mazmorra& m, Protagonista& p){
    int ganador;
    if ((get_posicion()%get_largo()) == (p.get_posicion()%get_largo()) && p.get_habitacion_actual() == get_habitacion_actual()) {
        ganador = lucha(p.get_fuerza(), 10);
        if (ganador == 1) {
            p.set_vidas(p.get_vidas()-1);
        } else {
            if (get_vidas() > 0) {
                set_vidas(get_vidas()-1);
            }
            if (get_vidas() == 0){
                eliminar_monstruo(m);
            }
        }
    }
}