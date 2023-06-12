#pragma once

#include <conio.h>
#include <Windows.h>
#include "enemigo.h"
#include "aliado.h"
#include "personaje.h"
#include "mapa.h"
#include "mapa2.h"
#include "mapa3.h"
#include "mapa4.h"

Personaje* personaje = new Personaje();
    Enemigo* enemigo = new Enemigo();
    Aliado* aliado = new Aliado();
    int posX = 0;
    int posY = 1;
    int posAliadoX = 25;
    int posAliadoY = 2;
    // Generar posici�n inicial del enemigo
    int enemigoX;
    int enemigoY;

void iniciarJuego() {
    bool cambioMapa2 = false;
    bool cambioMapa3 = false;
    bool cambioMapa4 = false;
    do
    {
        enemigoX = rand() % 111 + 1;
        enemigoY = rand() % 25 + 1;
    } while (mapa[enemigoY][enemigoX] == 1 || mapa[enemigoY+1][enemigoX] == 1 || mapa[enemigoY + 2][enemigoX] == 1 || mapa[enemigoY][enemigoX + 1] == 1 || mapa[enemigoY +1][enemigoX + 1] == 1 || mapa[enemigoY + 2][enemigoX + 1] == 1 || mapa[enemigoY][enemigoX + 2] == 1 || mapa[enemigoY + 1][enemigoX + 2] == 1 || mapa[enemigoY + 2][enemigoX + 2] == 1 || cambioMapa2 == true || cambioMapa3 == true || cambioMapa4 == true);
    


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
        
        if (cambioMapa2)
        {
            generarMapa(mapa2);
            posX = 0;
            posY = 1;
            break;
        }

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

        if (posY == 23 && posX == 112)
        {
            cambioMapa2 = true;
        }

        Sleep(100);
    }

    // ------------------------------------BUCLE DEL SEGUNDO MAPA--------------------------------------------------------

    while (2)
    {
        if (kbhit()) {
            char tecla = getch();

            if (tecla == DERECHA && (mapa2[posY][posX + 3] == 0 && mapa2[posY + 1][posX + 3] == 0 && mapa2[posY + 2][posX + 3] == 0)) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && (mapa2[posY][posX - 1] == 0 && mapa2[posY + 1][posX - 1] == 0 && mapa2[posY + 2][posX - 1] == 0))
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapa2[posY - 1][posX] == 0 && mapa2[posY - 1][posX + 1] == 0 && mapa2[posY - 1][posX + 2] == 0))
            {
                borrarPersonaje(personaje, posX, posY);
                posY--;
            }
            if (tecla == ABAJO && (mapa2[posY + 3][posX] == 0 && mapa2[posY + 3][posX + 1] == 0 && mapa2[posY + 3][posX + 2] == 0))
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
            moverBala(personaje->balas[i], mapa2, personaje->numBalas, i, personaje->balas);
        }

        dibujarPersonaje(personaje, posX, posY);

        if (cambioMapa3)
        {
            generarMapa3(mapa3);
            posX = 0;
            posY = 1;
            break;
        }


        if (posY == 23 && posX == 112)
        {
            cambioMapa3 = true;
        }

        Sleep(100);
    }

    // --------------------------------------------- BUCLE DEL TERCER MAPA-----------------------------------------
    while (3)
    {
        if (kbhit()) {
            char tecla = getch();

            if (tecla == DERECHA && (mapa3[posY][posX + 3] == 0 && mapa3[posY + 1][posX + 3] == 0 && mapa3[posY + 2][posX + 3] == 0)) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && (mapa3[posY][posX - 1] == 0 && mapa3[posY + 1][posX - 1] == 0 && mapa3[posY + 2][posX - 1] == 0))
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapa3[posY - 1][posX] == 0 && mapa3[posY - 1][posX + 1] == 0 && mapa3[posY - 1][posX + 2] == 0))
            {
                borrarPersonaje(personaje, posX, posY);
                posY--;
            }
            if (tecla == ABAJO && (mapa3[posY + 3][posX] == 0 && mapa3[posY + 3][posX + 1] == 0 && mapa3[posY + 3][posX + 2] == 0))
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
            moverBala(personaje->balas[i], mapa3, personaje->numBalas, i, personaje->balas);
        }

        dibujarPersonaje(personaje, posX, posY);

        if (cambioMapa4)
        {
            generarMapa4(mapa4);
            posX = 0;
            posY = 11;
            break;
        }

        if (posY == 23 && posX == 112)
        {
            cambioMapa4 = true;
        }

        Sleep(100);
    }

    // ------------------------------------------------BUCLE DEL CUARTO MAPA------------------------------------
    while (4)
    {
        if (kbhit()) {
            char tecla = getch();

            if (tecla == DERECHA && (mapa4[posY][posX + 3] == 0 && mapa4[posY + 1][posX + 3] == 0 && mapa4[posY + 2][posX + 3] == 0)) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && (mapa4[posY][posX - 1] == 0 && mapa4[posY + 1][posX - 1] == 0 && mapa4[posY + 2][posX - 1] == 0))
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapa4[posY - 1][posX] == 0 && mapa4[posY - 1][posX + 1] == 0 && mapa4[posY - 1][posX + 2] == 0))
            {
                borrarPersonaje(personaje, posX, posY);
                posY--;
            }
            if (tecla == ABAJO && (mapa4[posY + 3][posX] == 0 && mapa4[posY + 3][posX + 1] == 0 && mapa4[posY + 3][posX + 2] == 0))
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
            moverBala(personaje->balas[i], mapa4, personaje->numBalas, i, personaje->balas);
        }

        dibujarPersonaje(personaje, posX, posY);

        // movimiento aleatorio del enemigo

        dibujarEnemigo(enemigo, enemigoX, enemigoY);


        int direccion = rand() % 4;

        switch (direccion) {
        case 0:  // Izquierda
            if (mapa4[enemigoY][enemigoX - 1] == 0 && mapa4[enemigoY + 1][enemigoX - 1] == 0 && mapa4[enemigoY + 2][enemigoX - 1] == 0) {
                eliminarEnemigo(enemigo, enemigoX, enemigoY);
                enemigoX--;
            }
            break;
        case 1:  // Derecha
            if (mapa4[enemigoY][enemigoX + 3] == 0 && mapa4[enemigoY + 1][enemigoX + 3] == 0 && mapa4[enemigoY + 2][enemigoX + 3] == 0) {
                eliminarEnemigo(enemigo, enemigoX, enemigoY);
                enemigoX++;
            }
            break;
        case 2:  // Arriba
            if (mapa4[enemigoY - 1][enemigoX] == 0 && mapa4[enemigoY - 1][enemigoX + 1] == 0 && mapa4[enemigoY - 1][enemigoX + 2] == 0) {
                eliminarEnemigo(enemigo, enemigoX, enemigoY);
                enemigoY--;
            }
            break;
        case 3:  // Abajo
            if (mapa4[enemigoY + 3][enemigoX] == 0 && mapa4[enemigoY + 3][enemigoX + 1] == 0 && mapa4[enemigoY + 3][enemigoX + 2] == 0) {
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
