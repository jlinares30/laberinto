#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "utilidades.h"
#include "mapa.h"
#include "mapa2.h"
#include "mapa3.h"
#include "mapa4.h"

using namespace std;
using namespace System;


struct Agente {
    float x;
    float y;
    float dx = 1;
    float dy = 1;
    int tiempoInactividad;
};



void dibujar_agente(Agente* agente)
{
    Console::ForegroundColor = ConsoleColor::Red;
    ubicar(agente->x, agente->y); cout << (char)219;
    ubicar(agente->x, agente->y + 1); cout << (char)219;
    Console::ForegroundColor = ConsoleColor::White;
}

void borrar_agente(Agente* agente)
{
    ubicar(agente->x, agente->y); cout << " ";
    ubicar(agente->x, agente->y + 1); cout << " ";
}


bool validar_mov_agente_horizontal(int mapa[FILAS][COLUMNAS], Agente* agente)
{
    if (mapa[(int)agente->y][(int)(agente->x + agente->dx)] != 0) {
        return true;
    }
    return false;
}

bool validar_mov_agente_vertical(int mapa[FILAS][COLUMNAS], Agente* agente)
{
    if (mapa[(int)agente->y-1][(int)(agente->x)] != 0 || mapa[(int)agente->y+2][(int)agente->x] != 0) {
        return true;
    }

    return false;
}


void mover_agenteX(Agente* agente, int mapa[FILAS][COLUMNAS])
{

    if (validar_mov_agente_horizontal(mapa, agente)) {
        agente->dx *= -1;
    }
    agente->x += agente->dx;

}

void mover_agenteY(Agente* agente, int mapa[FILAS][COLUMNAS]) {
    if (validar_mov_agente_vertical(mapa, agente)) {
        agente->dy *= -1;
    }
    agente->y += agente->dy;

}

void eliminar_agente(Agente* agente)
{
    borrar_agente(agente);
    delete agente;
}