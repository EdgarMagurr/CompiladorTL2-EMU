#ifndef PILA_H
#define PILA_H


#include <list>
#include <iostream>
#include <string>

using namespace std;

class ElementoPila{
    protected:

    public:
        virtual void muestra(){}
        virtual int getEstado(){}

};

class Terminal: public ElementoPila{
    protected:
        string terminal;
    public:
        Terminal(string terminal){
            this->terminal= terminal;

        }
        void muestra(){
            //cout << "Terminal: " << terminal << endl;
            cout << terminal << " ";
        }
};

class NoTerminal: public ElementoPila{
    protected:
        string noTerminal;
    public:
        NoTerminal(string noTerminal){
            this->noTerminal= noTerminal;
        }

        void muestra(){
            //cout << "NoTerminal: " << noTerminal << endl;
            cout << noTerminal << " ";
        }
};

class Estado: public ElementoPila{
    protected:
        int estado;
    public:
        Estado(int estado){
            this->estado= estado;
        }

        virtual int getEstado(){
            return this->estado;
        }

        void muestra(){
            //cout << "Estado: " << estado << endl;
            cout << estado << " " ;
        }
};

class Pila{

   private:
      list <ElementoPila*> lista;

   public:
      void push( ElementoPila*);
      ElementoPila* top();
      ElementoPila* pop();
      void muestra();
};


void Pila::push( ElementoPila *x){
    lista.push_front(x);
}

ElementoPila*  Pila::pop(){

	ElementoPila* x= *lista.begin();
    lista.erase ( lista.begin() );

    return x;
}

ElementoPila* Pila::top(){
    return *lista.begin();
}

void Pila::muestra(){

    list <ElementoPila*>::reverse_iterator  it;
    ElementoPila *x;
    cout << "Pila: \n\n";

    for (it= lista.rbegin(); it != lista.rend(); it++){
        x = *it;
        x->muestra();
        //cout << (*it) << " ";
    }

    cout << endl;
}


#endif
