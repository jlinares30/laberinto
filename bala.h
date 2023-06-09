#pragma once
#include "conio.h"
#include "iostream"
#include "mapa.h"
#include "color.h"

using namespace System;
using namespace std;


const int MAX_BALAS = 100;

struct Bala {
    int x;
    int y;
    char caracter = '*';

};


void dibujarBala(Bala* bala, int posX, int posY) {

    bala->x = posX;
    bala->y = posY;
    asignarPosicion(bala->x, bala->y);
    cout << bala->caracter;
}

void borrarBala(Bala* bala, int posX, int posY) {
    bala->x = posX;
    bala->y = posY;
    asignarPosicion(bala->x, bala->y);
    cout << " ";
}


void moverBala(Bala& bala, int mapa[FILAS][COLUMNAS], int& numBalas, int index, Bala* balas) {
    borrarBala(&bala, bala.x, bala.y);

    if (mapa[bala.y][bala.x + 1] == 1) {
        char caracterOriginal = (char)219;
        asignarPosicion(bala.x, bala.y);
        asignarColor(13);
        cout << caracterOriginal;

        for (int j = index; j < numBalas - 1; j++) {
            balas[j] = balas[j + 1];
        }

        numBalas--;
    }
    else {
        bala.x++;

        if (bala.x >= COLUMNAS) {
            for (int j = index; j < numBalas - 1; j++) {
                balas[j] = balas[j + 1];
            }

            numBalas--;
        }
        else {
            asignarPosicion(bala.x, bala.y);
            asignarColor(15);
            dibujarBala(&bala, bala.x, bala.y);
        }
    }
}

