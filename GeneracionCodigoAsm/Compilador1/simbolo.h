#ifndef SIMBOLO_H_INCLUDED
#define SIMBOLO_H_INCLUDED

#include <iostream>

using namespace std;

class simbolo{
    public:
        string identificador;
        char tipoDato;
        string ambito;
        char vectorParam[20];
        bool funcion;
        char param;
    public:
        void setID(int);
        void setALL(string id, char tip, string amb,bool func);
        void setALL(string id, char tip, string amb, char* VP,bool func);
        string getID();
        string getAMB();
        char getTIPO();
        void getALL();
        int getNumPAram();
        char getVectorPAram(int);
        bool getFuncion();
};
void simbolo::setID(int ID){
    identificador = ID;
}

void simbolo::setALL(string id, char tip, string amb,bool func){
    identificador = id;
    tipoDato = tip;
    ambito = amb;
    funcion = func;
}

void simbolo::setALL(string id, char tip, string amb, char* VP,bool func){
    identificador = id;
    tipoDato = tip;
    ambito = amb;
    funcion = func;
    for (int i = 0; i < sizeof(vectorParam); i++){
		vectorParam[i] = VP[i];
	}
}

string simbolo::getID(){
    return identificador;
}

string simbolo::getAMB(){
    return ambito;
}

char simbolo::getTIPO(){
    return tipoDato;
}

bool simbolo::getFuncion(){
	return funcion;
}

void simbolo::getALL(){
    cout << "---------------------------\n";
    cout << identificador << " | " << ambito << " | " << tipoDato << endl;
}

int simbolo::getNumPAram(){
    int i;
	for (i = 0; i < sizeof(vectorParam) ; i++){
		if (vectorParam[i] == 0){
			return i;
        }
	}
	return i;
}

char simbolo::getVectorPAram(int i){
	return vectorParam[i];
}

#endif // SIMBOLO_H_INCLUDED
