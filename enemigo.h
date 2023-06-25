#pragma once
#include <iostream>
#include "color.h"
#include "bala.h" // Agregar esta línea

using namespace System;
using namespace std;

struct Enemigo {
    int enemigoX = 20;
    int enemigoY = 15;
    float dx = 1;
    float dy = 1;
    string cabeza = "___";
    string cuerpo = "|O|";
    string pies =   "|O|";
    Bala* balas; // Agregar el atributo Bala* balas al struct
};

void dibujarEnemigo(Enemigo* enemigo, int posX, int posY) {
    enemigo->enemigoX = posX;
    enemigo->enemigoY = posY;
    asignarColor(11);
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY);
    cout << enemigo->cabeza;
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY + 1);
    cout << enemigo->cuerpo;
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY + 2);
    cout << enemigo->pies;
}

void eliminarEnemigo(Enemigo* enemigo, int posX, int posY) {
    enemigo->enemigoX = posX;
    enemigo->enemigoY = posY;
    asignarColor(8);
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY);
    cout << string(3, ' ');
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY + 1);
    cout << string(3, ' ');
    asignarPosicion(enemigo->enemigoX, enemigo->enemigoY + 2);
    cout << string(3, ' ');
}

//
//void movimientoEnemigoX(Enemigo* enemigo, int enemigoX, int enemigoY) {
//        
//        // Verificar si todas las posiciones están vacías
//        eliminarEnemigo(enemigo, enemigoX, enemigoY);
//
//        bool posicionesVacias = true;
//        for (int i = enemigoY; i < enemigoY + 3; i++) {
//            for (int j = enemigoX; j < enemigoX + 3; j++) {
//                if (mapa[i][j] == 1) {
//                    posicionesVacias = false;
//                    break;
//                }
//            }
//            if (!posicionesVacias) {
//                break;
//            }
//        }
//
//        if (posicionesVacias) {
//            // Actualizar la posición del personaje
//            enemigoX += enemigo->direccion;
//
//            // Verificar si el personaje llegó al límite del área de juego
//            if (enemigoX + 3 > COLUMNAS || enemigoX < 0) {
//                enemigo->direccion *= -1;  // Invertir la dirección
//                enemigoX += enemigo->direccion;
//            }
//        }
//        else {
//            // Invertir la dirección
//            enemigo->direccion *= -1;
//            // Actualizar la posición del personaje
//            enemigoX += enemigo->direccion;
//        }
//
//        // Dibujar el personaje en la nueva posición
//        dibujarEnemigo(enemigo, enemigoX, enemigoY);
//
//}

//bool validar_mov_enemigo(int mapa[FILAS][COLUMNAS], Enemigo* enemigo)
//{
//    if (mapa[int(enemigo->enemigo1Mapa1Y)][int(enemigo->enemigo1Mapa1X + 3)] != 0) {
//        return true;
//    }
//    return false;
//}