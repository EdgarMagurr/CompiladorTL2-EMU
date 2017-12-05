#include "Lexico.h"

#include <iostream>
#include <string>
#include <string.h>

using namespace std;
Lexico::Lexico()
{
    indice=0;
    simbolo_per=true;
}

Lexico::~Lexico()
{
    //dtor
}

Lexico::Lexico(string e)
{
    indice=0;
    simbolo_per=true;
    fuente=e;
}

void Lexico::asignar_entrada(string e)
{
    indice=0;
    fuente=e;
}

string Lexico::tipo_simbolo(int tipo)
{
    string simbolo_tipo;

    switch(tipo)
    {
    case IDENTIFICADOR:
        simbolo_tipo="ID";
        break;
    case ENTERO:
        simbolo_tipo="Entero";
        break;
    case REAL:
        simbolo_tipo="Real";
        break;
    case CADENA:
        simbolo_tipo="Cadena";
        break;
    case TIPO_FUNCION:
        simbolo_tipo="TipoDato";
        break;
    case OP_ADICION:
        simbolo_tipo="OpAdicion";
        break;
    case OP_MUL:
        simbolo_tipo="OpMul";
        break;
    case OP_RELACIONAL:
        simbolo_tipo="OpRelacional";
        break;
    case OP_OR:
        simbolo_tipo="OpOr";
        break;
    case OP_AND:
        simbolo_tipo="OpAnd";
        break;
    case OP_NOT:
        simbolo_tipo="OpNot";
        break;
    case OP_IGUAL:
        simbolo_tipo="OpComparacion";
        break;
    case PUNTOCOMA:
        simbolo_tipo="PuntoComa";
        break;
    case COMA:
        simbolo_tipo="Coma";
        break;
    case PARENTESIS_IZQ:
        simbolo_tipo="ParentesisIzq";
        break;
    case PARENTESIS_DER:
        simbolo_tipo="ParentesisDer";
        break;
    case LLAVE_IZQ:
        simbolo_tipo="LlaveIzq";
        break;
    case LLAVE_DER:
        simbolo_tipo="LlaveDer";
        break;
    case OP_ASIGNACION:
        simbolo_tipo="OpAsignacion";
        break;
    case RES_IF:
		simbolo_tipo = "IF";
		break;
	case RES_WHILE:
		simbolo_tipo = "WHILE";
		break;
	case RES_RETURN:
		simbolo_tipo = "RETURN";
		break;
	case RES_ELSE:
		simbolo_tipo = "ELSE";
		break;
	case FIN:
		simbolo_tipo = "FIN";
		break;
	default:
		simbolo_tipo = "ERROR";
		break;
    }
    return simbolo_tipo;
}

int Lexico::siguiente_simbolo()
{
    estado = 0;
	continuar = true;
	simbolo.clear();

	while (continuar)
	{
		if (simbolo_per)
			c = sig_char();
		simbolo_per = true;
		switch (estado)
		{
		case 0:
			if (esLetra(c))
				sig_estado(1);
			else if
				(esDigito(c))
				sig_estado(3);
			else if (esAdicion(c))
				aceptacion(5);
			else if (esMul(c))
				aceptacion(6);
			else if (esMayorQue(c) || esMenorQue(c))
				sig_estado(6);
			else if (esOr(c))
				sig_estado(7);
			else if (esAnd(c))
				sig_estado(8);
			else if (esExclamacion(c))
				sig_estado(9);
			else if (esIgualQue(c))
				sig_estado(10);
			else if (esPuntoComa(c))
				aceptacion(12);
			else if (esComa(c))
				aceptacion(13);
			else if (esParentesisIzq(c))
				aceptacion(14);
			else if (esParentesisDer(c))
				aceptacion(15);
			else if (esLlaveIzq(c))
				aceptacion(16);
			else if (esLlaveDer(c))
				aceptacion(17);
			else if (esPesos(c))
				aceptacion(23);
			else if (esEspacio(c))
				sig_estado(0);
			else if (esComillas(c))
				sig_estado(11);
			else
				aceptacion(-1);
			break;

		case 1:
			if (esLetra(c))
				sig_estado(1);
			else if (esDigito(c))
				sig_estado(2);
			else
			{
				simbolo_per = false;

				aceptacion(rev_cadena());
			}
			break;

		case 2:
			if (esLetra(c) || esDigito(c))
				sig_estado(2);
			else
			{
				simbolo_per = false;
				aceptacion(0);
			}
			break;
		case 3:
			if (esDigito(c))
				sig_estado(3);
			else if (esPunto(c))
				sig_estado(4);
			else
			{
				simbolo_per = false;
				aceptacion(1);
			}
			break;
		case 4:
			if (esDigito(c))
				sig_estado(5);
			else
			{
				simbolo_per = false;
				aceptacion(-1);
			}
			break;
		case 5:
			if (esDigito(c))
				sig_estado(5);
			else
			{
				simbolo_per = false;
				aceptacion(2);
			}
			break;
		case 6:
			if (esIgualQue(c))
				aceptacion(7);
			else
			{
				simbolo_per = false;
				aceptacion(7);
			}
			break;
		case 7:
			if (esOr(c))
				aceptacion(8);
			else
			{
				simbolo_per = false;
				aceptacion(-1);
			}
			break;
		case 8:
			if (esAnd(c))
				aceptacion(9);
			else
			{
				simbolo_per = false;
				aceptacion(-1);
			}
			break;
		case 9:
			if (esIgualQue(c))
				aceptacion(11);
			else
			{
				simbolo_per = false;
				aceptacion(10);
			}
			break;
		case 10:
			if (esIgualQue(c))
				aceptacion(11);
			else
			{
				simbolo_per = false;
				aceptacion(18);
			}
			break;
		case 11:
			if (esComillas(c))
				aceptacion(3);
			else if (isascii(c))
				sig_estado(11);
			break;
		default:
			break;
		}
	}

	switch (estado)
	{
	case 0:
		tipo = IDENTIFICADOR;
		break;

	case 1:
		tipo = ENTERO;
		break;

	case 2:
		tipo = REAL;
		break;

	case 3:
		tipo = CADENA;
		break;

	case 4:
		tipo = TIPO_FUNCION;
		break;

	case 5:
		tipo = OP_ADICION;
		break;

	case 6:
		tipo = OP_MUL;
		break;

	case 7:
		tipo = OP_RELACIONAL;
		break;

	case 8:
		tipo = OP_OR;
		break;

	case 9:
		tipo = OP_AND;
		break;

	case 10:
		tipo = OP_NOT;
		break;

	case 11:
		tipo = OP_IGUAL;
		break;

	case 12:
		tipo = PUNTOCOMA;
		break;

	case 13:
		tipo = COMA;
		break;

	case 14:
		tipo = PARENTESIS_IZQ;
		break;

	case 15:
		tipo = PARENTESIS_DER;
		break;

	case 16:
		tipo = LLAVE_IZQ;
		break;

	case 17:
		tipo = LLAVE_DER;
		break;

	case 18:
		tipo = OP_ASIGNACION;
		break;

	case 19:
		tipo = RES_IF;
		break;

	case 20:
		tipo = RES_WHILE;
		break;

	case 21:
		tipo = RES_RETURN;
		break;

	case 22:
		tipo = RES_ELSE;
		break;

	case 23:
		tipo = FIN;
		break;

	default:
		tipo = ERROR;

	}

	return tipo;
}

bool Lexico::termino()
{
    return indice >= (int)fuente.length();
}

char Lexico::sig_char()
{
    char c = fuente.at(indice++);
    if (termino())
		return '$';
	return c;
}

void Lexico::sig_estado(int e)
{
    estado= e;

	if (simbolo_per)
		simbolo += c;
}

void Lexico::aceptacion(int e)
{
    sig_estado(e);
    continuar=false;
}

void Lexico::regresar()
{
    if (c != '$')
		indice--;
	continuar = false;
}

int Lexico::rev_cadena()
{
    if (simbolo == "int" || simbolo == "float" || simbolo == "void")
		return 4;
	else if (simbolo == "if")
		return 19;
	else if (simbolo == "while")
		return 20;
	else if (simbolo == "return")
		return 21;
	else if (simbolo == "else")
		return 22;
	else
		return 0;
}

bool Lexico::esLetra(char c)
{
    if((c >= 'a' && c <= 'z') || (c>='A' && c<='Z') || c=='_')
        return true;
    else
        return false;
}

bool Lexico::esDigito(char c)
{
    if((c>='1' && c<='9') || c=='0')
        return true;
    else
        return false;
}

bool Lexico::esEspacio(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

bool Lexico::esDosPuntos(char c)
{
    return c == ':';
}

bool Lexico::esPuntoComa(char c)
{
    return c == ';';
}

bool Lexico::esComa(char c)
{
    return c == ',';
}

bool Lexico::esAdicion(char c)
{
    return c == '+' || c == '-';
}

bool Lexico::esMul(char c)
{
    return c == '*' || c == '/';
}

bool Lexico::esParentesisIzq(char c)
{
    return c == '(';
}

bool Lexico::esParentesisDer(char c)
{
    return c == ')';
}

bool Lexico::esLlaveIzq(char c)
{
    return c == '{';
}

bool Lexico::esLlaveDer(char c)
{
    return c == '}';
}

bool Lexico::esPunto(char c)
{
    return c == '.';
}

bool Lexico::esMayorQue(char c)
{
    return c == '>';
}

bool Lexico::esMenorQue(char c)
{
    return c == '<';
}

bool Lexico::esIgualQue(char c)
{
    return c == '=';
}

bool Lexico::esExclamacion(char c)
{
    return c == '!';
}

bool Lexico::esOr(char c)
{
    	return c == '|';
}

bool Lexico::esAnd(char c)
{
	return c == '&';
}

bool Lexico::esPesos(char c)
{
	return c == '$';
}

bool Lexico::esComillas(char c)
{
	return c == '"';
}
