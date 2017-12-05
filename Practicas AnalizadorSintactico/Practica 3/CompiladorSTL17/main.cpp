#include <cstdlib>
#include <iostream>
#include <string>
#include "Lexico.h"
#include "Pila.h"

using namespace std;

int tablaLR[5][4]=
{
    2, 0, 0, 1,
    0, 0, -1, 0,
    0, 3, -3, 0,
    2, 0, 0, 4,
    0, 0, -2, 0,
};

int idReglas[2]= {3, 3};
int lonReglas[2]= {3, 1};
string terminales[4]={"id","+","$","E"};

int main()
{
    Lexico lexico;
    Pila pila;
    bool aceptacion= false;
    int posRegla;
    lexico.asignar_entrada("a+b+c$");

    pila.push(new Terminal("$"));
	pila.push(new Estado(0));

    lexico.siguiente_simbolo();
    pila.fila = pila.top()->getEstado();
	pila.columna = pila.obtenerColumnaTipo(lexico.tipo);
	pila.accion = tablaLR[pila.fila][pila.columna];

    pila.mostrarDatos(lexico.simbolo);


    while(!aceptacion||lexico.tipo!=-1)
    {
        if(pila.accion==-1)
        {
            cout << "Entrada Aceptada" << endl;
            aceptacion=true;
            break;
        }
        if(pila.accion>0)
        {
            //Desplazamiento
            pila.push(new Terminal(terminales[pila.obtenerColumnaTipo(lexico.tipo)]));
			pila.push(new Estado(pila.accion));
            if(lexico.simbolo.compare("$")!=0)
                lexico.siguiente_simbolo();
            pila.fila=pila.top()->getEstado();
            pila.columna=pila.obtenerColumnaTipo(lexico.tipo);
            pila.accion = tablaLR[pila.fila][pila.columna];
        }
        else if(pila.accion<0)
        {
            //Reduccion
            if(pila.accion != -1)
            {
                if(pila.accion == -2) posRegla=0;
                else if (pila.accion == -3) posRegla=1;

                for(int i=0; i<lonReglas[posRegla]*2; i++)
                    pila.pop();

                pila.fila=pila.top()->getEstado();
                pila.columna=idReglas[posRegla];
                pila.accion = tablaLR[pila.fila][pila.columna];

                pila.mostrarDatos(lexico.simbolo);

                //DESPLAZAMIENTO REDUCCION
                pila.push(new NoTerminal(terminales[pila.columna])); // columna es el entero qeu representa a E (no terminal)
				pila.push(new Estado(pila.accion));
                if(lexico.simbolo.compare("$")!=0)
                    lexico.siguiente_simbolo();

                pila.fila=pila.top()->getEstado();
                pila.columna=pila.obtenerColumnaTipo(lexico.tipo);
                pila.accion = tablaLR[pila.fila][pila.columna];
            }
        }
        else break; //ERROR

        pila.mostrarDatos(lexico.simbolo);
    }

    return 0;
}
