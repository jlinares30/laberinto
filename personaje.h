﻿#pragma once
#include <iostream>
#include "color.h"
#include "enemigo.h"
#include "agente.h"
#include "bala.h" 

using namespace System;
using namespace std;

const int ARRIBA = 72;
const int ABAJO = 80;
const int DERECHA = 77;
const int IZQUIERDA = 75;

struct Personaje {
    int x;
    int y;
    int posX;
    int posY;
    int contVidas = 3;
    int contVidasTuto = 1;
    int posVidasX = 1;
    int posVidasY = 27;
    string cabeza = "/O\\";
    string cuerpo = "| |";
    string pies =   "|=|";
    Bala* balas; 
    int numBalas; 
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
        cout << "*    ";
        break;
    case 2:
        cout << "* *  ";
        break;
    case 3:
        cout << "* * *";
        break;
    default:
        break;
    }
}
void imprimirVidasTutorial(Personaje* personaje) {
    asignarColor(13);
    asignarPosicion(1, 20);
    cout << "HP: " << personaje->contVidasTuto << " ";
    switch (personaje->contVidasTuto)
    {
    case 1:
        cout << "*    ";
        break;
    case 2:
        cout << "* *  ";
        break;
    case 3:
        cout << "* * *";
        break;
    default:
        break;
    }
}

void colisionEnemigoPersonaje(Personaje* personaje,int posX, int posY, Enemigo* enemigo) {
    int enemigoX = static_cast<int>(enemigo->enemigoX);
    int enemigoY = static_cast<int>(enemigo->enemigoY);

    bool colision = false;

    // Verificar colisión en cada posición del personaje y enemigo
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((posY + i == enemigoY && posX + j == enemigoX) ||
                (posY + i == enemigoY + 1 && posX + j == enemigoX) ||
                (posY + i == enemigoY + 2 && posX + j == enemigoX))
            {
                colision = true;
                break;
            }
        }
        if (colision) {
            break;
        }
    }
        personaje->contVidas--;
        borrarPersonaje(personaje, posX, posY);
        posX = 0;
        posY = 1;
    }


void imprimir_mensaje_perdedor()
{
    Console::Clear();
    Console::SetWindowSize(120, 30);
    ubicar(40, 12);
    cout << " GGGG   AAAAA  M   M  EEEEE       OOO   V   V  EEEEE  RRRR ";
    ubicar(40, 13);
    cout << "G      A     A MM MM  E          O   O  V   V  E      R   R";
    ubicar(40, 14);
    cout << "G  GGG AAAAAAA M M M  EEEE       O   O  V   V  EEEE   RRRR ";
    ubicar(40, 15);
    cout << "G    G A     A M   M  E          O   O  V   V  E      R  R ";
    ubicar(40, 16);
    cout << " GGGG  A     A M   M  EEEEE       OOO    VVV   EEEEE  R   R";
}
void imprimir_mensaje_ganador()
{
    Console::Clear();
    Console::SetWindowSize(120, 30);
    ubicar(40, 12);
    cout << "_  _   ___   __ __    __    __ __ __  __";
    ubicar(40, 13);
    cout << "\\\\//  // \\\\  || ||    ||    || || ||\\ ||";
    ubicar(40, 14);
    cout << " )/  ((   )) || ||    \\\\ /\\ // || ||\\\\||";
    ubicar(40, 15);
    cout << "//    \\\\_//  \\\\_//     \\V/\\V/  || || \\||";
}