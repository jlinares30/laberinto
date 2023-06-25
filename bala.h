#pragma once
#include "conio.h"
#include "iostream"
#include "mapa.h"
#include "color.h"
#include "enemigo.h"
#include "agente.h"

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

void moverBala(Bala& bala, int mapa[FILAS][COLUMNAS], int& numBalas, int index, Bala* balas, Agente agentes[], int numAgentes) {
    borrarBala(&bala, bala.x, bala.y);

    if (mapa[bala.y][bala.x + 1] == 1) {
        borrarBala(&bala, bala.x, bala.y);

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
            asignarColor(10);
            dibujarBala(&bala, bala.x, bala.y);
        }
        
    }
    for (int i = 0; i < numAgentes; i++) {
        if (bala.x == agentes[i].x && bala.y >= agentes[i].y && bala.y <= agentes[i].y + 1) {
            // Detener el movimiento del agente
            agentes[i].dx = 0;
            agentes[i].dy = 0;
            agentes[i].tiempoInactividad = 30;
            // Eliminar la bala
            borrarBala(&bala, bala.x, bala.y);
            for (int j = index; j < numBalas - 1; j++) {
                balas[j] = balas[j + 1];
            }

            numBalas--;
        }
    }

    
}

