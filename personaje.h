#pragma once
#include <iostream>
#include "color.h"
#include "bala.h" // Agregar esta línea

using namespace System;
using namespace std;

const int ARRIBA = 72;
const int ABAJO = 80;
const int DERECHA = 77;
const int IZQUIERDA = 75;

struct Personaje {
    int x;
    int y;
    string cabeza = "°w°";
    string cuerpo = "\||/";
    string pies = " >￣> ";
    Bala* balas; // Agregar el atributo Bala* balas al struct
    int numBalas; // Agregar el atributo numBalas para llevar cuenta de las balas
};

void dibujarPersonaje(Personaje* personaje, int posX, int posY) {
    personaje->x = posX;
    personaje->y = posY;
    asignarColor(14);
    asignarPosicion(personaje->x, personaje->y);
    cout << personaje->cabeza;
    asignarPosicion(personaje->x, personaje->y + 1);
    cout << personaje->cuerpo;
    asignarPosicion(personaje->x, personaje->y + 2);
    cout << personaje->pies;
}

void borrarPersonaje(Personaje* personaje, int posX, int posY) {
    personaje->x = posX;
    personaje->y = posY;
    asignarColor(8);
    asignarPosicion(personaje->x, personaje->y);
    cout << string(5, ' ');
    asignarPosicion(personaje->x, personaje->y + 1);
    cout << string(5, ' ');
    asignarPosicion(personaje->x, personaje->y + 2);
    cout << string(5, ' ');
}

void disparar(Personaje* personaje) {
    if (personaje->numBalas < MAX_BALAS) {
        Bala nuevaBala;
        nuevaBala.x = personaje->x + 3;
        nuevaBala.y = personaje->y + 1;
        personaje->balas[personaje->numBalas] = nuevaBala;
        personaje->numBalas++;
    }
}
