//
//  Personajes.h
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#ifndef __Roguelike2__Personajes__
#define __Roguelike2__Personajes__

#include "Mazmorra.h"
class Personajes {
    posicion pos;
    int vidas;
    int Fuerza;
    char simbolo;
    int habitacion_actual;
    int largo;
public:
    Personajes(int l);
    int get_posicion();
    int get_vidas();
    int get_fuerza();
    char get_simbolo();
    int get_habitacion_actual();
    int get_largo();
    
    void set_posicion(int x, int y);
    void set_vidas(int v);
    void set_fuerza(int f);
    void set_simbolo(char s);
    void set_habitacion_actual(int h);
    
    int lucha(int fuerza1, int fuerza2);
};


#endif /* defined(__Roguelike2__Personajes__) */
