#include <iostream>
#include "Lexico.h"
#include "Sintactico.h"

using namespace std;

int tablaLR[5][4]={
2, 0, 0, 1,
0, 0, -1, 0,
0, 3, 0, 0,
4, 0, 0, 0,
0, 0, -2, 0,
};

int main()
{
    Lexico lex;
    Sintactico sin;
    bool aceptacion= false;
    lex.asignar_entrada("a+b$");

    lex.siguiente_simbolo();

    sin.fila=sin.pila.at(sin.pila.size()-1);
    sin.columna=sin.obtenerColumnaTipo(lex.tipo);
    cout << sin.fila << "\t" << sin.columna << endl;
    sin.accion = tablaLR[sin.fila][sin.columna];

    sin.MostrarPila();
    cout << "Entrada: " << lex.simbolo << endl;
    cout << "Accion:  " << sin.accion << endl;

    sin.pila.push_back(lex.tipo);
    sin.pila.push_back(sin.accion);

    lex.siguiente_simbolo();
    sin.fila=sin.pila.at(sin.pila.size()-1);
    sin.columna=sin.obtenerColumnaTipo(lex.tipo);
    cout << sin.fila << "\t" << sin.columna << endl;
    sin.accion = tablaLR[sin.fila][sin.columna];

    sin.MostrarPila();
    cout << "Entrada: " << lex.simbolo << endl;
    cout << "Accion:  " << sin.accion << endl;

    sin.pila.push_back(lex.tipo);
    sin.pila.push_back(sin.accion);

    lex.siguiente_simbolo();
    sin.fila=sin.pila.at(sin.pila.size()-1);
    sin.columna=sin.obtenerColumnaTipo(lex.tipo);
    cout << sin.fila << "\t" << sin.columna << endl;
    sin.accion = tablaLR[sin.fila][sin.columna];

    sin.MostrarPila();
    cout << "Entrada: " << lex.simbolo << endl;
    cout << "Accion:  " << sin.accion << endl;

    sin.pila.push_back(lex.tipo);
    sin.pila.push_back(sin.accion);

    lex.siguiente_simbolo();
    sin.fila=sin.pila.at(sin.pila.size()-1);
    sin.columna=sin.obtenerColumnaTipo(lex.tipo);
    cout << sin.fila << "\t" << sin.columna << endl;
    sin.accion = tablaLR[sin.fila][sin.columna];

    sin.MostrarPila();
    cout << "Entrada: " << lex.simbolo << endl;
    cout << "Accion:  " << sin.accion << endl;

    sin.pila.pop_back();
    sin.pila.pop_back();
    sin.pila.pop_back();
    sin.pila.pop_back();
    sin.pila.pop_back();
    sin.pila.pop_back();

    sin.fila=sin.pila.at(sin.pila.size()-1);
    sin.columna=3;
    cout << sin.fila << "\t" << sin.columna << endl;
    sin.accion = tablaLR[sin.fila][sin.columna];

    //transicion
    sin.pila.push_back(2);
    sin.pila.push_back(sin.accion);

    sin.MostrarPila();
    cout << "Entrada: " << lex.simbolo << endl;
    cout << "Accion:  " << sin.accion << endl;

    sin.fila=sin.pila.at(sin.pila.size()-1);
    sin.columna=sin.obtenerColumnaTipo(lex.tipo);
    cout << sin.fila << "\t" << sin.columna << endl;
    sin.accion = tablaLR[sin.fila][sin.columna];

    sin.MostrarPila();
    cout << "Entrada: " << lex.simbolo << endl;
    cout << "Accion:  " << sin.accion << endl;

    if(sin.accion==-1)
        aceptacion=true;
    if (aceptacion)
        cout << "Entrada Aceptada" << endl;





//    while(lex.simbolo.compare("$")!=0)
//    {
//        lex.siguiente_simbolo();
//        cout << lex.simbolo << "    " << lex.tipo_simbolo(lex.tipo) << endl;
//    }
    return 0;
}
