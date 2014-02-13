//
//  Protagonista.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Protagonista.h"





Protagonista::Protagonista(Mazmorra& m) : Personajes(m.get_largo()){
    set_posicion((m.get_acceso()%get_largo())+1, m.get_acceso()/get_largo());
    set_simbolo('@');
    m.set_vector_personajes((m.get_acceso()%m.get_largo())+1, m.get_acceso()/m.get_largo(), get_simbolo());
    set_vidas(5);
    set_fuerza(5);
    set_habitacion_actual(0);
    Beneficio = 0;
}
int Protagonista::get_beneficio(){
    return Beneficio;
}
void Protagonista::set_beneficio(int b){
    Beneficio = b;
}

bool Protagonista::vidas_a_cero(){
    return get_vidas()==0 ? true : false;
}
bool Protagonista::victoria(Mazmorra& m){
    return (get_beneficio() >= 3) && (get_posicion()==m.get_acceso()) ? true : false;
}

void Protagonista::mover_protagonista(char mov, Mazmorra& m){
    if (mov == 'w') {
        if (m.get_vector_arquitectura(get_posicion()%get_largo(), (get_posicion()/get_largo())-1) == ' ' || m.get_vector_arquitectura(get_posicion()%get_largo(), (get_posicion()/get_largo())-1) == 'X') {
            posicion tmp;
            tmp.x = get_posicion()%get_largo();
            tmp.y = get_posicion()/get_largo();
            set_posicion(get_posicion()%get_largo(), (get_posicion()/get_largo())-1);
            m.set_vector_personajes(tmp.x, tmp.y, ' ');
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
        } else if (m.get_vector_arquitectura(get_posicion()%get_largo(), (get_posicion()/get_largo())-1) == '+') {
            posicion tmp;
            tmp.x = get_posicion()%get_largo();
            tmp.y = get_posicion()/get_largo();
            set_posicion(m.get_habitacion_puerta_pos(0, 1)%get_largo(), (m.get_habitacion_puerta_pos(0, 1)/get_largo())-1);
            m.set_vector_personajes(tmp.x, tmp.y, ' ');
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
            set_habitacion_actual(0);
        } else {
            cout << "IMPOSIBLE MOVERSE EN ESA DIRECCIÓN, INTÉNTALO DE NUEVO." << endl;
        }
        
    }
    if (mov == 's') {
        if (m.get_vector_arquitectura(get_posicion()%get_largo(), (get_posicion()/get_largo())+1) == ' ' || m.get_vector_arquitectura(get_posicion()%get_largo(), (get_posicion()/get_largo())+1) == 'X') {
            posicion tmp;
            tmp.x = get_posicion()%get_largo();
            tmp.y = get_posicion()/get_largo();
            set_posicion(get_posicion()%get_largo(), (get_posicion()/get_largo())+1);
            m.set_vector_personajes(tmp.x, tmp.y, ' ');
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
        } else if (m.get_vector_arquitectura(get_posicion()%get_largo(), (get_posicion()/get_largo())+1) == '+') {
            if (get_habitacion_actual() == 0) {
                posicion tmp;
                tmp.x = get_posicion()%get_largo();
                tmp.y = get_posicion()/get_largo();
                set_posicion(m.get_habitacion_puerta_pos(2, 1)%get_largo(), (m.get_habitacion_puerta_pos(2, 1)/get_largo())+1);
                m.set_vector_personajes(tmp.x, tmp.y, ' ');
                m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
                set_habitacion_actual(2);
            } else if (get_habitacion_actual() == 1) {
                posicion tmp;
                tmp.x = get_posicion()%get_largo();
                tmp.y = get_posicion()/get_largo();
                set_posicion((m.get_habitacion_puerta_pos(2, 0)%get_largo())-1, m.get_habitacion_puerta_pos(2, 0)/get_largo());
                m.set_vector_personajes(tmp.x, tmp.y, ' ');
                m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
                set_habitacion_actual(2);
            }
            
        } else {
            cout << "IMPOSIBLE MOVERSE EN ESA DIRECCIÓN, INTÉNTALO DE NUEVO." << endl;
        }
    }
    if (mov == 'a') {
        if (m.get_vector_arquitectura((get_posicion()%get_largo())-1, (get_posicion()/get_largo())) == ' ' || m.get_vector_arquitectura((get_posicion()%get_largo())-1, (get_posicion()/get_largo())) == 'X') {
            posicion tmp;
            tmp.x = get_posicion()%get_largo();
            tmp.y = get_posicion()/get_largo();
            set_posicion((get_posicion()%get_largo())-1, (get_posicion()/get_largo()));
            m.set_vector_personajes(tmp.x, tmp.y, ' ');
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
        } else if (m.get_vector_arquitectura((get_posicion()%get_largo())-1, (get_posicion()/get_largo())) == '+') {
            posicion tmp;
            tmp.x = get_posicion()%get_largo();
            tmp.y = get_posicion()/get_largo();
            set_posicion((m.get_habitacion_puerta_pos(0, 0)%get_largo())-1, (m.get_habitacion_puerta_pos(0, 0)/get_largo()));
            m.set_vector_personajes(tmp.x, tmp.y, ' ');
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
            set_habitacion_actual(0);
        } else {
            cout << "IMPOSIBLE MOVERSE EN ESA DIRECCIÓN, INTÉNTALO DE NUEVO." << endl;
        }
    }
    if (mov == 'd') {
        if (m.get_vector_arquitectura((get_posicion()%get_largo())+1, (get_posicion()/get_largo())) == ' ' || m.get_vector_arquitectura((get_posicion()%get_largo())+1, (get_posicion()/get_largo())) == 'X') {
            posicion tmp;
            tmp.x = get_posicion()%get_largo();
            tmp.y = get_posicion()/get_largo();
            set_posicion((get_posicion()%get_largo())+1, (get_posicion()/get_largo()));
            m.set_vector_personajes(tmp.x, tmp.y, ' ');
            m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
        } else if (m.get_vector_arquitectura((get_posicion()%get_largo())+1, (get_posicion()/get_largo())) == '+') {
            if (get_habitacion_actual() == 0) {
                posicion tmp;
                tmp.x = get_posicion()%get_largo();
                tmp.y = get_posicion()/get_largo();
                set_posicion((m.get_habitacion_puerta_pos(1, 0)%get_largo())+1, (m.get_habitacion_puerta_pos(1, 0)/get_largo()));
                m.set_vector_personajes(tmp.x, tmp.y, ' ');
                m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
                set_habitacion_actual(1);
                
            } else if (get_habitacion_actual() == 2) {
                posicion tmp;
                tmp.x = get_posicion()%get_largo();
                tmp.y = get_posicion()/get_largo();
                set_posicion((m.get_habitacion_puerta_pos(1, 1)%get_largo()), (m.get_habitacion_puerta_pos(1, 1)/get_largo())-1);
                m.set_vector_personajes(tmp.x, tmp.y, ' ');
                m.set_vector_personajes(get_posicion()%get_largo(), get_posicion()/get_largo(), get_simbolo());
                set_habitacion_actual(1);
            }
            
        } else {
            cout << "IMPOSIBLE MOVERSE EN ESA DIRECCIÓN, INTÉNTALO DE NUEVO." << endl;
        }
    }
}

void Protagonista::mostrar_estadisticas(){
    cout << "VIDAS: ";
    for (int i = 0; i < get_vidas(); i++) {
        cout << "√";
    }
    cout << endl;
    cout << "BENEFICIO: " << Beneficio << " FUERZA: " << get_fuerza() << endl;
}