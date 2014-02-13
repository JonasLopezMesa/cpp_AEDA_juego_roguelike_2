//
//  Mazmorra.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Mazmorra.h"

void Mazmorra::rellenar_dibujos(){
    for (int i = 0 ;i < size ; i++) {
        Arquitectura[i] = ' ';
        Personajes[i] = ' ';
        Objetos[i] = ' ';
    }
}


Mazmorra::Mazmorra(){
    largo = 30+rand()%(51-30);
    alto = 30+rand()%(51-30);
    size = largo * alto;
    
    Arquitectura = new char[size];
    Personajes = new char[size];
    Objetos = new char[size];
    
    
    rellenar_dibujos();
    
    //Crear habitación 1
    habitacion[0].largo = 6+rand()%(11-6);
    habitacion[0].alto = 6+rand()%(11-6);
    habitacion[0].size = habitacion[0].alto * habitacion[0].largo;
    habitacion[0].inicio.x = 2+rand()%(4-2);
    habitacion[0].inicio.y = 2+rand()%(4-2);
    habitacion[0].pos_puerta[0].y = habitacion[0].inicio.y+1+rand()%((habitacion[0].alto-1)-habitacion[0].inicio.y+1);
    habitacion[0].pos_puerta[0].x = habitacion[0].inicio.x+habitacion[0].largo;
    habitacion[0].pos_puerta[1].y = habitacion[0].inicio.y+habitacion[0].alto;
    habitacion[0].pos_puerta[1].x = habitacion[0].inicio.x+1+rand()%((habitacion[0].largo-1)-habitacion[0].inicio.x+1);
    habitacion[0].trol = false;
    habitacion[0].n_dragones = 0;
    
    //Crear habitación 2
    habitacion[1].largo = 6+rand()%(11-6);
    habitacion[1].alto = 6+rand()%(11-6);
    habitacion[1].size = habitacion[1].alto * habitacion[1].largo;
    habitacion[1].inicio.x = (largo/2)+rand()%(((largo/2)+3)-(largo/2));
    habitacion[1].inicio.y = 2+rand()%(4-2);
    habitacion[1].pos_puerta[0].y = habitacion[1].inicio.y+1+rand()%((habitacion[1].alto-1)-habitacion[1].inicio.y+1);
    habitacion[1].pos_puerta[0].x = habitacion[1].inicio.x;
    habitacion[1].pos_puerta[1].y = habitacion[1].inicio.y+habitacion[1].alto;
    habitacion[1].pos_puerta[1].x = habitacion[1].inicio.x+rand()%((habitacion[1].largo-1)-habitacion[1].inicio.x);
    habitacion[1].trol = false;
    habitacion[1].n_dragones = 0;
    
    //Crear habitación 3
    habitacion[2].largo = 6+rand()%(11-6);
    habitacion[2].alto = 6+rand()%(11-6);
    habitacion[2].size = habitacion[2].alto * habitacion[2].largo;
    habitacion[2].inicio.x = 2+rand()%(4-2);
    habitacion[2].inicio.y = (alto/2)+rand()%(((alto/2)+3)-(alto/2));
    habitacion[2].pos_puerta[0].y = habitacion[2].inicio.y+1+rand()%((habitacion[2].alto-1)-habitacion[2].inicio.y+1);
    habitacion[2].pos_puerta[0].x = habitacion[2].inicio.x+habitacion[2].largo;
    habitacion[2].pos_puerta[1].y = habitacion[2].inicio.y;
    habitacion[2].pos_puerta[1].x = habitacion[2].inicio.x+1+rand()%((habitacion[2].largo-1)-habitacion[2].inicio.x+1);
    habitacion[2].trol = false;
    habitacion[2].n_dragones = 0;
    
    //Meter datos en la Arquitectura
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < habitacion[k].largo; i++) {
            Arquitectura[(((habitacion[k].inicio.y)*largo)+habitacion[k].inicio.x)+i] = '*';
        }
        for (int j = 0; j < habitacion[k].alto; j++) {
            Arquitectura[(((habitacion[k].inicio.y)*largo)+habitacion[k].inicio.x)+j*largo] = '*';
        }
        for (int j = 0; j < habitacion[k].alto; j++) {
            Arquitectura[(((habitacion[k].inicio.y)*largo)+habitacion[k].inicio.x+habitacion[k].largo)+j*largo] = '*';
        }
        for (int i = 0; i <= habitacion[k].largo; i++) {
            Arquitectura[(((habitacion[k].inicio.y+habitacion[k].alto)*largo)+habitacion[k].inicio.x)+i] = '*';
        }
        Arquitectura[(habitacion[k].pos_puerta[0].y*largo)+habitacion[k].pos_puerta[0].x] = '+';
        Arquitectura[(habitacion[k].pos_puerta[1].y*largo)+habitacion[k].pos_puerta[1].x] = '+';
    }
    
    //PASILLOS:
    //habitación 1 a habitación 2:
    int pasillo1x = abs(habitacion[0].pos_puerta[0].x-habitacion[1].pos_puerta[0].x);
    int pasillo1y = abs(habitacion[0].pos_puerta[0].y-habitacion[1].pos_puerta[0].y);
    for (int i = 1; i < pasillo1x /*+ pasillo1y*/; i++) {
        Arquitectura[(habitacion[0].pos_puerta[0].y*largo)+habitacion[0].pos_puerta[0].x+i] = '#';
    }
    if (habitacion[1].pos_puerta[0].y < habitacion[0].pos_puerta[0].y) {
        for (int i = 1; i <= pasillo1y; i++) {
            Arquitectura[((habitacion[0].pos_puerta[0].y*largo)+habitacion[0].pos_puerta[0].x+pasillo1x)-i*largo-1] = '#';
        }
    } else {
        for (int i = 1; i <= pasillo1y; i++) {
            Arquitectura[((habitacion[0].pos_puerta[0].y*largo)+habitacion[0].pos_puerta[0].x+pasillo1x)+i*largo-1] = '#';
        }
    }
    //habitación 2 a habitación 3:
    int pasillo3x = abs(habitacion[1].pos_puerta[1].x-habitacion[2].pos_puerta[0].x);
    int pasillo3y = abs(habitacion[1].pos_puerta[1].y-habitacion[2].pos_puerta[0].y);
    for (int i = 1; i < pasillo3x /*+ pasillo1y*/; i++) {
        Arquitectura[(habitacion[2].pos_puerta[0].y*largo)+habitacion[2].pos_puerta[0].x+i] = '#';
    }
    if (habitacion[1].pos_puerta[1].y < habitacion[2].pos_puerta[0].y) {
        for (int i = 0; i < pasillo3y; i++) {
            Arquitectura[((habitacion[2].pos_puerta[0].y*largo)+habitacion[2].pos_puerta[0].x+pasillo3x)-i*largo] = '#';
        }
    } else {
        for (int i = 1; i <= pasillo3y; i++) {
            Arquitectura[((habitacion[2].pos_puerta[0].y*largo)+habitacion[2].pos_puerta[0].x+pasillo3x)+i*largo-1] = '#';
        }
    }
    //habitación 1 a habitación 3:
    int pasillo2x = abs(habitacion[0].pos_puerta[1].x-habitacion[2].pos_puerta[1].x);
    int pasillo2y = abs(habitacion[0].pos_puerta[1].y-habitacion[2].pos_puerta[1].y);
    
    if (habitacion[2].pos_puerta[1].y < habitacion[0].pos_puerta[1].y) {
        for (int i = 1; i < pasillo2y; i++) {
            Arquitectura[((habitacion[0].pos_puerta[1].y*largo)+habitacion[0].pos_puerta[1].x+pasillo2x)-i*largo] = '#';
        }
    } else {
        for (int i = 1; i < pasillo2y; i++) {
            Arquitectura[((habitacion[0].pos_puerta[1].y*largo)+habitacion[0].pos_puerta[1].x+pasillo2x)+i*largo] = '#';
        }
    }
    if (habitacion[2].pos_puerta[1].x < habitacion[0].pos_puerta[1].x) {
        for (int i = 1; i <= pasillo2x /*+ pasillo1y*/; i++) {
            Arquitectura[(habitacion[0].pos_puerta[1].y*largo)+habitacion[0].pos_puerta[1].x-i-1+largo] = '#';
        }
    } else {
        for (int i = 1; i <= pasillo2x /*+ pasillo1y*/; i++) {
            Arquitectura[(habitacion[0].pos_puerta[1].y*largo)+habitacion[0].pos_puerta[1].x+i-1+largo] = '#';
        }
    }
    acceso.x = habitacion[0].inicio.x+1+rand()%((habitacion[0].largo-1)-(habitacion[0].inicio.x+1));
    acceso.y = habitacion[0].inicio.y+1+rand()%((habitacion[0].alto-1)-(habitacion[0].inicio.y+1));
    Arquitectura[(acceso.y*largo)+acceso.x] = 'X';
    
}

Mazmorra::Mazmorra(int nombre){
    ifstream text;
    char a[] = "Mazmorra_30_30.dat";
    char b[] = "Mazmorra_50_25.dat";
    if (nombre == 1) {
        text.open(a);
    } else if (nombre == 2) {
        text.open(b);
    }
    if (text.is_open()) {
        if (nombre == 1) {
            largo = 30;
            alto = 30;
            size = 30*30;
            habitacion[0].alto = 9;
            habitacion[0].largo = 7;
            habitacion[0].inicio.x = 2;
            habitacion[0].inicio.y = 3;
            habitacion[0].pos_puerta[0].x = 8;
            habitacion[0].pos_puerta[0].y = 5;
            habitacion[0].pos_puerta[1].x = 5;
            habitacion[0].pos_puerta[1].y = 11;
            habitacion[0].trol = false;
            habitacion[0].n_dragones = 0;
            habitacion[1].alto = 6;
            habitacion[1].largo = 13;
            habitacion[1].inicio.x = 15;
            habitacion[1].inicio.y = 1;
            habitacion[1].pos_puerta[0].x = 15;
            habitacion[1].pos_puerta[0].y = 5;
            habitacion[1].pos_puerta[1].x = 26;
            habitacion[1].pos_puerta[1].y = 6;
            habitacion[1].trol = false;
            habitacion[1].n_dragones = 0;
            habitacion[2].alto = 10;
            habitacion[2].largo = 19;
            habitacion[2].inicio.x = 5;
            habitacion[2].inicio.y = 17;
            habitacion[2].pos_puerta[0].x = 23;
            habitacion[2].pos_puerta[0].y = 20;
            habitacion[2].pos_puerta[1].x = 17;
            habitacion[2].pos_puerta[1].y = 17;
            habitacion[2].trol = false;
            habitacion[2].n_dragones = 0;
            
        } else if (nombre == 2){
            largo = 50;
            alto = 25;
            size = 50*25;
            habitacion[0].alto = 10;
            habitacion[0].largo = 10;
            habitacion[0].inicio.x = 5;
            habitacion[0].inicio.y = 0;
            habitacion[0].pos_puerta[0].x = 14;
            habitacion[0].pos_puerta[0].y = 2;
            habitacion[0].pos_puerta[1].x = 7;
            habitacion[0].pos_puerta[1].y = 9;
            habitacion[0].trol = false;
            habitacion[0].n_dragones = 0;
            habitacion[1].alto = 7;
            habitacion[1].largo = 18;
            habitacion[1].inicio.x = 27;
            habitacion[1].inicio.y = 5;
            habitacion[1].pos_puerta[0].x = 27;
            habitacion[1].pos_puerta[0].y = 7;
            habitacion[1].pos_puerta[1].x = 34;
            habitacion[1].pos_puerta[1].y = 11;
            habitacion[1].trol = false;
            habitacion[1].n_dragones = 0;
            habitacion[2].alto = 10;
            habitacion[2].largo = 15;
            habitacion[2].inicio.x = 11;
            habitacion[2].inicio.y = 14;
            habitacion[2].pos_puerta[0].x = 25;
            habitacion[2].pos_puerta[0].y = 20;
            habitacion[2].pos_puerta[1].x = 18;
            habitacion[2].pos_puerta[1].y = 14;
            habitacion[2].trol = false;
            habitacion[2].n_dragones = 0;
        }
        Arquitectura = new char[size];
        Personajes = new char[size];
        Objetos = new char[size];
        
        rellenar_dibujos();
        
        char l;
        for (int i = 0; i < size; i++) {
            text.get(l);
            if (l != '\n' && l != '\t' && l != '\r') {
                Arquitectura[i] = l;
            } else if (l == '\n' || l == '\t' || l == '\r') {
                i--;
            }
        }
        
        acceso.x = habitacion[0].inicio.x+1+rand()%((habitacion[0].largo-1)-(habitacion[0].inicio.x+1));
        acceso.y = habitacion[0].inicio.y+1+rand()%((habitacion[0].alto-1)-(habitacion[0].inicio.y+1));
        Arquitectura[(acceso.y*largo)+acceso.x] = 'X';
    }
}

char Mazmorra::get_vector_arquitectura(int x, int y){
    return Arquitectura[y*largo+x];
}
char Mazmorra::get_vector_personajes(int x, int y){
    return Personajes[y*largo+x];
}
char Mazmorra::get_vector_objetos(int x, int y){
    return Objetos[y*largo+x];
}


int Mazmorra::get_largo(){
    return largo;
}
int Mazmorra::get_alto(){
    return alto;
}
int Mazmorra::get_size(){
    return size;
}
int Mazmorra::get_acceso(){
    return acceso.y*largo+acceso.x;
}


int Mazmorra::get_habitacion_inicio(int h){
    return habitacion[h].inicio.y*largo+habitacion[h].inicio.x;
}
int Mazmorra::get_habitacion_largo(int h){
    return habitacion[h].largo;
}
int Mazmorra::get_habitacion_alto(int h){
    return habitacion[h].alto;
}
int Mazmorra::get_habitacion_puerta_pos(int h, int puer){
    return habitacion[h].pos_puerta[puer].y*largo+habitacion[h].pos_puerta[puer].x;
}
int Mazmorra::get_habitacion_puerta_conec(int h, int puer){
    return habitacion[h].pos_puerta[puer].puerta_conecta;
}


void Mazmorra::set_vector_objetos(int x, int y, char i){
    Objetos[y*largo+x] = i;
}
void Mazmorra::set_vector_personajes(int x, int y, char i){
    Personajes[y*largo+x] = i;
}
void Mazmorra::set_vector_arquitectura(int x, int y, char i){
    Arquitectura[y*largo+x] = i;
}


void Mazmorra::set_largo(int l){
    largo = l;
}
void Mazmorra::set_alto(int a){
    alto = a;
}
void Mazmorra::set_size(int s){
    size = s;
}
void Mazmorra::set_acceso(int x, int y){
    acceso.x = x;
    acceso.y = y;
}


void Mazmorra::set_habitacion_inicio(int h, int x, int y){
    habitacion[h].inicio.x = x;
    habitacion[h].inicio.y = y;
}
void Mazmorra::set_habitacion_largo(int h, int l){
    habitacion[h].largo = l;
}
void Mazmorra::set_habitacion_alto(int h, int a){
    habitacion[h].alto = a;
}
void Mazmorra::set_habitacion_puerta_pos(int h, int puer, int x, int y){
    habitacion[h].pos_puerta[puer].x = x;
    habitacion[h].pos_puerta[puer].y = y;
}
void Mazmorra::set_habitacion_puerta_conec(int h, int puer, int p){
    habitacion[h].pos_puerta[puer].puerta_conecta = p;
}


void Mazmorra::mostrar_arquitectura(){
    int prioridad;
    for (int i = 0; i < largo*alto; i++) {
        prioridad = 0;
        if (i != 0) {
            if (i%largo == 0) {
                cout << endl;
            }
        }
        if (Arquitectura[i] != ' ') {
            prioridad = 1;
        }
        if (Objetos[i] != ' ') {
            prioridad = 2;
        }
        if (Personajes[i] != ' ') {
            prioridad = 3;
        }
        
        if (prioridad == 0) {
            cout << ' ';
        }
        if (prioridad == 1) {
            cout << Arquitectura[i];
        }
        if (prioridad == 2) {
            cout << Objetos[i];
        }
        if (prioridad == 3) {
            cout << Personajes[i];
        }
    }
}

hab Mazmorra::get_habitacion(int h) {
    return habitacion[h];
}

void Mazmorra::set_habitacion_n_dragones(int h, int n){
    habitacion[h].n_dragones = n;
}
void Mazmorra::set_habitacion_trol(int h, bool b){
    habitacion[h].trol = b;
}
