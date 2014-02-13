//
//  Monstruos.h
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#ifndef __Roguelike2__Monstruos__
#define __Roguelike2__Monstruos__

#include "Personajes.h"
#include "Protagonista.h"

class Monstruos : public Personajes {
    bool vivo;
public:
    Monstruos(int v, int f, Mazmorra& m, char s);
    void eliminar_monstruo(Mazmorra& m);
    virtual void detectar_protagonista(Mazmorra& m, Protagonista& p){
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
    }
    //void detectar_protagonista_t(Mazmorra& m, Protagonista& p);
    bool get_vivo();
};


#endif /* defined(__Roguelike2__Monstruos__) */
