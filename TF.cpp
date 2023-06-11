#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "menu.h"
#include "jugar.h"

using namespace System;
using namespace std;

int main()
{
    //setlocale(LC_ALL, "spanish");
    srand(time(0));
    mainMenu();
    system("pause>0");
    return 0;
}
