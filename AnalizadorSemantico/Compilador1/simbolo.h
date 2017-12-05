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
    public:
        void setID(int);
        void setALL(string id, char tip, string amb);
        void setALL(string id, char tip, string amb, char* VP);
        string getID();
        string getAMB();
        char getTIPO();
        void getALL();
        int getNumPAram();
        char getVectorPAram(int);
};
void simbolo::setID(int ID){
    identificador = ID;
}

void simbolo::setALL(string id, char tip, string amb){
    identificador = id;
    tipoDato = tip;
    ambito = amb;
}

void simbolo::setALL(string id, char tip, string amb, char* VP){
    identificador = id;
    tipoDato = tip;
    ambito = amb;
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
