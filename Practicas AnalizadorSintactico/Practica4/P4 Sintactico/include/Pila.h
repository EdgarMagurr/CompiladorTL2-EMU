#ifndef PILA_H
#define PILA_H

#include <stack>

using namespace std;


class ElementoPila{
    protected:

    public:
        virtual void muestra(){}
        virtual int getEstado(){return 0;}
};

class Terminal: public ElementoPila{

    protected:
        string terminal;

    public:
        Terminal(string terminal){
            this->terminal = terminal;
        }

        void muestra(){
            cout <<terminal << " ";
        }
};

class NoTerminal: public ElementoPila{

    protected:
        string noTerminal;

    public:
        NoTerminal(string noTerminal){
            this->noTerminal = noTerminal;
        }

        void muestra(){
            cout << noTerminal << " ";
        }
};

class Estado: public ElementoPila{

    protected:
        int estado;

    public:
        Estado(int estado){
            this->estado = estado;
        }

        virtual int getEstado(){
            return this->estado;
        }

        void muestra(){
            cout << estado << " ";
        }
};

class Pila
{
    stack<ElementoPila*> pila;

    public:

    void push(ElementoPila*);
    ElementoPila* pop();
    ElementoPila* top();

    void muestra();

};

void Pila::push(ElementoPila *elemento){
    pila.push(elemento);
}

ElementoPila* Pila::pop(){
    ElementoPila* x = pila.top();
    pila.pop();
    return x;
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

ElementoPila* Pila::top(){
    return pila.top();
}


#endif // PILA_H
