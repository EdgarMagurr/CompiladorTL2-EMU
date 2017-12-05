#ifndef SINTACTICO_H_INCLUDED
#define SINTACTICO_H_INCLUDED

#include <iostream>
#include <fstream>

#include "pila.h"
#include "lista_tokens.h"
#include "reglas.h"

using namespace std;

class Sintacico{
    public:
        Pila pila;
        int **tablaLR;
        int idReglas[60], longReglas[60];
        string nomReglas[60];
    public:
        Regla* sint(lista<tokens>);
};

Regla* Sintacico::sint(lista<tokens> datos){
    bool aceptacion;
    int fila, columna, accion, num, cont = 0;
    char cadena[1000];
    string palabra, actual;
    Regla *nd;

    ifstream llenar("compilador.lr");

    if(!llenar.good()){
        cout << "error";
    }
    else{
        //leemos la primera linea que tiene el numero de elementos de las reglas
        llenar.getline((char*)&cadena, 100);
        accion = atoi(cadena);

        //llenamos los arreglos
        for(int i = 0; i < accion; i++){
            llenar.getline((char*)&cadena, 100);

            while(cadena[cont] != '\t'){
                actual = cadena[cont];
                palabra.append(actual);
                cont ++;
            }

            num = atoi(palabra.c_str());
            idReglas[i] = num;
            cont ++;
            palabra.clear();

            while(cadena[cont] != '\t'){
                actual = cadena[cont];
                palabra.append(actual);
                cont ++;
            }

            num = atoi(palabra.c_str());
            longReglas[i] = num;
            cont ++;
            palabra.clear();

            while(cadena[cont] != '\0'){
                actual = cadena[cont];
                palabra.append(actual);
                cont ++;
            }

            nomReglas[i] = palabra;
            palabra.clear();
            cont = 0;
        }

        //leemos las filas y las columnas de la tabla LR
        llenar.getline((char *)& cadena, 100);

        while(cadena[cont] != '\t'){
            actual = cadena[cont];
            palabra.append(actual);
            cont ++;
        }

        fila = atoi(palabra.c_str());
        cont ++;
        palabra.clear();

        while(cadena[cont] != '\0'){
            actual = cadena[cont];
            palabra.append(actual);
            cont ++;
        }

        columna = atoi(palabra.c_str());
        palabra.clear();
        cont = 0;

        //creamos la matriz
        tablaLR = new int*[fila];

        for(int i = 0; i < fila; i++){
            tablaLR[i] = new int[columna];
        }

        for(int f = 0; f < fila; f++){
            llenar.getline((char*)&cadena, 1000);

            for(int c = 0; c < columna; c++){
                while(cadena[cont] != '\t' and cadena[cont] != '\0'){
                    actual = cadena[cont];
                    palabra.append(actual);
                    cont ++;
                }

                tablaLR[f][c] = atoi(palabra.c_str());
                cont ++;
                palabra.clear();
            }
            cont = 0;
        }

        llenar.close();
    }

    pila.push(new Terminal(datos.primero()->getdato().getTK()));
    pila.push(new Estado(0));

    while(!aceptacion and !datos.vacia()){
        fila = pila.top()->getEstado();
        columna = datos.ultimo()->getdato().getID();
        accion = tablaLR[fila][columna];

        //pila.muestra();
        //cout << "Fila: " << fila << " Columna: " << columna << endl;
        //cout << "\nentrada: " << datos.ultimo()->getdato().getTK() << endl;
        //cout << "accion: " << accion << "\n\n";

        aceptacion = accion == -1;

        if (aceptacion){
            cout << "\naceptacion" << endl;
            //nd->muestra();
            return nd;
        }

        if(accion > 0){
            pila.push(new Terminal(datos.ultimo()->getdato().getTK()));
            pila.push(new Estado(accion));
            datos.elimina(datos.ultimo());
        }
        else if(accion < 0){

            cont = (-accion) - 2;

            //eleccion de estados actual
            switch(cont){
                case 1:
                case 6:
                case 9:
                case 11:
                case 14:
                case 18:
                case 25:
                case 28:
                case 30:
                case 32:
                    nd = NULL;
                break;
                case 0:
                    nd = new R1(pila);
                break;
                case 2:
                    nd = new R3(pila);
                break;
                case 3:
                    nd = new R4(pila);
                break;
                case 4:
                    nd = new R5(pila);
                break;
                case 5:
                    nd = new R6(pila);

                break;
                case 7:
                    nd = new R8(pila);
                break;
                case 8:
                    nd = new R9(pila);
                break;
                case 10:
                    nd = new R11(pila);
                break;
                case 12:
                    nd = new R13(pila);
                break;
                case 13:
                    nd = new R14(pila);
                break;
                case 15:
                    nd = new R16(pila);
                break;
                case 16:
                    nd = new R17(pila);
                break;
                case 17:
                    nd = new R18(pila);
                break;
                case 19:
                    nd = new R20(pila);
                break;
                case 20:
                    nd = new R21(pila);
                break;
                case 21:
                    nd = new R22(pila);
                break;
                case 22:
                    nd = new R23(pila);
                break;
                case 23:
                    nd = new R24(pila);
                break;
                case 24:
                    nd = new R25(pila);
                break;
                case 26:
                    nd = new R27(pila);
                break;
                case 27:
                    nd = new R28(pila);
                break;
                case 29:
                    nd = new R30(pila);
                break;
                case 31:
                    nd = new R32(pila);
                break;
                case 33:
                    nd = new R34(pila);
                break;
                case 34:
                    nd = new R35(pila);
                break;
                case 35:
                    nd = new R36(pila);
                break;
                case 36:
                    nd = new R37(pila);
                break;
                case 37:
                    nd = new R38(pila);
                break;
                case 38:
                    nd = new R39(pila);
                break;
                case 39:
                    nd = new R40(pila);
                break;
                case 40:
                    nd = new R41(pila);
                break;
                case 41:
                    nd = new R42(pila);
                break;
                case 42:
                    nd = new R43(pila);
                break;
                case 43:
                    nd = new R44(pila);
                break;
                case 44:
                    nd = new R45(pila);
                break;
                case 45:
                    nd = new R46(pila);
                break;
                case 46:
                    nd = new R47(pila);
                break;
                case 47:
                    nd = new R48(pila);
                break;
                case 48:
                    nd = new R49(pila);
                break;
                case 49:
                    nd = new R50(pila);
                break;
                case 50:
                    nd = new R51(pila);
                break;
                case 51:
                    nd = new R52(pila);
                break;
            }

            /*for de la actividad pasada
            for(int i = 0; i < longReglas[cont]; i ++){
                pila.pop();
                pila.pop();
            }*/

            fila = pila.top()->getEstado();
            columna = idReglas[cont]; //el no terminal que representa a E

            accion = tablaLR[fila][columna];

            //transición
            pila.push(new NoTerminal(nomReglas[cont], nd));
            pila.push(new Estado(accion));
        }
        else return NULL;
    }
}

#endif // SINTACTICO_H_INCLUDED
