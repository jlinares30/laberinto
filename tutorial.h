#pragma once

#include <conio.h>
#include <Windows.h>
#include "enemigo.h"
#include "aliado.h"
#include "agente.h"
#include "personaje.h"
#include "mapaTuto.h"



//int posAliadoX = 25;
//int posAliadoY = 2;
//Generar posición inicial del enemigo
//int enemigoX;
//int enemigoY;

int tutoMain() {
    bool mapaDisparo = false;
    bool mapaVitaminas[20][120] = {}; // inicializa un mapa con todos los valores de la matriz en falso
    int contadorTotalVitaminasTuto = 0;


    personaje->balas = new Bala[MAX_BALAS];
    personaje->numBalas = 0;

    generarMapaTutoMovimiento(mapatuto);
    dibujarPersonaje(personaje, posX, posY);

    while (1) {
        if (kbhit()) {
            char tecla = getch();

            if (tecla == DERECHA && (mapatuto[posY][posX + 3] != 1 && mapatuto[posY + 1][posX + 3] != 1 && mapatuto[posY + 2][posX + 3] != 1)) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && (mapatuto[posY][posX - 1] != 1 && mapatuto[posY + 1][posX - 1] != 1 && mapatuto[posY + 2][posX - 1] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapatuto[posY - 1][posX] != 1 && mapatuto[posY - 1][posX + 1] != 1 && mapatuto[posY - 1][posX + 2] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posY--;
            }
            if (tecla == ABAJO && (mapatuto[posY + 3][posX] != 1 && mapatuto[posY + 3][posX + 1] != 1 && mapatuto[posY + 3][posX + 2] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posY++;
            }

            if (tecla == 'D' || tecla == 'd')
            {
                disparar(personaje);
            }
        }
        dibujarPersonaje(personaje, posX, posY);


        if (posX +3  == 114)
        {
            posX = 0;
            posY = 1;
            break;

        }

        Sleep(10);
    }
    generarMapaTutoMovimiento(mapatutoDisparo);

    while (2) {
        if (kbhit()) {
            char tecla = getch();

            if (tecla == DERECHA && (mapatutoDisparo[posY][posX + 3] != 1 && mapatutoDisparo[posY + 1][posX + 3] != 1 && mapatutoDisparo[posY + 2][posX + 3] != 1)) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && (mapatutoDisparo[posY][posX - 1] != 1 && mapatutoDisparo[posY + 1][posX - 1] != 1 && mapatutoDisparo[posY + 2][posX - 1] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapatutoDisparo[posY - 1][posX] != 1 && mapatutoDisparo[posY - 1][posX + 1] != 1 && mapatutoDisparo[posY - 1][posX + 2] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posY--;
            }
            if (tecla == ABAJO && (mapatutoDisparo[posY + 3][posX] != 1 && mapatutoDisparo[posY + 3][posX + 1] != 1 && mapatutoDisparo[posY + 3][posX + 2] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posY++;
            }

            if (tecla == 'D' || tecla == 'd')
            {
                disparar(personaje);
            }
        }
        dibujarPersonaje(personaje, posX, posY);

        for (int i = 0; i < personaje->numBalas; i++) {
            moverBala(personaje->balas[i], mapatutoDisparo, personaje->numBalas, i, personaje->balas, agentes, 9);
        }
        if (posX + 3 == 114)
        {
            posX = 0;
            posY = 1;
            imprimirVidasTutorial(personaje);
            break;

        }
        
        Sleep(10);
    }
    generarMapaTutoMovimiento(mapatutoVitamina);


    while (3) {
        if (kbhit()) {
            char tecla = getch();

            if (tecla == DERECHA && (mapatutoVitamina[posY][posX + 3] != 1 && mapatutoVitamina[posY + 1][posX + 3] != 1 && mapatutoVitamina[posY + 2][posX + 3] != 1)) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && (mapatutoVitamina[posY][posX - 1] != 1 && mapatutoVitamina[posY + 1][posX - 1] != 1 && mapatutoVitamina[posY + 2][posX - 1] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapatutoVitamina[posY - 1][posX] != 1 && mapatutoVitamina[posY - 1][posX + 1] != 1 && mapatutoVitamina[posY - 1][posX + 2] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posY--;
            }
            if (tecla == ABAJO && (mapatutoVitamina[posY + 3][posX] != 1 && mapatutoVitamina[posY + 3][posX + 1] != 1 && mapatutoVitamina[posY + 3][posX + 2] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posY++;
            }

            if (tecla == 'D' || tecla == 'd')
            {
                disparar(personaje);
            }
        }
        dibujarPersonaje(personaje, posX, posY);

       
        if ((posX + 3 == 114))
        {
            posX = 0;
            posY = 1;
            break;
            memset(mapaVitaminas, false, sizeof(mapaVitaminas)); // vuelve a inicializar la matriz de vitaminas en falso
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int mapaX = posX + j;
                    int mapaY = posY + i;

                    if (mapatutoVitamina[mapaY][mapaX] == 5 && !mapaVitaminas[mapaY][mapaX])
                    {
                        if (personaje->contVidasTuto < 3)
                        {
                            personaje->contVidasTuto++;
                        }
                        contadorTotalVitaminasTuto++;
                        imprimirVidasTutorial(personaje);
                        mapaVitaminas[mapaY][mapaX] = true; // si cualquier parte del personaje pasa por la coordenada de la vitamina, la misma coordenada en el mapa de la vitamina se pone en true y solo lo contabiliza una vez
                    }
                }
            }
        }
        Sleep(10);
    }

    return 0;
}