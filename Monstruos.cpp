//
//  Monstruos.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Monstruos.h"


Monstruos::Monstruos(int v, int f, Mazmorra& m, char s) : Personajes(m.get_largo()) {
    set_simbolo(s);
    set_vidas(v);
    set_fuerza(f);
    vivo = true;
}

void Monstruos::eliminar_monstruo(Mazmorra& m){
    m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), ' ');
    set_simbolo(' ');
    vivo = false;
}

/*void Monstruos::detectar_protagonista(Mazmorra& m, Protagonista& p){
    if (get_vivo() == true) {
        int ganador;
        if (m.get_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo())-1) == '@') {
            ganador = lucha(p.get_fuerza(), 20);
            cout << ganador;
            if (ganador == 1) {
                cout << "la lucha la ganó el monstruo" << endl;
                p.set_vidas(p.get_vidas()-1);
            } else {
                cout << "la lucha la ganó el protagonista" << endl;
                eliminar_monstruo(m);
            }
        }
        if (m.get_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo())+1) == '@') {
            ganador = lucha(p.get_fuerza(), 20);
            cout << ganador;
            if (ganador == 1) {
                cout << "la lucha la ganó el monstruo" << endl;
                p.set_vidas(p.get_vidas()-1);
            } else {
                cout << "la lucha la ganó el protagonista" << endl;
                eliminar_monstruo(m);
            }
        }
        if (m.get_vector_personajes((get_posicion()%get_largo())-1, (get_posicion()/get_largo())) == '@') {
            ganador = lucha(p.get_fuerza(), 20);
            cout << ganador;
            if (ganador == 1) {
                cout << "la lucha la ganó el monstruo" << endl;
                p.set_vidas(p.get_vidas()-1);
            } else {
                cout << "la lucha la ganó el protagonista" << endl;
                eliminar_monstruo(m);
            }
        }
        if (m.get_vector_personajes((get_posicion()%get_largo())+1, (get_posicion()/get_largo())) == '@') {
            ganador = lucha(p.get_fuerza(), 20);
            cout << ganador;
            if (ganador == 1) {
                cout << "la lucha la ganó el monstruo" << endl;
                p.set_vidas(p.get_vidas()-1);
            } else {
                cout << "la lucha la ganó el protagonista" << endl;
                eliminar_monstruo(m);
            }
        }
    } else {
        cout << "Estas muerto, no busques nada" << endl;
    }
}*/

/*void Monstruos::detectar_protagonista_t(Mazmorra& m, Protagonista& p){
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
}*/

bool Monstruos::get_vivo(){
    return vivo;
}