#pragma once
#include <iostream>
#include "color.h"
#include "bala.h" 

using namespace System;
using namespace std;

struct Enemigo {
    int enemigoX = 20;
    int enemigoY = 15;
    float dx = 1;
    float dy = 1;
    string cabeza = "___";
    string cuerpo = "|O|";
    string pies =   "|O|";
    Bala* balas; 
};

void dibujarEnemigo(Enemigo* enemigo, int posX, int posY) {
    enemigo->enemigoX = posX;
    enemigo->enemigoY = posY;
    asignarColor(11);
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY);
    cout << enemigo->cabeza;
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY + 1);
    cout << enemigo->cuerpo;
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY + 2);
    cout << enemigo->pies;
}

void eliminarEnemigo(Enemigo* enemigo, int posX, int posY) {
    enemigo->enemigoX = posX;
    enemigo->enemigoY = posY;
    asignarColor(8);
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY);
    cout << string(3, ' ');
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY + 1);
    cout << string(3, ' ');
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY + 2);
    cout << string(3, ' ');
}