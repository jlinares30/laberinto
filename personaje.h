#pragma once
#include <iostream>
#include "color.h"
#include "enemigo.h"
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
    int contVidas = 2;
    int posVidasX = 1;
    int posVidasY = 27;
    string cabeza = "/O\\";
    string cuerpo = "| |";
    string pies =   "|=|";

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
    cout << string(3, ' ');
    asignarPosicion(personaje->x, personaje->y + 1);
    cout << string(3, ' ');
    asignarPosicion(personaje->x, personaje->y + 2);
    cout << string(3, ' ');
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

void imprimirVidas(Personaje* personaje) {
    asignarColor(9);
    asignarPosicion(personaje->posVidasX, personaje->posVidasY);
    cout << "HP: " << personaje->contVidas << " ";
    switch (personaje->contVidas)
    {
    case 1:
        cout << "*";
        break;
    case 2:
        cout << "* *";
        break;
    case 3:
        cout << "* * *";
        break;
    default:
        break;
    }
}

void colisionEnemigoPersonaje(Personaje* personaje, Enemigo* enemigo) {

}