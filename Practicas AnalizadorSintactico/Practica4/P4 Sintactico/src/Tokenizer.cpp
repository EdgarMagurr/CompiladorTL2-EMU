#include "Tokenizer.h"

Tokenizer::Tokenizer(){

}

Tokenizer::Tokenizer(string entrada){
    this->entrada = entrada;
    this->posicion = 0;
}

int Tokenizer::sigSimbolo(){
    this->estado = 0;
    this->continua = true;

    this->simbolo = "";

    while(continua){
        this->c = sigCaracter();
        switch(estado){
        case 0:
            if (esLetra(this->c)){
                sigEstado(21);
            }else if (this->c == '\"'){
                sigEstado(22);
            }else if (esDigito(this->c)){
                sigEstado(1);
            }else if (this->c == '+' || this->c =='-'){
                aceptacion(6);
            }else if(this->c == '*' || this->c == '/'){
                aceptacion(7);
            }else if(this->c == '<' || this->c == '>'){
                sigEstado(4);
            }else if(this->c == '|'){
                sigEstado(8);
            }else if(this->c == '&'){
                sigEstado(10);
            }else if(this->c == '!'){
                sigEstado(12);
            }else if(this->c == '='){
                sigEstado(14);
            }else if(this->c == ';'){
                aceptacion(15);
            }else if(this->c == '\''){
                aceptacion(16);
            }else if(this->c == '('){
                aceptacion(17);
            }else if(this->c == ')'){
                aceptacion(18);
            }else if(this->c == '{'){
                aceptacion(19);
            }else if(this->c == '}'){
                aceptacion(20);
            }else if(this->c == '$'){
                aceptacion(23);
            }
            break;

        case 1:
            if (esDigito(this->c)){
                sigEstado(1);
            }else if(this->c == '.'){
                sigEstado(2);
            }else{
                retroceso();
            }
            break;

        case 2:
            if(esDigito(this->c)){
                sigEstado(3);
            }
            break;

        case 3:
            if(esDigito(this->c)){
                sigEstado(3);
            }else{
                retroceso();
            }
            break;

        case 4:
            if(this->c == '='){
                sigEstado(5);
            }else{
                retroceso();
            }
            break;

        case 5:
            retroceso();
            break;

        case 8:
            if(this->c == '|'){
                sigEstado(9);
            }
            break;

        case 9:
            retroceso();
            break;

        case 10:
            if(this->c == '&'){
                sigEstado(11);
            }
            break;

        case 11:
            retroceso();
            break;

        case 12:
            if(this->c ==  '='){
                    sigEstado(13);
            }else{
                retroceso();
            }
            break;

        case 13:
            retroceso();
            break;

        case 14:
            if(this->c == '='){
                sigEstado(13);
            }else{
                retroceso();
            }
            break;

        case 21:
            if(esLetra(this->c) || esDigito(this->c)){
                sigEstado(21);
            }else{
                retroceso();
            }
            break;

        case 22:
            if (esLetra(this->c) || esDigito(this->c) || esEspacio(this->c)){
                sigEstado(23);
            }
            break;

        case 23:
            if (esLetra(this->c) || esDigito(this->c) || esEspacio(this->c)){
                sigEstado(23);
            }else if(this->c == '\"'){
                sigEstado(24);
            }
            break;

        case 24:
            retroceso();
            break;
        }
    }
tipo = dameTipo(this->estado);
return tipo;
}

int Tokenizer::dameTipo(int estado){
    switch(estado){
        case 1:
            return ENTERO;
            break;

        case 3:
            return REAL;
            break;

        case 4:
            return OP_REL;
            break;

        case 5:
            return OP_REL;
            break;

        case 6:
            return OP_SUMA;
            break;

        case 7:
            return OP_MUL;
            break;

        case 9:
            return OP_OR;
            break;

        case 11:
            return OP_AND;
            break;

        case 12:
            return OP_NOT;
            break;

        case 13:
            return OP_IGUALDAD;
            break;

        case 14:
            return IGUAL;
            break;

        case 15:
            return PUNTO_COMA;
            break;

        case 16:
            return COMA;
            break;

        case 17:
            return PARENT_A;
            break;

        case 18:
            return PARENT_C;
            break;

        case 19:
            return LLAVE_A;
            break;

        case 20:
            return LLAVE_C;
            break;

        case 21:
            if(this->simbolo == "int" || this->simbolo == "float" || this->simbolo == "void"){
                return TIPO;
            }else if(this->simbolo == "if"){
                return SI;
            }else if(this->simbolo == "while"){
                return MIENTRAS;
            }else if(this->simbolo == "return"){
                return RETORNO;
            }else if(this->simbolo == "else"){
                return SINO;
            }else{
                return IDENTIFICADOR;
            }
            break;

        case 23:
            return PESOS;
            break;

        case 24:
            return CADENA;
            break;

        default:
            return ERROR;
    }
}

string Tokenizer::dameTipoCadena(int tipo){
    switch(tipo){
        case IDENTIFICADOR:
            return "IDENTIFICADOR";
            break;

        case ENTERO:
            return "ENTERO";
            break;

        case REAL:
            return "REAL";
            break;

        case CADENA:
            return "CADENA";
            break;

        case TIPO:
            return "TIPO";
            break;

        case OP_SUMA:
            return "OPERADOR SUMA";
            break;

        case OP_MUL:
            return "OPERADOR MULTIPLICACION";
            break;

        case OP_REL:
            return "OPERADOR RELACIONAL";
            break;

        case OP_OR:
            return "OPERADOR OR";
            break;

        case OP_AND:
            return "OPERADOR AND";
            break;

        case OP_NOT:
            return "OPERADOR NOT";
            break;

        case OP_IGUALDAD:
            return "OPERADOR IGUALDAD";
            break;

        case PUNTO_COMA:
            return "PUNTO Y COMA";
            break;

        case COMA:
            return "COMA";
            break;

        case PARENT_A:
            return "PARENTESIS ABRE";
            break;

        case PARENT_C:
            return "PARENTESIS CIERRA";
            break;

        case LLAVE_A:
            return "LLAVE ABRE";
            break;

        case LLAVE_C:
            return "LLAVE CIERRA";
            break;

        case IGUAL:
            return "ASIGNACION";
            break;

        case SI:
            return "IF";
            break;

        case MIENTRAS:
            return "WHILE";
            break;

        case RETORNO:
            return "RETURN";
            break;

        case SINO:
            return "ELSE";
            break;

        case PESOS:
            return "FIN DE CADENA";
            break;
    }
return NULL;
}

void Tokenizer::sigEstado(int estado){
    this->estado = estado;
    this->simbolo += this->c;
}

void Tokenizer::aceptacion(int estado){
    this->sigEstado(estado);
    this->continua = false;
}

void Tokenizer::retroceso(){
    if(this->c != '$'){
        posicion--;
    }
    this->continua = false;
}

char Tokenizer::sigCaracter(){
    if(this->posicion >= this->entrada.length()){
        return '$';
    }
    return entrada[posicion++];
}

bool Tokenizer::esLetra(char c){
    return isalpha(c) || c == '_';;
}

bool Tokenizer::esDigito(char c){
    return isdigit(c);
}

bool Tokenizer::esEspacio(char c){
    return c == ' ' || c == '\t';
}

string Tokenizer::getSimbolo(){
    return this->simbolo;
}

int Tokenizer::getTipo(){
    return this->tipo;
}

Tokenizer::~Tokenizer(){

}
