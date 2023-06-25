#pragma once
#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "color.h"
#include "jugar.h"


using namespace std;
using namespace System;

void textoLento(char* texto) {
    while (*texto) {
        cout << *texto++;
        _sleep(15);
    }
}
void mostrarMenu()
{
    system("cls");


    asignarColor(8);

    cout << "\n\n\t\t\t\t\t\t"; cout << char(201) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
    cout << "\t\t\t\t\t\t"; cout << char(186); asignarColor(10); cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178); asignarColor(13); cout << " P O W E R ";
    asignarColor(10); cout << char(178) << char(178) << char(178) << char(178) << char(178); asignarColor(8); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; cout << char(186); asignarColor(10); cout << char(178) << char(178) << char(178) << char(178) << char(178); asignarColor(13); cout << "  S A V E R  ";
    asignarColor(10); cout << char(178) << char(178) << char(178) << char(178); asignarColor(8); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; cout << char(204) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(185) << endl;
    cout << "\t\t\t\t\t\t"; asignarColor(8); cout << char(186); asignarColor(13); cout << " 1.";
    asignarColor(10); cout << " Jugar             "; asignarColor(8); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; asignarColor(8); cout << char(186); asignarColor(13); cout << "  2.";
    asignarColor(10); cout << " Historia         "; asignarColor(8); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; asignarColor(8); cout << char(186); asignarColor(13); cout << "   3.";
    asignarColor(10); cout << " Instrucciones   "; asignarColor(8); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; asignarColor(8); cout << char(186); asignarColor(13); cout << "    4.";
    asignarColor(10); cout << " Creditos       "; asignarColor(8); cout << char(186) << endl;
    cout << "\t\t\t\t\t\t"; asignarColor(8); cout << char(186); asignarColor(13); cout << "     5.";
    asignarColor(10); cout << " Salir         "; asignarColor(8); cout << char(186) << endl;
    asignarColor(8);
    cout << "\t\t\t\t\t\t"; cout << char(200) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
        << char(205) << char(205) << char(205) << char(205) << char(188) << endl;

    asignarColor(14);
}

void jugar() {
    iniciarJuego();
}
void mostrarHistoria() {
    cout << "Historia del juego..." << endl;

}

void mostrarInstrucciones() {
    char* texto = "En PowerSaver, seras el heroe de la energia sostenible. Tu mision es ampliar \n\t\tla infraestructura energetica en paises poco desarrollados. Enfrentaras obstaculos,\n\t\tenemigos y contaras con poderes y aliados para lograrlo. A medida que avanzas, el\n\t\tjuego se vuelve más desafiante, haciendo que la experiencia sea aun mas emocionante.\n\t\tPreparate para convertirte en el salvador de la energia sostenible en PowerPlanet.";

    cout << "\n\n\n";
    cout << "\t    -------------------------------------------------------------------------------" << endl;
    cout << "\t      -----------------------------------------------------------------------------------" << endl;
    cout << "\t\t"; textoLento(texto);
    cout << "\n\t\t  -----------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;


    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPulsa una tecla para continuar...";
}
void mostrarCreditos() {
    char* texto = "\n\n\n\n\t1. Leandro Arevalo \n\n\t2. Nayara Maldonado\n\n\t3. Jorge Linares";
    asignarColor(4);
    cout << "\n\n\t\t\t\t           #";
    cout << "\n\t\t\t\t          ##.";
    cout << "\n\t\t\t\t     #    ####.        #";
    cout << "\n\t\t\t\t   .#     .######       #.";
    cout << "\n\t\t\t\t   ##      #######      ##";
    cout << "\n\t\t\t\t   ###       #####.    ###";
    cout << "\n\t\t\t\t   ####        ###    ####";
    cout << "\n\t\t\t\t    ######     #   ######";
    cout << "\n\t\t\t\t      #################";
    cout << "\n\t\t\t\t         ###########\n";
    asignarColor(14);
    textoLento(texto);
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPulsa una tecla para continuar...";

}


int mainMenu()
{
    int opcion;
    mostrarMenu();

    do
    {
        mostrarMenu();


        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        asignarColor(5);
        cout << "\t\t\t\t\t\t\t\t\t\t\t#########*#" << endl;
        asignarColor(12);
        cout << "\t\t\t\t\t\t\t\t\t\t\tIngrese una opcion: "; cin >> opcion;
        system("cls");

        asignarColor(14);
        switch (opcion)
        {
        case 1:
            jugar();
            _getch();

            // Aquí puedes llamar a la función para empezar el juego
            break;
        case 2:
            mostrarHistoria();
            _getch();
            system("cls");

            // Aquí puedes mostrar la historia del juego
            break;
        case 3:
            mostrarInstrucciones();
            _getch();
            system("cls");
            // Aquí puedes mostrar las instrucciones del juego
            break;
        case 4:
            mostrarCreditos();
            _getch();
            system("cls");
            // Aquí puedes mostrar los créditos del juego
            break;
        case 5:
            asignarColor(11);
            cout << "Game Over" << endl;
            cout << "Saliendo del juego..." << endl;
            asignarColor(14);

            break;
        default:
            asignarColor(11);
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
            cout << "\t\t\t\tOpcion invalida. Por favor, ingrese un numero valido." << endl;
            cout << "\t\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
            asignarColor(14);
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPulsa una tecla para continuar...";
            _getch();
            system("cls");
            break;
        }

        cout << endl;


    } while (opcion != 5);

    exit(0);
    return 0;
}
