#include <iostream>

#include "Tokenizer.h"
#include "Pila.h"
#include "File.h"

using namespace std;

Pila pila;
int fila, columna, accion;

void mostrarDatos();

File file("prueba.txt");
string input = file.readFromFile();
Tokenizer token(input);

int main()
{

    file.nombreArchivo = "compilador.lr";
    file.parse();

    int **tablaLR = file.tablaLR;
    int *idReglas = file.idReglas;
    int *lonReglas = file.lonReglas;
    string *nomReglas = file.nomReglas;

    pila.push(new Terminal("$"));
    pila.push(new Estado(0));

    unsigned int contador;

    token.sigSimbolo();

    while(1){

        //cout << "Simbolo: " << token.getSimbolo() << " Tipo: " << token.getTipo() << endl;
        fila = pila.top()->getEstado();
        columna = token.getTipo();
        accion = tablaLR[fila][columna];

        mostrarDatos();

        if(accion < -1){
            contador = (-accion) - 2;
            for (int i = 0; i < lonReglas[contador]; i++){
                pila.pop();
                pila.pop();
            }
            fila = pila.top()->getEstado();
            columna = idReglas[contador];
            accion = tablaLR[fila][columna];
            pila.push(new NoTerminal(nomReglas[contador]));
            pila.push(new Estado(accion));
        }else if(accion > 0){
            pila.push(new Terminal(token.getSimbolo()));
            pila.push(new Estado(accion));
            token.sigSimbolo();
        }else if(accion == 0){
            cout << "Error" << endl;
            break;
        }
        else if(accion == -1){
            cout << "Aceptacion" << endl;
            break;
        }
    }

    cin.get();

    return 0;
}

void mostrarDatos()
{

    cout << "Pila: ";
    pila.muestra();
    cout << "Fila: " << fila << " Columna: " << columna << endl;
    cout << "Entrada: " << token.getSimbolo() << endl;
    cout << "Accion: " << accion << endl;
    cout << endl << endl;

}
