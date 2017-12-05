#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>

#include "tokens.h"

using namespace std;

template <class T>
class nodo{
public:
    nodo *siguiente;
    nodo *anterior;
    nodo (T);
    nodo();

    T getdato();
    void setdato(T);
    nodo* getsiguiente();
    nodo*getanterior();
    void setsiguiente(nodo*);
    void setanterior(nodo*);
    T dato;
};

template <class T>
nodo<T>::nodo(T p){
    dato = p;
    siguiente = NULL;
    anterior = NULL;
}

template <class T>
T nodo<T>::getdato(){
    return dato;
}

template <class T>
void nodo<T>::setdato(T d){
    dato = d;
}

template <class T>
nodo<T>* nodo<T>::getsiguiente(){
    return siguiente;
}

template <class T>
nodo<T>* nodo<T>::getanterior(){
    return  anterior;
}

template <class T>
void nodo<T>::setsiguiente(nodo* next){
    siguiente = next;
}

template <class T>
void nodo<T>::setanterior(nodo* previus){
    anterior = previus;
}

#endif // NODO_H_INCLUDED
