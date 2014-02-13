//
//  Amuleto.h
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#ifndef __Roguelike2__Amuleto__
#define __Roguelike2__Amuleto__
#include "Objetos.h"
#include "Protagonista.h"

class Amuleto : public Objetos {
    bool encontrado;
public:
    Amuleto(Mazmorra& m);
    bool get_encontrado();
    void set_encontrado(bool e);
    void controlar_personaje(Mazmorra& m, Protagonista& p);
};

#endif /* defined(__Roguelike2__Amuleto__) */
