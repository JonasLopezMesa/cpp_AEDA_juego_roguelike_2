//
//  main.cpp
//  Roguelike2
//
//  Created by jonas on 05/03/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Mazmorra.h"
#include "Protagonista.h"
#include "Dragon.h"
#include "Trol.h"
#include "Amuleto.h"
#include "Pocima.h"
#include "Espada.h"
#include "funciones_varias.h"
int main()
{
        int opcion;
        cout << "Bienvenido al juego Roguelike." << endl;
        cout << "¿Desea cargar un mapa aleatoriamente o cargarlo desde fichero?" << endl;
        cout << "1. Cargarlo aleatoriamente." << endl;
        cout << "2. Cargarlo desde fichero." << endl;
        cin >> opcion;
        if (opcion == 1) {
            Mazmorra prueba;
            Protagonista prota1(prueba);
            Dragon lista_dragones[9] = {Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba)};
            Trol lista_troles[3] = {Trol(prueba,0), Trol(prueba,1), Trol(prueba,2)};
            Amuleto amul(prueba);
            Pocima lista_pocimas[3] = {Pocima(prueba,0), Pocima(prueba,1), Pocima(prueba,2)};
            Espada lista_espadas[3] = {Espada(prueba,0), Espada(prueba,1), Espada(prueba,2)};
            
            int x = 0;
            char mov;
            while (x != 1) {
                if (prota1.vidas_a_cero() == true) {
                    x = 1;
                    limpiar_pantalla();
                    cout << "HAS PERDIDO" << endl;
                }
                if (prota1.get_beneficio() >= 3 && prota1.get_posicion() == prueba.get_acceso()) {
                    x = 1;
                    limpiar_pantalla();
                    cout << "HAS GANADO!!!" << endl;
                }
                if (x == 0) {
                    limpiar_pantalla();
                    prota1.mostrar_estadisticas();
                    prueba.mostrar_arquitectura(/*lista_dragones*/);
                    for (int i = 0; i < 9; i++) {
                        lista_dragones[i].detectar_protagonista(prueba, prota1);
                    }
                    for (int i = 0; i < 3; i++) {
                        lista_troles[i].detectar_protagonista(prueba, prota1);
                        lista_pocimas[i].controlar_personaje(prueba, prota1);
                        lista_espadas[i].controlar_personaje(prueba, prota1);
                    }
                    amul.controlar_personaje(prueba, prota1);
                    
                    
                    //comprobar victoria
                    cin >> mov;
                    prota1.mover_protagonista(mov, prueba);
                    for (int i = 0; i < 9; i++) {
                        lista_dragones[i].modificar_posicion(prueba);
                    }
                    for (int i = 0; i < 3; i++) {
                        lista_troles[i].modificar_posicion(prueba);
                    }
                }
            }
        }
        if (opcion == 2) {
            int opt;
            cout << "1. Mazmorra 30x30" << endl;
            cout << "2. Mazmorra 50x25" << endl;
            cin >> opt;
            if (opt == 1 || opt == 2) {
                Mazmorra prueba(opt);
                cout << 1 << endl;
                Protagonista prota1(prueba);
                cout << 2 << endl;
                Dragon lista_dragones[9] = {Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba), Dragon(prueba)};
                cout << 3 << endl;
                Trol lista_troles[3] = {Trol(prueba, 0), Trol(prueba, 1), Trol(prueba, 2)};
                cout << 4 << endl;
                Amuleto amul(prueba);
                cout << 5 << endl;
                Pocima lista_pocimas[3] = {Pocima(prueba,0), Pocima(prueba,1), Pocima(prueba,2)};
                cout << 6 << endl;
                Espada lista_espadas[3] = {Espada(prueba,0), Espada(prueba,1), Espada(prueba,2)};
                cout << 7 << endl;
                
                int x = 0;
                char mov;
                while (x != 1) {
                    if (prota1.vidas_a_cero() == true) {
                        x = 1;
                        limpiar_pantalla();
                        cout << "HAS PERDIDO" << endl;
                    }
                    if (prota1.get_beneficio() >= 3 && prota1.get_posicion() == prueba.get_acceso()) {
                        x = 1;
                        limpiar_pantalla();
                        cout << "HAS GANADO!!!" << endl;
                    }
                    if (x == 0) {
                        limpiar_pantalla();
                        prota1.mostrar_estadisticas();
                        prueba.mostrar_arquitectura(/*lista_dragones*/);
                        for (int i = 0; i < 9; i++) {
                            lista_dragones[i].detectar_protagonista(prueba, prota1);
                        }
                        for (int i = 0; i < 3; i++) {
                            lista_troles[i].detectar_protagonista(prueba, prota1);
                            lista_pocimas[i].controlar_personaje(prueba, prota1);
                            lista_espadas[i].controlar_personaje(prueba, prota1);
                        }
                        amul.controlar_personaje(prueba, prota1);
                        
                        
                        //comprobar victoria
                        cin >> mov;
                        prota1.mover_protagonista(mov, prueba);
                        for (int i = 0; i < 9; i++) {
                            lista_dragones[i].modificar_posicion(prueba);
                        }
                        for (int i = 0; i < 3; i++) {
                            lista_troles[i].modificar_posicion(prueba);
                        }
                    }
                }
            }
        }
    
    
    
    return 0;
}

