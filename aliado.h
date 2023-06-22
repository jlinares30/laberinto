#pragma once
#include <iostream>
#include "color.h"
#include "bala.h" // Agregar esta línea

using namespace System;
using namespace std;

struct Aliado {
    int aliadoX = 25;
    int aliadoY = 2;
    string cabeza = "/O\\";
    string cuerpo = "/|\\";
    string pies =   "/ \\";
};


void dibujarAliado(Aliado* aliado, int posX, int posY) {
    aliado->aliadoX = posX;
    aliado->aliadoY = posY;
    asignarColor(3);
    asignarPosicion(aliado->aliadoX, aliado->aliadoY);
    cout << aliado->cabeza;
    asignarPosicion(aliado->aliadoX, aliado->aliadoY + 1);
    cout << aliado->cuerpo;
    asignarPosicion(aliado->aliadoX, aliado->aliadoY + 2);
    cout << aliado->pies;
}
void eliminarAliado(Aliado* aliado, int posX, int posY) {
    aliado->aliadoX = posX;
    aliado->aliadoY = posY;
    asignarColor(8);
    asignarPosicion(aliado->aliadoX, aliado->aliadoY);
    cout << string(3, ' ');
    asignarPosicion(aliado->aliadoX, aliado->aliadoY + 1);
    cout << string(3, ' ');
    asignarPosicion(aliado->aliadoX, aliado->aliadoY + 2);
    cout << string(3, ' ');
}