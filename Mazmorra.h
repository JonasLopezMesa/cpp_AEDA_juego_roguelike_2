//
//  Mazmorra.h
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#ifndef __Roguelike2__Mazmorra__
#define __Roguelike2__Mazmorra__

#include <iostream>
#include <string>
#include "vector"
#include <fstream>
//#include "Dragon.h"
using namespace std;

struct puerta {
    int x;
    int y;
    int puerta_conecta;
};

struct posicion {
    int x;
    int y;
};

struct hab {
    int n_dragones;
    bool trol;
    posicion inicio;
    int largo;
    int alto;
    int size;
    puerta pos_puerta[2];
};

class Mazmorra {
private:
    char* Arquitectura;
    char* Personajes;
    char* Objetos;
    posicion acceso;
    int largo;
    int alto;
    int size;
    hab habitacion[3];
    void rellenar_dibujos();
public:
    Mazmorra(); //constructor aleatorio
    Mazmorra(int nombre); //constructor con fichero
    
    char get_vector_arquitectura(int x, int y);
    char get_vector_personajes(int x, int y);
    char get_vector_objetos(int x, int y);
    
    int get_largo();
    int get_alto();
    int get_size();
    int get_acceso();
    
    int get_habitacion_inicio(int hab);
    int get_habitacion_largo(int hab);
    int get_habitacion_alto(int hab);
    int get_habitacion_puerta_pos(int hab, int puer);
    int get_habitacion_puerta_conec(int hab, int puer);
    
    void set_vector_objetos(int x, int y, char i);
    void set_vector_personajes(int x, int y, char i);
    void set_vector_arquitectura(int x, int y, char i);
    
    void set_largo(int l);
    void set_alto(int a);
    void set_size(int s);
    void set_acceso(int x, int y);
    
    void set_habitacion_inicio(int hab, int x, int y);
    void set_habitacion_largo(int hab, int l);
    void set_habitacion_alto(int hab, int a);
    void set_habitacion_puerta_pos(int hab, int puer, int x, int y);
    void set_habitacion_puerta_conec(int hab, int puer, int p);
    void set_habitacion_n_dragones(int hab, int n);
    void set_habitacion_trol(int hab, bool b);
    
    void mostrar_arquitectura(/*Dragon& lista_dragones*/);
    hab get_habitacion(int h);
    
};

#endif /* defined(__Roguelike2__Mazmorra__) */
