#pragma once

#include <conio.h>
#include <Windows.h>
#include "personaje.h"
#include "mapa.h"

void jugar() {
    Personaje* personaje = new Personaje();
    int posX = 1;
    int posY = 25;

    personaje->balas = new Bala[MAX_BALAS];
    personaje->numBalas = 0;



    generarMapa(mapa);
    dibujarPersonaje(personaje, posX, posY);



    while (1) {
        if (kbhit()) {
            char tecla = getch();

            if (tecla == DERECHA && mapa[posY][posX + 3] == 0) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && mapa[posY][posX - 1] == 0)
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapa[posY - 3][posX] == 0 && mapa[posY - 3][posX + 1] == 0 && mapa[posY - 3][posX + 2] == 0))
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

        Sleep(100);
    }

    delete personaje;
    delete[] personaje->balas;
}
