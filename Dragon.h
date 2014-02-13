//
//  Dragon.h
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#ifndef __Roguelike2__Dragon__
#define __Roguelike2__Dragon__

#include "Monstruos.h"


class Dragon : public Monstruos {
public:
    Dragon(Mazmorra& m);
    void modificar_posicion(Mazmorra& m){
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
    }
    void monstrar_estadisticas(int i);
};

#endif /* defined(__Roguelike2__Dragon__) */
