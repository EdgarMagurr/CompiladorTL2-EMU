#ifndef SINTACTICO_H
#define SINTACTICO_H

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;


class Sintactico
{
public:


    int fila;
    int columna;
    int accion;
    vector<int> pila;
    Sintactico();
    virtual ~Sintactico();
    void MostrarPila();
    int obtenerColumnaTipo(int tipo);

    static const int ERROR = -1;
    static const int IDENTIFICADOR = 0;
    static const int ENTERO = 1;
    static const int REAL = 2;
    static const int CADENA = 3;
    static const int TIPO_FUNCION = 4;
    static const int OP_ADICION = 5;
    static const int OP_MUL = 6;
    static const int OP_RELACIONAL = 7;
    static const int OP_OR = 8;
    static const int OP_AND = 9;
    static const int OP_NOT = 10;
    static const int OP_IGUAL = 11;
    static const int PUNTOCOMA = 12;
    static const int COMA = 13;
    static const int PARENTESIS_IZQ = 14;
    static const int PARENTESIS_DER = 15;
    static const int LLAVE_IZQ = 16;
    static const int LLAVE_DER = 17;
    static const int OP_ASIGNACION = 18;
    static const int RES_IF = 19;
    static const int RES_WHILE = 20;
    static const int RES_RETURN = 21;
    static const int RES_ELSE = 22;
    static const int FIN = 23;

protected:

private:
};

#endif // SINTACTICO_H
