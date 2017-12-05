#include "Sintactico.h"

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

Sintactico::Sintactico()
{
    pila.clear();
    pila.push_back(23);
    pila.push_back(0);
//    idReglas.push_back(3);
//    idReglas.push_back(3);
//    lonReglas.push_back(3);
//    lonReglas.push_back(0);
}

Sintactico::~Sintactico()
{
    //dtor
}

void Sintactico::MostrarPila()
{
    for(unsigned int i=0;i<pila.size();i++)
        cout << pila.at(i) << " ";
    cout << endl;
}

int Sintactico::obtenerColumnaTipo(int tipo)
{
    int columna;
    switch(tipo)
    {
   case 0:
    columna = 0;
    break;
   case 5:
    columna = 1;
    break;
   case 23:
    columna = 2;
    break;
   default:
       columna = -1;
    break;
    }
    return columna;
}


