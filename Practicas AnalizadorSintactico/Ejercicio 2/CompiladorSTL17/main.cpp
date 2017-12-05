#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"
#include "pila.h"

using namespace std;

Pila pila;

int fila, columna, accion;
Lexico lexico;

int idReglas[2]={3,3};
int lonReglas[2]={2,6};

string terminales[4]={"id","+","$","E"};

int tablaLR[5][4]={
	2,0,0,1,
	0,0,-1,0,
	0,3,-3,0,
	2,0,0,4,
	0,0,-2,0
};

void mostrarDatos(){
	pila.muestra();
	cout << "Fila: " << fila << " Columna: " << columna << endl;
	cout << "Entrada: " << lexico.simbolo << endl;
	cout << "accion: " << accion << endl;
	cout << endl << endl;
}

void ejercicio2(){
	// analisis sintactico de a + b + c

	lexico.entrada("a-b+c");

//----------------------------------------------------------------------

	pila.push(new Terminal("$"));
	pila.push(new Estado(0));

	lexico.sigSimbolo();


	fila = pila.top()->getEstado();
	columna = lexico.tipo;
	accion = tablaLR[fila][columna];

	mostrarDatos();
//----------------------------------------------------------------------

	while(true){

		if(accion == -1){
			cout << "ACEPTACION"<< endl;
			break;
		}

		if(accion > 0){
			//DESPLAZAMIENTO
			pila.push(new Terminal(terminales[lexico.tipo]));
			pila.push(new Estado(accion));
			lexico.sigSimbolo();

			fila = pila.top()->getEstado();
			columna = lexico.tipo;
			accion = tablaLR[fila][columna];

		}else if(accion < 0){
				//REDUCCION
				cout << "lonReglas[accion+3]: " << lonReglas[accion+3] << endl;
				for (int i = 0; i < lonReglas[accion+3]; i++)
					pila.pop();

				fila = pila.top()->getEstado();
				cout << "idReglas[accion+3]: " << idReglas[accion+3] << endl;
				columna = idReglas[accion+3];
				accion = tablaLR[fila][columna];

				mostrarDatos();

				//DESPLAZAMIENTO REDUCCION
				pila.push(new NoTerminal(terminales[columna])); // columna es el entero qeu representa a E (no terminal)
				pila.push(new Estado(accion));
				lexico.sigSimbolo();

				fila = pila.top()->getEstado();
				columna = lexico.tipo;
				accion = tablaLR[fila][columna];


		}else break;

		mostrarDatos();

	}

}

int main(int argc, char const *argv[])
{
	ejercicio2();

	return 0;
}
