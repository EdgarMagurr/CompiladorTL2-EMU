#include <iostream>
#include "Lexico.h"
#include "Sintactico.h"

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
int terminales[4]= {0,1,2,3};

int main()
{
    Lexico lex;
    Sintactico sin;
    bool aceptacion= false;
    int posRegla;
    lex.asignar_entrada("a+b-c+$");

    lex.siguiente_simbolo();
    sin.fila=sin.pila.at(sin.pila.size()-1);
    sin.columna=sin.obtenerColumnaTipo(lex.tipo);
    cout << sin.fila << "\t" << sin.columna << endl;
    sin.accion = tablaLR[sin.fila][sin.columna];

    sin.MostrarPila();
    cout << "Entrada: " << lex.simbolo << endl;
    cout << "Accion:  " << sin.accion << endl;


    while(!aceptacion||lex.tipo!=-1)
    {
        if(sin.accion==-1)
        {
            cout << "Entrada Aceptada" << endl;
            aceptacion=true;
            break;
        }
        if(sin.accion>0)
        {
            //Desplazamiento
            sin.pila.push_back(lex.tipo);
            sin.pila.push_back(sin.accion);
            if(lex.simbolo.compare("$")!=0)
                lex.siguiente_simbolo();
            sin.fila=sin.pila.at(sin.pila.size()-1);
            sin.columna=sin.obtenerColumnaTipo(lex.tipo);
            cout << sin.fila << "\t" << sin.columna << endl;
            sin.accion = tablaLR[sin.fila][sin.columna];
        }
        else if(sin.accion<0)
        {
            //Reduccion
            if(sin.accion != -1)
            {
                if(sin.accion == -2) posRegla=0;
                else if (sin.accion == -3) posRegla=1;

                for(int i=0; i<lonReglas[posRegla]*2; i++)
                {
                    sin.pila.pop_back();
                }

                sin.fila=sin.pila.at(sin.pila.size()-1);
                sin.columna=idReglas[posRegla];
                cout << sin.fila << "\t" << sin.columna << endl;
                sin.accion = tablaLR[sin.fila][sin.columna];

                sin.MostrarPila();
                cout << "Entrada: " << lex.simbolo << endl;
                cout << "Accion:  " << sin.accion << endl;

                //DESPLAZAMIENTO REDUCCION
                sin.pila.push_back(terminales[sin.columna]);
                sin.pila.push_back(sin.accion);
                if(lex.simbolo.compare("$")!=0)
                    lex.siguiente_simbolo();
                sin.fila=sin.pila.at(sin.pila.size()-1);
                sin.columna=sin.obtenerColumnaTipo(lex.tipo);
                cout << sin.fila << "\t" << sin.columna << endl;
                sin.accion = tablaLR[sin.fila][sin.columna];
            }
        }
        else break; //ERROR

        sin.MostrarPila();
        cout << "Entrada: " << lex.simbolo << endl;
        cout << "Accion:  " << sin.accion << endl;
    }

    return 0;
}
