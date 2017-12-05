#include <iostream>
#include <cstring>
#include <fstream>

#include "lexico.h"
#include "lista_tokens.h"
#include "sintactico.h"
#include "reglas.h"

using namespace std;

int main(){
    lista<tokens> datos;
    lexico lex1;
    Sintacico sint1;
    Regla *arbol;

    string archivo;
    //cout << "Ingrese el nombre del archivo: ";
    //cin >> archivo;
    ifstream lectura("entrada.txt");
    char cadena[1000];

    if(!lectura.good()){
        cout << "error";
    }
    else{
        lectura.getline((char*)&cadena, 10000, lectura.eof());
        lectura.close();
    }

    datos = lex1.lex(cadena);

    datos.imprimir();
    cout << endl;

    arbol = sint1.sint(datos);

    arbol->muestra();

    return 0;
}
