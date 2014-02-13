//
//  Trol.h
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#ifndef __Roguelike2__Trol__
#define __Roguelike2__Trol__


#include "Monstruos.h"
#endif /* defined(__Roguelike2__Trol__) */

class Trol : public Monstruos {
    char direccion;
public:
    Trol(Mazmorra& m, int i);
    void modificar_posicion(Mazmorra& m){
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
    }
    void detectar_protagonista(Mazmorra& m, Protagonista& p);
};