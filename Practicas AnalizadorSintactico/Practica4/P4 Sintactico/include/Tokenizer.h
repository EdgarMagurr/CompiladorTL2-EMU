#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <string>
#include <cstring>

#define ERROR -1
#define IDENTIFICADOR 0
#define ENTERO 1
#define REAL 2
#define CADENA 3
#define TIPO 4
#define OP_SUMA 5
#define OP_MUL 6
#define OP_REL 7
#define OP_OR 8
#define OP_AND 9
#define OP_NOT 10
#define OP_IGUALDAD 11
#define PUNTO_COMA 12
#define COMA 13
#define PARENT_A 14
#define PARENT_C 15
#define LLAVE_A 16
#define LLAVE_C 17
#define IGUAL 18
#define SI 19
#define MIENTRAS 20
#define RETORNO 21
#define SINO 22
#define PESOS 23


using namespace std;

class Tokenizer
{
    public:

    Tokenizer();
    Tokenizer(string);
    virtual ~Tokenizer();

    string getSimbolo();
    string dameTipoCadena(int);
    int getTipo();
    int sigSimbolo();

    private:

    string entrada, simbolo;
    int tipo, estado;
    unsigned int posicion;
    char c;
    bool continua;
    char sigCaracter();
    bool esLetra(char);
    bool esDigito(char);
    bool esEspacio(char);

    void sigEstado(int);
    void aceptacion(int);
    void retroceso();

    int dameTipo(int);

};

#endif // TOKENIZER_H
