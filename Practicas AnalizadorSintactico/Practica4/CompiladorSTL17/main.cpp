#include <cstdlib>
#include <iostream>
#include <string>
#include "Lexico.h"
#include "Pila.h"
#include "Gramatica.h"

using namespace std;



int main()
{
    Lexico lexico;
    Pila pila;
    Gramatica gram("prueba.txt");
    bool aceptacion= false;
    unsigned int contador;

    string entrada = gram.readFromFile();
    lexico.asignar_entrada(entrada);

    gram.nombreArchivo = "compilador.lr";
    gram.parse();

    int **tablaLR = gram.tablaLR;
    int *idReglas = gram.idReglas;
    int *lonReglas = gram.lonReglas;
    string *nomReglas = gram.nomReglas;

    pila.push(new Terminal("$"));
	pila.push(new Estado(0));

    lexico.siguiente_simbolo();

    while(!aceptacion||lexico.tipo!=-1)
    {
        pila.fila = pila.top()->getEstado();
        pila.columna = lexico.tipo;
        pila.accion = tablaLR[pila.fila][pila.columna];

         pila.mostrarDatos(lexico.simbolo);

        if(pila.accion < -1){
            contador = (-pila.accion) - 2;
            for (int i = 0; i < lonReglas[contador]; i++){
                pila.pop();
                pila.pop();
            }
            pila.fila = pila.top()->getEstado();
            pila.columna = idReglas[contador];
            pila.accion = tablaLR[pila.fila][pila.columna];
            pila.push(new NoTerminal(nomReglas[contador]));
            pila.push(new Estado(pila.accion));

        }else if(pila.accion > 0){
            pila.push(new Terminal(lexico.simbolo));
            pila.push(new Estado(pila.accion));
            if(lexico.simbolo.compare("$")!=0)
                lexico.siguiente_simbolo();

        }else if(pila.accion == 0){
            cout << "Error" << endl;
            break;
        }
        else if(pila.accion == -1){
            cout << "Aceptacion" << endl;
            break;
        }
    }

    return 0;
}
