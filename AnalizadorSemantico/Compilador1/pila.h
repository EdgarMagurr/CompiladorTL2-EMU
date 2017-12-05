#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <list>
#include <iostream>
#include <string>

using namespace std;
class Regla;

class ElementoPila{
    public:
        virtual void muestra(){}
        virtual int getEstado(){}
        virtual string getTerminal(){}
        virtual string getNoTerminal(){}
        virtual Regla* getNodo(){}
};

class Terminal: public ElementoPila{
    protected:
            string tk;
    public:
        Terminal(string tk){
            this->tk = tk;
        }

        void muestra(){
            cout << tk << " ";
        }
        string getTerminal(){
            return this->tk;
        }
};

class NoTerminal: public ElementoPila{
    protected:
        string NT;
        Regla *nd;
    public:
        NoTerminal(string NT, Regla *nd){
            this->NT = NT;
            this->nd = nd;
        }

        void muestra(){
            cout << NT << " ";
        }

        string getNoTerminal(){
            return this->NT;
        }

        Regla* getNodo(){
            return this->nd;
        }
};

class Estado: public ElementoPila{
    protected:
            int state;
    public:
        Estado(int state){
            this->state = state;
        }

        void muestra(){
            cout << state << " ";
        }

        int getEstado(){
            return this->state;
        }
};

class Pila{

   private:
      list <ElementoPila*> lista;

   public:
      void push( ElementoPila *x);
      ElementoPila* top();
      ElementoPila* pop();
      void muestra();
};

void Pila::push( ElementoPila *x){
    lista.push_front(x);
}

ElementoPila* Pila::pop(){
    ElementoPila* x = *lista.begin();
    lista.erase ( lista.begin() );
    return x;
}


ElementoPila* Pila::top(){
    return *lista.begin();
}

void Pila::muestra(){
    list <ElementoPila*>::reverse_iterator it;

    ElementoPila *x;

    cout << "Pila: ";

    for (it = lista.rbegin(); it != lista.rend(); it++){
        x = *it;
        x->muestra();
        //cout << (*it) << " ";
    }
    cout << endl;
}

#endif // PILA_H_INCLUDED
