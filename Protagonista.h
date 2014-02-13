//
//  Protagonista.h
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#ifndef __Roguelike2__Protagonista__
#define __Roguelike2__Protagonista__

#include "Personajes.h"

class Protagonista : public Personajes {
    int Beneficio;
public:
    Protagonista(Mazmorra& m);
    int get_beneficio();
    void set_beneficio(int b);
    
    bool vidas_a_cero();
    bool victoria(Mazmorra& m);
    
    void mover_protagonista(char mov, Mazmorra& m);
    
    void mostrar_estadisticas();
};
#endif /* defined(__Roguelike2__Protagonista__) */
