//
//  Espada.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Espada.h"

Espada::Espada(Mazmorra& m, int i) : Objetos(m.get_largo(), 0, 10){
    cout << "ESPADA: " << i << endl;
    int x,y,colocado=0;int contador = 0;
    while (colocado == 0) {
        cout << contador << endl;
        contador = contador+1;
        x = m.get_habitacion(i).inicio.x+1+rand()%((m.get_habitacion(i).inicio.x+m.get_habitacion(i).largo-2)-(m.get_habitacion(i).inicio.x+1));
        cout << "a" << endl;
        y = m.get_habitacion(i).inicio.y+1+rand()%((m.get_habitacion(i).inicio.y+m.get_habitacion(i).alto-2)-(m.get_habitacion(i).inicio.y+1));
        cout << "b" << endl;
        if (m.get_vector_arquitectura(x, y) == ' ' && m.get_vector_personajes(x, y) == ' ' && m.get_vector_objetos(x, y) == ' ') {
            cout << "c" << endl;
            colocado = 1;
            cout << "d" << endl;
            set_habitacion_actual(i);
            cout << "e" << endl;
            set_posicion(x, y);
            cout << "f" << endl;
            m.set_vector_objetos(x, y, 'E');
            cout << "g" << endl;
            encontrado = false;
            cout << "h" << endl;
        }
        if (contador == 100) {
            colocado = 1;
        }
    }
}

bool Espada::get_encontrado(){
    return encontrado;
}

void Espada::set_encontrado(bool e){
    encontrado = e;
}

void Espada::controlar_personaje(Mazmorra& m, Protagonista& p){
    if (encontrado == false) {
        if (p.get_posicion() == get_posicion()) {
            encontrado = true;
            p.set_fuerza(get_aumento_fuerza()+p.get_fuerza());
            p.set_beneficio(p.get_beneficio()+get_beneficio());
            m.set_vector_objetos(get_posicion()%get_largo(), get_posicion()/get_largo(), ' ');
        }
    }
}