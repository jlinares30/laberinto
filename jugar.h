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
    Agente* agentes = new Agente[10];
    Bala* balas = new Bala[10];
    Aliado* aliado = new Aliado();
    int posX = 0; //110
    int posY = 1; // 22
    int posAliadoX = 28;
    int posAliadoY = 5;
    int posAliado2X = 57;
    int posAliado2Y = 12;
    int posAliado3X = 89;
    int posAliado3Y = 18;
    int posAliado4X = 33;
    int posAliado4Y = 8;
    int contadorTotalVitaminas = 0;
    int numVitaminasMapa1 = 2;
    int numVitaminasMapa2 = 3;
    int numVitaminasMapa3 = 5;
    

void iniciarJuego() {
    bool cambioMapa2 = false;
    bool cambioMapa3 = false;
    bool cambioMapa4 = false;
    bool juegoTerminado = false;
    bool ganador = false;
    int numAgentes = 10;
    bool mapaVitaminas[30][120] = {}; // inicializa un mapa con todos los valores de la matriz en falso


    personaje->balas = new Bala[MAX_BALAS];
    personaje->numBalas = 0;


    generarMapa(mapa);
    imprimirVidas(personaje);
    dibujarPersonaje(personaje, posX, posY);
    agentes[0].x = 19;
    agentes[0].y = 15;
    agentes[1].x = 50;
    agentes[1].y = 21;
    agentes[2].x = 58;
    agentes[2].y = 9;
    agentes[3].x = 2;
    agentes[3].y = 12;
    agentes[4].x = 47;
    agentes[4].y = 12;
    agentes[5].x = 76;
    agentes[5].y = 7;
    agentes[7].x = 31;
    agentes[7].y = 3;
    agentes[6].x = 22;
    agentes[6].y = 15;
    agentes[8].x = 66;
    agentes[8].y = 15;
    agentes[9].x = 79;
    agentes[9].y = 23;

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
            moverBala(personaje->balas[i], mapa, personaje->numBalas, i, personaje->balas, agentes, numAgentes);
        }
        for (int i = 0; i < numAgentes; i++) {
            if (agentes[i].tiempoInactividad > 0) {
                agentes[i].tiempoInactividad--;

                // Si el tiempo de inactividad llega a cero, reanudar el movimiento
                if (agentes[i].tiempoInactividad == 0) {
                    // se asigna nuevas velocidades al agente
                    agentes[i].dx = 1;
                    agentes[i].dy = 1;
                }
            }
        }

        dibujarPersonaje(personaje, posX, posY);
        dibujarAliado(aliado, posAliadoX, posAliadoY);


        if (cambioMapa2)
        {
            generarMapa(mapa2);
            posX = 0;
            posY = 1;
            imprimirVidas(personaje);
            break;
        }

        // movimiento del enemigo
        borrar_agente(&agentes[0]);
        mover_agenteX(&agentes[0], mapa);
        dibujar_agente(&agentes[0]);
        for (int i = 1; i < 3; i++)
        {
            borrar_agente(&agentes[i]);
            mover_agenteY(&agentes[i], mapa);
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



        // colision aliado-personaje
            if (posX == posAliadoX && posY == posAliadoY)
            {
                // Realizar acciones cuando hay colisión con el aliado
                eliminarAliado(aliado, posAliadoX, posAliadoY);
                // Cambiar el valor de la pared al lado del aliado de 1 a 0 en el mapa
                mapa[posAliadoY][posAliadoX + 3] = 0; //Cambia la coordenada de la pared a 0 en la linea de la cabeza del aliado
                mapa[posAliadoY][posAliadoX + 4] = 0; //Cambia la segunda coordenada de la pared a 0 en la linea de la cabeza del aliado
                mapa[posAliadoY+1][posAliadoX + 3] = 0; //Cambia la coordenada de la pared a 0 en la linea del cuerpo del aliado
                mapa[posAliadoY+1][posAliadoX + 4] = 0;//Cambia la segunda coordenada de la pared a 0 en la linea del cuerpo del aliado
                mapa[posAliadoY+2][posAliadoX + 3] = 0;//Cambia la coordenada de la pared a 0 en la linea de los pies del aliado
                mapa[posAliadoY+2][posAliadoX + 4] = 0;//Cambia la segunda coordenada de la pared a 0 en la linea de los pies del aliado

                
            }


        // Cambio de mapa si consigue todas las vitaminas y llega al final del laberinto
        if ((posY == 23 && posX == 112)&& (contadorTotalVitaminas == numVitaminasMapa1))
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
                        contadorTotalVitaminas++;
                        imprimirVidas(personaje);
                        mapaVitaminas[mapaY][mapaX] = true; // si cualquier parte del personaje pasa por la coordenada de la vitamina, la misma coordenada en el mapa de la vitamina se pone en true y solo lo contabiliza una vez
                    }
                }
            }
        }
        Sleep(50);
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

            if (tecla == DERECHA && (mapa2[posY][posX + 3] != 1 && mapa2[posY + 1][posX + 3] != 1 && mapa2[posY + 2][posX + 3] != 1)) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && (mapa2[posY][posX - 1] != 1 && mapa2[posY + 1][posX - 1] != 1 && mapa2[posY + 2][posX - 1] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapa2[posY - 1][posX] != 1 && mapa2[posY - 1][posX + 1] != 1 && mapa2[posY - 1][posX + 2] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posY--;
            }
            if (tecla == ABAJO && (mapa2[posY + 3][posX] != 1 && mapa2[posY + 3][posX + 1] != 1 && mapa2[posY + 3][posX + 2] != 1))
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
            moverBala(personaje->balas[i], mapa2, personaje->numBalas, i, personaje->balas, agentes, numAgentes);
        }
        for (int i = 0; i < numAgentes; i++) {
            if (agentes[i].tiempoInactividad > 0) {
                agentes[i].tiempoInactividad--;

                // Si el tiempo de inactividad llega a cero, reanudar el movimiento
                if (agentes[i].tiempoInactividad == 0) {
                    // se asigna nuevas velocidades al agente
                    agentes[i].dx = 1;
                    agentes[i].dy = 1;
                }
            }
        }

        dibujarPersonaje(personaje, posX, posY);
        dibujarAliado(aliado, posAliado2X, posAliado2Y);

        if (cambioMapa3)
        {
            generarMapa3(mapa3);
            posX = 0;
            posY = 1;
            imprimirVidas(personaje);
            break;
        }

        // movimiento del enemigo
        borrar_agente(&agentes[3]);
        mover_agenteX(&agentes[3], mapa2);
        dibujar_agente(&agentes[3]);
        for (int i = 4; i < 6; i++)
        {
            borrar_agente(&agentes[i]);
            mover_agenteY(&agentes[i], mapa2);
            dibujar_agente(&agentes[i]);
        }

        //Colision agente-personaje
        bool colision = false;

        // Verificar colisión en cada posición del personaje y enemigo
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((posY + i >= agentes[3].y && posY + i <= agentes[3].y + 1 && posX + j == agentes[3].x) ||
                    (posY + i >= agentes[4].y && posY + i <= agentes[4].y + 1 && posX + j == agentes[4].x) ||
                    (posY + i >= agentes[5].y && posY + i <= agentes[5].y + 1 && posX + j == agentes[5].x))
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
        // colision aliado-personaje
        if (posX == posAliado2X && posY == posAliado2Y)
        {
            // Realizar acciones cuando hay colisión con el aliado
            eliminarAliado(aliado, posAliado2X, posAliado2Y);
            // Cambiar el valor de la pared al lado del aliado de 1 a 0 en el mapa
            mapa2[posAliado2Y][posAliado2X + 3] = 0; //Cambia la coordenada de la pared a 0 en la linea de la cabeza del aliado
            mapa2[posAliado2Y][posAliado2X + 4] = 0; //Cambia la segunda coordenada de la pared a 0 en la linea de la cabeza del aliado
            mapa2[posAliado2Y + 1][posAliado2X + 3] = 0; //Cambia la coordenada de la pared a 0 en la linea del cuerpo del aliado
            mapa2[posAliado2Y + 1][posAliado2X + 4] = 0;//Cambia la segunda coordenada de la pared a 0 en la linea del cuerpo del aliado
            mapa2[posAliado2Y + 2][posAliado2X + 3] = 0;//Cambia la coordenada de la pared a 0 en la linea de los pies del aliado
            mapa2[posAliado2Y + 2][posAliado2X + 4] = 0;//Cambia la segunda coordenada de la pared a 0 en la linea de los pies del aliado


        }
        // Cambio de mapa si consigue todas las vitaminas y llega al final del laberinto
        if ((posY == 23 && posX == 112) && (contadorTotalVitaminas == numVitaminasMapa2))
        {
            cambioMapa3 = true;
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

                    if (mapa2[mapaY][mapaX] == 5 && !mapaVitaminas[mapaY][mapaX])
                    {
                        if (personaje->contVidas < 3)
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

        Sleep(50);
    }
    if (juegoTerminado) {
        imprimir_mensaje_perdedor();
        getch();
    }
    // --------------------------------------------- BUCLE DEL TERCER MAPA-----------------------------------------
    while (3)
    {
        if (kbhit()) {
            char tecla = getch();

            if (tecla == DERECHA && (mapa3[posY][posX + 3] != 1 && mapa3[posY + 1][posX + 3] != 1 && mapa3[posY + 2][posX + 3] != 1)) {
                borrarPersonaje(personaje, posX, posY);
                posX++;
            }

            if (tecla == IZQUIERDA && (mapa3[posY][posX - 1] != 1 && mapa3[posY + 1][posX - 1] != 1 && mapa3[posY + 2][posX - 1] != 1))
            {
                borrarPersonaje(personaje, posX, posY);
                posX--;
            }
            if (tecla == ARRIBA && (mapa3[posY - 1][posX] != 1 && mapa3[posY - 1][posX + 1] != 1 && mapa3[posY - 1][posX + 2] != 1))
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
            moverBala(personaje->balas[i], mapa3, personaje->numBalas, i, personaje->balas, agentes, numAgentes);
        }
        for (int i = 0; i < numAgentes; i++) {
            if (agentes[i].tiempoInactividad > 0) {
                agentes[i].tiempoInactividad--;

                // Si el tiempo de inactividad llega a cero, reanudar el movimiento
                if (agentes[i].tiempoInactividad == 0) {
                    // se asigna nuevas velocidades al agente
                    agentes[i].dx = 1;
                    agentes[i].dy = 1;
                }
            }
        }

        dibujarPersonaje(personaje, posX, posY);
        dibujarAliado(aliado, posAliado3X, posAliado3Y);
        dibujarAliado(aliado, posAliado4X, posAliado4Y);

        // movimiento del enemigo
        borrar_agente(&agentes[6]);
        mover_agenteX(&agentes[6], mapa3);
        dibujar_agente(&agentes[6]);
        for (int i = 7; i < 10; i++)
        {
            borrar_agente(&agentes[i]);
            mover_agenteY(&agentes[i], mapa3);
            dibujar_agente(&agentes[i]);
        }
        //Colision agente-personaje
        bool colision = false;

        // Verificar colisión en cada posición del personaje y enemigo
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((posY + i >= agentes[6].y && posY + i <= agentes[6].y + 1 && posX + j == agentes[6].x) ||
                    (posY + i >= agentes[7].y && posY + i <= agentes[7].y + 1 && posX + j == agentes[7].x) ||
                    (posY + i >= agentes[8].y && posY + i <= agentes[8].y + 1 && posX + j == agentes[8].x) ||
                    (posY + i >= agentes[9].y && posY + i <= agentes[9].y + 1 && posX + j == agentes[9].x))
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
        // colision aliado3-personaje
        if (posX == posAliado3X && posY == posAliado3Y)
        {
            // Realizar acciones cuando hay colisión con el aliado
            eliminarAliado(aliado, posAliado3X, posAliado3Y);
            // Cambiar el valor de la pared al lado del aliado de 1 a 0 en el mapa
            mapa3[posAliado3Y][posAliado3X + 3] = 0; //Cambia la coordenada de la pared a 0 en la linea de la cabeza del aliado
            mapa3[posAliado3Y][posAliado3X + 4] = 0; //Cambia la segunda coordenada de la pared a 0 en la linea de la cabeza del aliado
            mapa3[posAliado3Y + 1][posAliado3X + 3] = 0; //Cambia la coordenada de la pared a 0 en la linea del cuerpo del aliado
            mapa3[posAliado3Y + 1][posAliado3X + 4] = 0;//Cambia la segunda coordenada de la pared a 0 en la linea del cuerpo del aliado
            mapa3[posAliado3Y + 2][posAliado3X + 3] = 0;//Cambia la coordenada de la pared a 0 en la linea de los pies del aliado
            mapa3[posAliado3Y + 2][posAliado3X + 4] = 0;//Cambia la segunda coordenada de la pared a 0 en la linea de los pies del aliado


        }
        //colision aliado4-personaje
        if (posX == posAliado4X && posY == posAliado4Y)
        {
            // Realizar acciones cuando hay colisión con el aliado
            eliminarAliado(aliado, posAliado4X, posAliado4Y);
            // Cambiar el valor de la pared al lado del aliado de 1 a 0 en el mapa
            mapa3[posAliado4Y][posAliado4X + 3] = 0; //Cambia la coordenada de la pared a 0 en la linea de la cabeza del aliado
            mapa3[posAliado4Y][posAliado4X + 4] = 0; //Cambia la segunda coordenada de la pared a 0 en la linea de la cabeza del aliado
            mapa3[posAliado4Y + 1][posAliado4X + 3] = 0; //Cambia la coordenada de la pared a 0 en la linea del cuerpo del aliado
            mapa3[posAliado4Y + 1][posAliado4X + 4] = 0;//Cambia la segunda coordenada de la pared a 0 en la linea del cuerpo del aliado
            mapa3[posAliado4Y + 2][posAliado4X + 3] = 0;//Cambia la coordenada de la pared a 0 en la linea de los pies del aliado
            mapa3[posAliado4Y + 2][posAliado4X + 4] = 0;//Cambia la segunda coordenada de la pared a 0 en la linea de los pies del aliado


        }

        // Cambio de mapa si consigue todas las vitaminas y llega al final del laberinto
        if ((posY == 23 && posX == 112) && (contadorTotalVitaminas == numVitaminasMapa3))
        {
            ganador = true;
            break;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int mapaX = posX + j;
                    int mapaY = posY + i;

                    if (mapa3[mapaY][mapaX] == 5 && !mapaVitaminas[mapaY][mapaX])
                    {
                        if (personaje->contVidas < 3)
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

        Sleep(50);
    }
    if (ganador)
    {
        imprimir_mensaje_ganador();
        getch();
    }
    if (juegoTerminado) {
        imprimir_mensaje_perdedor();
        getch();
    }

    delete personaje;
    delete[] personaje->balas;
    delete[] agentes;
}
