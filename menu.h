#pragma once
#include "pch.h"
#include <iostream>
#include <windows.h>
#include "color.h"


using namespace std;

// Función para establecer el color del texto en la consola de Windows
void setColor(int color);

void jugar();

void mostrarHistoria();
void mostrarInstrucciones();
void mostrarCreditos();

void mostrarMenu()
{
    //system("cls"); // Limpiar la consola en Windows (para otros sistemas operativos, se necesita otro enfoque)

    // Establecer el color del marco y las palabras
    asignarColor(14); // Amarillo
    cout << char(201) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
    cout << char(186) << "      P O W E R       " << char(186) << endl;
    cout << char(186) << "      P L A N E T     " << char(186) << endl;
    cout << char(204) << string(22, char(205)) << char(185) << endl;
    cout << char(186) << " 1. Jugar             " << char(186) << endl;
    cout << char(186) << " 2. Historia          " << char(186) << endl;
    cout << char(186) << " 3. Instrucciones     " << char(186) << endl;
    cout << char(186) << " 4. Créditos          " << char(186) << endl;
    cout << char(186) << " 5. Salir             " << char(186) << endl;
    cout << char(200) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(188) << endl;

    // Restaurar el color predeterminado
    asignarColor(7); // Blanco
}
int main()
{
    int opcion;

    do
    {

        mostrarMenu();
        asignarColor(11); // Cian
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            jugar();
            // Aquí puedes llamar a la función para empezar el juego
            break;
        case 2:
            mostrarHistoria();
            // Aquí puedes mostrar la historia del juego
            break;
        case 3:
            mostrarInstrucciones();
            // Aquí puedes mostrar las instrucciones del juego
            break;
        case 4:
            mostrarCreditos();
            // Aquí puedes mostrar los créditos del juego
            break;
        case 5:
            cout << "Saliendo del juego..." << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese un número válido." << endl;
            break;
        }

        cout << endl;


    } while (opcion != 5);

    return 0;
}
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void jugar()
{
    cout << "Iniciando el juego..." << endl;
    // Aquí puedes llamar a la función para empezar el juego
}

void mostrarHistoria()
{
    cout << "Historia del juego..." << endl;
    // Aquí puedes mostrar la historia del juego
}

void mostrarInstrucciones()
{
    cout << "Instrucciones del juego..." << endl;
    // Aquí puedes mostrar las instrucciones del juego
}

void mostrarCreditos()
{
    cout << "Créditos del juego..." << endl;
    // Aquí puedes mostrar los créditos del juego
}