#pragma once

#include <conio.h>
#include <Windows.h>
#include "enemigo.h"
#include "aliado.h"
#include "personaje.h"
#include "mapa.h"


void iniciarJuego() {
    Personaje* personaje = new Personaje();
    Enemigo* enemigo = new Enemigo();
    Aliado* aliado = new Aliado();
    int posX = 0;
    int posY = 1;
    int posAliadoX = 25;
    int posAliadoY = 2;
    // Generar posición inicial del enemigo
    int enemigoX;
    int enemigoY;
    do
    {
        enemigoX = rand() % 118 + 1;
        enemigoY = rand() % 28 + 1;
    } while (mapa[enemigoY][enemigoX] == 1);
    


    personaje->balas = new Bala[MAX_BALAS];
    personaje->numBalas = 0;


    generarMapa(mapa);
    dibujarPersonaje(personaje, posX, posY);
    dibujarAliado(aliado, posAliadoX, posAliadoY);

    while (1) {
        if (kbhit()) {
            char tecla = getch();

            if (tecla == DERECHA && (mapa[posY][posX + 3] == 0 && mapa[posY + 1][posX + 3] == 0 && mapa[posY + 2][posX + 3] == 0)) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && (mapa[posY][posX - 1] == 0 && mapa[posY + 1][posX - 1] == 0 && mapa[posY + 2][posX - 1] == 0))
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapa[posY - 1][posX] == 0 && mapa[posY - 1][posX + 1] == 0 && mapa[posY - 1][posX + 2] == 0))
            {
                borrarPersonaje(personaje, posX, posY);
                posY--;
            }
            if (tecla == ABAJO && (mapa[posY + 3][posX] == 0 && mapa[posY + 3][posX + 1] == 0 && mapa[posY + 3][posX + 2] == 0))
            {
                borrarPersonaje(personaje, posX, posY);
                posY++;
            }

            if (tecla == 'D' || tecla == 'd')
            {
                disparar(personaje);
            }
        }

        for (int i = 0; i < personaje->numBalas; i++) {
            moverBala(personaje->balas[i], mapa, personaje->numBalas, i, personaje->balas);
        }

        dibujarPersonaje(personaje, posX, posY);
        
        // movimiento aleatorio del enemigo

        dibujarEnemigo(enemigo, enemigoX, enemigoY);


        int direccion = rand() % 4;  

        switch (direccion) {
        case 0:  // Izquierda
            if (mapa[enemigoY][enemigoX - 1] == 0 && mapa[enemigoY + 1][enemigoX - 1] == 0 && mapa[enemigoY + 2][enemigoX - 1] == 0) {
                eliminarEnemigo(enemigo, enemigoX, enemigoY);
                enemigoX--;
            }
            break;
        case 1:  // Derecha
            if (mapa[enemigoY][enemigoX + 3] == 0 && mapa[enemigoY + 1][enemigoX + 3] == 0 && mapa[enemigoY + 2][enemigoX + 3] == 0) {
                eliminarEnemigo(enemigo, enemigoX, enemigoY);
                enemigoX++;
            }
            break;
        case 2:  // Arriba
            if (mapa[enemigoY - 1][enemigoX] == 0 && mapa[enemigoY - 1][enemigoX + 1] == 0 && mapa[enemigoY - 1][enemigoX + 2] == 0) {
                eliminarEnemigo(enemigo, enemigoX, enemigoY);
                enemigoY--;
            }
            break;
        case 3:  // Abajo
            if (mapa[enemigoY + 3][enemigoX] == 0 && mapa[enemigoY + 3][enemigoX + 1] == 0 && mapa[enemigoY + 3][enemigoX + 2] == 0) {
                eliminarEnemigo(enemigo, enemigoX, enemigoY);
                enemigoY++;
            }
            break;
        }

        dibujarEnemigo(enemigo, enemigoX, enemigoY);


        Sleep(100);
    }

    delete personaje;
    delete[] personaje->balas;
}
