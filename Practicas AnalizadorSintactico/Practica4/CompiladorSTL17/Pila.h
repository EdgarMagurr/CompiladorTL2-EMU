#ifndef PILA_H
#define PILA_H

#include <stack>
#include <iostream>
#include <string>

using namespace std;

class ElementoPila
{
protected:
public:
    virtual void muestra() {}
    virtual int getEstado() {return 0;}
};

class Terminal: public ElementoPila
{
protected:
    string terminal;
public:
    Terminal(string terminal)
    {
        this->terminal= terminal;
    }
    void muestra()
    {
        cout << terminal << " ";
    }
};

class NoTerminal: public ElementoPila
{
protected:
    string noTerminal;
public:
    NoTerminal(string noTerminal)
    {
        this->noTerminal= noTerminal;
    }

    void muestra()
    {
        cout << noTerminal << " ";
    }
};

class Estado: public ElementoPila
{
protected:
    int estado;
public:
    Estado(int estado)
    {
        this->estado= estado;
    }

    virtual int getEstado()
    {
        return this->estado;
    }

    void muestra()
    {
        cout << estado << " " ;
    }
};


class Pila
{
public:
    int fila, columna, accion;
    Pila() {}
    virtual ~Pila() {}
    void push( ElementoPila*);
    ElementoPila* top();
    ElementoPila* pop();
    void muestra();
    void mostrarDatos(string simbolo);
    int obtenerColumnaTipo(int tipo);

protected:

private:
    stack<ElementoPila*> pila;
};

void Pila::push( ElementoPila *x){
    pila.push(x);
}

ElementoPila*  Pila::pop(){
	ElementoPila* x = pila.top();
    pila.pop();
    return x;
}

ElementoPila* Pila::top(){
    return pila.top();
}

void Pila::muestra(){

    if(pila.empty()){
        cout << endl;
        return;
    }
    ElementoPila *x = pila.top();
    x->muestra();
    pila.pop();
    muestra();
    pila.push(x);
}

void Pila::mostrarDatos(string simbolo){
	muestra();
	cout << "Fila: " << fila << " Columna: " << columna << endl;
	cout << "Entrada: " << simbolo << endl;
	cout << "accion: " << accion << endl;
	cout << endl << endl;
}

int Pila::obtenerColumnaTipo(int tipo)
{
    int columna;
    switch(tipo)
    {
   case 0:
    columna = 0;
    break;
   case 5:
    columna = 1;
    break;
   case 23:
    columna = 2;
    break;
   default:
       columna = -1;
    break;
    }
    return columna;
}

#endif // PILA_H
