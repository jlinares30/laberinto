#pragma once

#include <conio.h>
#include <Windows.h>
#include "enemigo.h"
#include "aliado.h"
#include "personaje.h"
#include "agente.h"
#include "mapa.h"
#include "mapa2.h"
#include "mapa3.h"
#include "mapa4.h"

Personaje* personaje = new Personaje();
    Enemigo* enemigo = new Enemigo();
    Agente* agentes = new Agente[3];
    Aliado* aliado = new Aliado();
    int posX = 0; //110
    int posY = 1; // 22
    int posAliadoX = 28;
    int posAliadoY = 5;
    // Generar posición inicial del enemigo
    int enemigoX;
    int enemigoY;
    int contadorTotalVitaminas = 0;
    int numVitaminasMapa1 = 2;
    int numVitaminasMapa2 = 3;
    int numVitaminasMapa3 = 4;
    

void iniciarJuego() {
    bool cambioMapa2 = false;
    bool cambioMapa3 = false;
    bool cambioMapa4 = false;
    bool juegoTerminado = false;
    bool mapaVitaminas[30][120] = {}; // inicializa un mapa con todos los valores de la matriz en falso


    personaje->balas = new Bala[MAX_BALAS];
    personaje->numBalas = 0;


    generarMapa(mapa);
    imprimirVidas(personaje);
    dibujarPersonaje(personaje, posX, posY);
    dibujarAliado(aliado, posAliadoX, posAliadoY);
    agentes[0].x = 19;
    agentes[0].y = 15;
    agentes[1].x = 50;
    agentes[1].y = 21;
    agentes[2].x = 58;
    agentes[2].y = 9;

    while (1) {
        if (kbhit()) {
            char tecla = getch();

            if (tecla == DERECHA && (mapa[posY][posX + 3] != 1 && mapa[posY + 1][posX + 3] != 1 && mapa[posY + 2][posX + 3] != 1)) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && (mapa[posY][posX - 1] != 1 && mapa[posY + 1][posX - 1] != 1 && mapa[posY + 2][posX - 1] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapa[posY - 1][posX] != 1 && mapa[posY - 1][posX + 1] != 1 && mapa[posY - 1][posX + 2] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posY--;
            }
            if (tecla == ABAJO && (mapa[posY + 3][posX] != 1 && mapa[posY + 3][posX + 1] != 1 && mapa[posY + 3][posX + 2] != 1))
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

        // movimiento del enemigo
        borrar_agente(&agentes[0]);
        mover_agenteX(&agentes[0]);
        dibujar_agente(&agentes[0]);
        for (int i = 1; i < 3; i++)
        {
            borrar_agente(&agentes[i]);
            mover_agenteY(&agentes[i]);
            dibujar_agente(&agentes[i]);
        }
            
    
        //Colision agente-personaje
            bool colision = false;

            // Verificar colisión en cada posición del personaje y enemigo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if ((posY + i >= agentes[0].y && posY + i <= agentes[0].y + 1 && posX + j == agentes[0].x) ||
                        (posY + i >= agentes[1].y && posY + i <= agentes[1].y + 1 && posX + j == agentes[1].x) ||
                        (posY + i >= agentes[2].y && posY + i <= agentes[2].y + 1 && posX + j == agentes[2].x))
                    {
                        colision = true;
                        personaje->contVidas--;
                        imprimirVidas(personaje);
                        borrarPersonaje(personaje, posX, posY);
                        posX = 0;
                        posY = 1;
                        break;
                    }
                }
                if (colision) {
                    break;
                }
            }
            if (personaje->contVidas < 1)
            {
                juegoTerminado = true;
                break;
            }

            //colision bala-agente
            

        // colision aliado-personaje
            if (posX == posAliadoX && posY == posAliadoY)
            {
                // Realizar acciones cuando hay colisión con el aliado
                eliminarAliado(aliado, posAliadoX, posAliadoY);
                asignarColor(13);
                // Cambiar el valor de la pared al lado del aliado de 1 a 0 en el mapa
                mapa[posAliadoY][posAliadoX + 3] = 0;
                mapa[posAliadoY][posAliadoX + 4] = 0;
                mapa[posAliadoY+1][posAliadoX + 3] = 0;
                mapa[posAliadoY+1][posAliadoX + 4] = 0;
                mapa[posAliadoY+2][posAliadoX + 3] = 0;
                mapa[posAliadoY+2][posAliadoX + 4] = 0;

                
            }


        // Cambio de mapa si consigue todas las vitaminas y llega al final del laberinto
        if ((posY == 23 && posX == 112) && (contadorTotalVitaminas == numVitaminasMapa1))
        {
            cambioMapa2 = true;
            contadorTotalVitaminas = 0;
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

                    if (mapa[mapaY][mapaX] == 5 && !mapaVitaminas[mapaY][mapaX])
                    {
                        if (personaje->contVidas<3)
                        {
                            personaje->contVidas++;
                        }
                        imprimirVidas(personaje);
                        contadorTotalVitaminas++;
                        mapaVitaminas[mapaY][mapaX] = true; // si cualquier parte del personaje pasa por la coordenada de la vitamina, la misma coordenada en el mapa de la vitamina se pone en true y solo lo contabiliza una vez
                    }
                }
            }
        }
        Sleep(100);
    }
    if (juegoTerminado) {
        imprimir_mensaje_perdedor();
        getch();
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
