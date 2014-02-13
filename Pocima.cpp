//
//  Pocima.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Pocima.h"

Pocima::Pocima(Mazmorra& m, int i) : Objetos(m.get_largo(), 1, 5){
    int x,y,colocado=0; int contador = 0;
    int incremento = 1;
    while (colocado == 0) {
        contador = contador+1;
        cout << "a" << endl;
                x = m.get_habitacion(i).inicio.x+incremento+rand()%((m.get_habitacion(i).inicio.x+m.get_habitacion(i).largo-2)-(m.get_habitacion(i).inicio.x+incremento));
        cout << "b" << endl;
                y = m.get_habitacion(i).inicio.y+incremento+rand()%((m.get_habitacion(i).inicio.y+m.get_habitacion(i).alto-2)-(m.get_habitacion(i).inicio.y+incremento));
        cout << "c" << endl;
                if (m.get_vector_arquitectura(x, y) != '*' && m.get_vector_arquitectura(x, y) != '+' && m.get_vector_arquitectura(x, y) != '#' && m.get_vector_arquitectura(x, y) != 'X' && m.get_vector_personajes(x, y) != '@' && m.get_vector_personajes(x, y) != 'D' && m.get_vector_personajes(x, y) != 'T' && m.get_vector_objetos(x, y) != 'A') {
                    cout << "d" << endl;
                    colocado = 1;
                    cout << "e" << endl;
                    set_habitacion_actual(i);
                    cout << "f" << endl;
                    set_posicion(x, y);
                    cout << "g" << endl;
                    m.set_vector_objetos(x, y, 'P');
                    cout << "h" << endl;
                    encontrado = false;
                } else{
                    incremento = incremento+1;
                }
        if (contador == 10) {
            colocado = 1;
        }
    }
}

bool Pocima::get_encontrado(){
    return encontrado;
}

void Pocima::set_encontrado(bool e){
    encontrado = e;
}

void Pocima::controlar_personaje(Mazmorra& m, Protagonista& p){
    if (encontrado == false) {
        if (p.get_posicion() == get_posicion()) {
            encontrado = true;
            p.set_fuerza(get_aumento_fuerza()+p.get_fuerza());
            p.set_beneficio(p.get_beneficio()+get_beneficio());
            m.set_vector_objetos(get_posicion()%get_largo(), get_posicion()/get_largo(), ' ');
        }
    }
}