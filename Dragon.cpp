//
//  Dragon.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Dragon.h"

Dragon::Dragon(Mazmorra& m) : Monstruos(1, 20, m, 'D') {
    int x,y,colocado = 0;
    while (colocado == 0) {
        for (int i = 0; i < 3; i++) {
            if (m.get_habitacion(i).n_dragones < 3 && colocado == 0) {
                x = m.get_habitacion(i).inicio.x+1+rand()%((m.get_habitacion(i).inicio.x+m.get_habitacion(i).largo-2)-(m.get_habitacion(i).inicio.x+1));
                y = m.get_habitacion(i).inicio.y+1+rand()%((m.get_habitacion(i).inicio.y+m.get_habitacion(i).alto-2)-(m.get_habitacion(i).inicio.y+1));
                if (m.get_vector_arquitectura(x, y) != '*' && m.get_vector_arquitectura(x, y) != '+' && m.get_vector_arquitectura(x, y) != '#' && m.get_vector_arquitectura(x, y) != 'X' && m.get_vector_personajes(x, y) != '@' && m.get_vector_personajes(x, y) != 'D' && m.get_vector_personajes(x, y) != 'T') {
                    colocado = 1;
                    set_habitacion_actual(i);
                    m.set_habitacion_n_dragones(i, m.get_habitacion(i).n_dragones+1);
                    set_posicion(x, y);
                    m.set_vector_personajes(x, y, 'D');
                }
            }
        }
    }
}

/*void Dragon::modificar_posicion(Mazmorra& m){
    int opcion, terminado=0;
    opcion = rand()%4;
    if (get_vivo() == true) {
        int contador = 0;
        while (terminado == 0) {
            contador= contador+1;
            if (opcion == 0) {
                if (m.get_vector_arquitectura((get_posicion()%get_largo()), (get_posicion()/get_largo())-1) == ' ' && m.get_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo())-1) == ' ' &&
                    m.get_vector_objetos((get_posicion()%get_largo()), (get_posicion()/get_largo())-1) == ' ') {
                    m.set_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo()), ' ');
                    set_posicion((get_posicion()%get_largo()), (get_posicion()/get_largo())-1);
                    m.set_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo()), 'D');
                    terminado = 1;
                } else {
                    opcion = opcion+1;
                }
            }if (opcion == 1){
                if (m.get_vector_arquitectura((get_posicion()%get_largo()), (get_posicion()/get_largo())+1) == ' ' && m.get_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo())+1) == ' ' && m.get_vector_objetos((get_posicion()%get_largo()), (get_posicion()/get_largo())+1) == ' ') {
                    m.set_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo()), ' ');
                    set_posicion((get_posicion()%get_largo()), (get_posicion()/get_largo())+1);
                    m.set_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo()), 'D');
                    terminado = 1;
                } else {
                    opcion = opcion+1;
                }
            }if (opcion == 2){
                if (m.get_vector_arquitectura((get_posicion()%get_largo())-1, (get_posicion()/get_largo())) == ' ' && m.get_vector_personajes((get_posicion()%get_largo())-1, (get_posicion()/get_largo())) == ' ' && m.get_vector_objetos((get_posicion()%get_largo())-1, (get_posicion()/get_largo())) == ' ') {
                    m.set_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo()), ' ');
                    set_posicion((get_posicion()%get_largo())-1, (get_posicion()/get_largo()));
                    m.set_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo()), 'D');
                    terminado = 1;
                } else {
                    opcion = opcion+1;
                }
            }if (opcion == 3){
                if (m.get_vector_arquitectura((get_posicion()%get_largo())+1, (get_posicion()/get_largo())) == ' ' && m.get_vector_personajes((get_posicion()%get_largo())+1, (get_posicion()/get_largo())) == ' ' && m.get_vector_objetos((get_posicion()%get_largo())+1, (get_posicion()/get_largo())) == ' ') {
                    m.set_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo()), ' ');
                    set_posicion((get_posicion()%get_largo())+1, (get_posicion()/get_largo()));
                    m.set_vector_personajes((get_posicion()%get_largo()), (get_posicion()/get_largo()), 'D');
                    terminado = 1;
                } else {
                    opcion = 0;
                }
            }
            if (contador == 2) {
                terminado = 1;
            }
        }
    } 
}*/

void Dragon::monstrar_estadisticas(int i){
    cout << "Dragon " << i << endl;
    cout << "Fuerza: " << get_fuerza();
    cout << " Vidas: " << get_vidas();
}
