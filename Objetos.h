//
//  Objetos.h
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#ifndef __Roguelike2__Objetos__
#define __Roguelike2__Objetos__

#include "Mazmorra.h"

class Objetos {
    posicion pos;
    char simbolo;
    int habitacion_actual;
    int largo;
    int beneficio;
    int aumento_fuerza;
public:
    Objetos(int l, int b,  int a);
    int get_posicion();
    char get_simbolo();
    int get_habitacion_actual();
    int get_largo();
    int get_beneficio();
    int get_aumento_fuerza();
    
    void set_posicion(int x, int y);
    void set_simbolo(char s);
    void set_habitacion_actual(int h);
    void set_beneficio(int b);
    void set_aumento_fuerza(int a);
};


#endif /* defined(__Roguelike2__Objetos__) */
