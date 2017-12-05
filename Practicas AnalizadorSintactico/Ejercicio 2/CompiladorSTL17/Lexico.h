#ifndef LEXICO_H
#define LEXICO_H

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class TipoSimbolo{
public:

 static const int ERROR = -1;
 static const int IDENTIFICADOR = 0;
 static const int OPADIC = 1;
 static const int PESOS = 2;
};


class Lexico{
      private:
      string fuente;

      int ind;
      bool continua;
      char c;
      int estado;

      char sigCaracter();
      void sigEstado(int estado);
      void aceptacion(int estado);
      bool esLetra(char c);
      bool esDigito(char c);
      bool esEspacio(char c);
      void retroceso();

      public:
      string simbolo;
      int tipo;

      Lexico(string fuente);
      Lexico();

      void entrada(string fuente);
      string tipoAcad(int tipo);

      int sigSimbolo();
      bool terminado();

};
Lexico::Lexico(string fuente){
    ind= 0;
    this->fuente= fuente;
}

Lexico::Lexico(){
    ind= 0;
}

/*string Lexico::tipoAcad(int tipo){
    string cad= "";

    switch (tipo){
        case TipoSimbolo::IDENTIFICADOR:
            cad= "Identificador";
            break;

        case TipoSimbolo::OPADIC:
            cad= "Op. Adicion";
            break;

        case TipoSimbolo::PESOS:
            cad= "Fin de la Entrada";
            break;

        }
        return cad;
}
  */
void Lexico::entrada(string fuente){
    ind= 0;
    this->fuente= fuente;
}

int Lexico::sigSimbolo(){
    estado=0;
    continua= true;
    simbolo= "";

    //Inicio del Automata
    while (continua){
      c= sigCaracter();

      switch (estado){
        case 0:
            if ( esLetra(c) ) sigEstado(21);
            else
            if ( c == '+' || c =='-') aceptacion(6);
            else

            if ( c == '$' ) aceptacion(23);
            break;

        case 1:
            if ( esDigito(c)) sigEstado(1);
            else
            if ( c == '.') sigEstado(2);
            else{
                retroceso();
            }
            break;

        case 2:
            if( esDigito(c)) sigEstado(3);

            break;

        case 3:
            if( esDigito(c)) sigEstado(3);
            else{
                retroceso();
            }
            break;

        case 4:
            if( c == '=') sigEstado(5);
            else{
                retroceso();
            }
            break;

        case 5:
            retroceso();
            break;

        case 8:
            if (c == '|') sigEstado(9);
            break;

        case 9:
            retroceso();
            break;

        case 10:
            if (c == '&') sigEstado(11);
            break;

        case 11:
            retroceso();
            break;

        case 12:
            if( c ==  '=') sigEstado(13);
            else{
                retroceso();
            }
            break;

        case 13:
            retroceso();
            break;

        case 14:
            if (c == '=') sigEstado(13);
            else{
                retroceso();
            }
            break;

        case 21:
            if ( esLetra(c) || esDigito(c) ) sigEstado(21);
            else{
                retroceso();
            }
            break;

        case 22:
            if ( esLetra(c) || esDigito(c) || esEspacio(c) ) sigEstado(23);
            break;

        case 23:
            if ( esLetra(c) || esDigito(c) || esEspacio(c) ) sigEstado(23);
            else{
                if( c == '\"') sigEstado(24);
            }
            break;

        case 24:
            retroceso();
            break;
      }

   }
    //Fin del Automata

    switch (estado){
        case 6:
            tipo= TipoSimbolo::OPADIC;
            break;
        case 21:
            tipo = TipoSimbolo::IDENTIFICADOR;
            break;
        case 23:
            tipo = TipoSimbolo::PESOS;
            break;
        default:
            tipo= TipoSimbolo::ERROR;
            break;
    }

    return tipo;
}

char Lexico::sigCaracter(){
      if (terminado()) return '$';

      return fuente[ind++];
}

void Lexico::sigEstado(int estado){
    this->estado= estado;
    simbolo+= c;
}

void Lexico::aceptacion(int estado){
    sigEstado(estado);
    continua= false;
}

bool Lexico::terminado(){//fin de cadena
    return ind >= (int)fuente.length();
}

bool Lexico::esLetra(char c){
    return isalpha(c) || c=='_';
}


bool Lexico::esDigito(char c){
    return isdigit(c);
}

bool Lexico::esEspacio(char c){
    return c== ' ' || c== '\t';
}


void Lexico::retroceso(){
    if ( c != '$') ind--;
    continua= false;
}

#endif
