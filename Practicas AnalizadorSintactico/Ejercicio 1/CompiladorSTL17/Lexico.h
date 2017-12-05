#ifndef LEXICO_H
#define LEXICO_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Lexico
{
public:
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

    string simbolo;
	int tipo;
    Lexico(string e);
    Lexico();
    ~Lexico();
    void asignar_entrada(string e);
	string tipo_simbolo(int tipo);

	int siguiente_simbolo();
	bool termino();

    string fuente;

    int indice;
    bool continuar;
    bool simbolo_per;
    char c;
    int estado;

    char sig_char();
    void sig_estado(int e);
    void aceptacion(int e);
    void regresar();
    int rev_cadena();

    bool esLetra(char c);
    bool esDigito(char c);
    bool esEspacio(char c);
    bool esDosPuntos(char c);
    bool esPuntoComa(char c);
    bool esComa(char c);
    bool esAdicion(char c);
    bool esMul(char c);
    bool esParentesisIzq(char c);
    bool esParentesisDer(char c);
    bool esLlaveIzq(char c);
    bool esLlaveDer(char c);
    bool esPunto(char c);
    bool esMayorQue(char c);
    bool esMenorQue(char c);
    bool esIgualQue(char c);
    bool esExclamacion(char c);
    bool esOr(char c);
    bool esAnd(char c);
    bool esPesos(char c);
    bool esComillas(char c);
};

#endif // LEXICO_H
