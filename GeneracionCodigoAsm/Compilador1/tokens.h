#ifndef TOKENS_H_INCLUDED
#define TOKENS_H_INCLUDED

#include <iostream>

using namespace std;

class tokens{
    public:
        int identificador;
        string tipo;
        string token;
    public:
        void setID(int);
        void setALL(int id, string tip, string TK);
        int getID();
        string getTK();
        string getTIPO();
        void getALL();
};
void tokens::setID(int ID){
    identificador = ID;
}

void tokens::setALL(int id, string tip, string TK){
    identificador = id;
    tipo = tip;
    token = TK;
}

int tokens::getID(){
    return identificador;
}

string tokens::getTK(){
    return token;
}

string tokens::getTIPO(){
    return tipo;
}

void tokens::getALL(){
    cout << "---------------------------\n";
    cout << identificador << " | " << token << " | " << tipo << endl;
}

#endif // TOKENS_H_INCLUDED
