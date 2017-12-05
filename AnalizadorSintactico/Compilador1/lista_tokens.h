#ifndef LISTA_TOKENS_H_INCLUDED
#define LISTA_TOKENS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "nodo.h"

using namespace std;

template <class T>
class lista{
    public:
        lista();
        void insertar(T);
        void insertarError(int, T);
        void elimina(nodo<T>*);
        bool vacia();
        void inicializar();
        nodo<T>* primero();
        nodo<T>* sigSimbolo();
        nodo<T>* ultimo();
        nodo<T>* siguiente();
        nodo<T>* anterior(nodo<T>* p);
        bool buscar(string);
        bool buscarVar(string, string);
        char buscarTIP(string, string);
        T buscarPAR(string, string);
        T recupera(nodo<T>* p);
        void imprimir();
        void borrartodo();
    private:
        nodo<T>* encabezado;
};


template <class T>
lista<T>::lista(){
    inicializar();
}

template <class T>
void lista<T>::inicializar(){
    encabezado = NULL;
}

template <class T>
bool lista<T>::vacia(){
    if (encabezado == NULL){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void lista<T>::insertar(T dato){
    nodo<T>* aux = new nodo<T>(dato);

    if(vacia()){
        encabezado = aux;
        aux->setsiguiente(NULL);
        aux->setanterior(NULL);
    }
    else{
        aux->setsiguiente(encabezado);
        aux->setanterior(NULL);
        encabezado->setanterior(aux);
        encabezado = aux;
    }
}

template <class T>
nodo<T>* lista<T>::primero(){
    return encabezado;
}

template <class T>
nodo<T>* lista<T>::sigSimbolo(){
    encabezado = encabezado->siguiente;
    return encabezado;
}

template <class T>
nodo<T>* lista<T>::ultimo(){
    if(vacia()){
        return NULL;
    }
    else{
        nodo<T>* temp = encabezado;
        while(temp->getsiguiente()!= NULL){
            temp = temp->getsiguiente();
        }
        return temp;
    }
}

template <class T>
void lista<T>::imprimir(){
    nodo<T> *tempo = ultimo();
    if(!encabezado){
        cout<<"La Lista esta vacia"<<endl;
    }
    else{
        while(tempo != NULL){
            tempo->getdato().getALL();
            tempo = tempo->getanterior();
        }
    }
}

template <class T>
nodo<T>* lista<T>::siguiente(){
    return encabezado->getsiguiente();
}

template <class T>
nodo<T>* lista<T>::anterior(nodo<T>* p){
    return p->getanterior();
}

template <class T>
bool lista<T>::buscar(string a){
    nodo<T>* temporal = encabezado;
    while(temporal != NULL){
        if(temporal->getdato().getTK() == a){
            return true;
        }
        temporal = temporal->getsiguiente();
    }
    return false;
}

template <class T>
void lista<T>::elimina(nodo<T> *e){
    nodo<T> *temporal=encabezado;
    if(temporal==e){

        encabezado=temporal->getsiguiente();
        temporal->getsiguiente()->setanterior(NULL);
        delete(temporal);
    }
    else{
        while(temporal->getsiguiente() != NULL && temporal != e){
            temporal=temporal->getsiguiente();
        }

        if(temporal->getsiguiente() == NULL){
            nodo<T>  *auxiliar;
            auxiliar = temporal;
            temporal->getanterior()->setsiguiente(NULL);
            delete (auxiliar);
        }
        else{
            nodo<T>  *auxiliar;
            auxiliar = temporal;
            temporal->getsiguiente()->setanterior(temporal->getanterior());
            temporal->getanterior()->setsiguiente(temporal->getsiguiente());
            delete (auxiliar);
        }
    }
}

template <class T>
void lista<T>::borrartodo(){
    while(encabezado!=NULL){
        nodo<T>* aux=encabezado;
        encabezado=encabezado->getsiguiente();
        delete aux;
    }
}

template <class T>
void lista<T>::insertarError(int idE, T dato){
    T errorStr = "";

	switch(idE){
		case 1:
		    cout << "\tERROR Duplicado: " << dato << "Variable Redefinida\n";
			errorStr = "\tERROR Duplicado: " + dato + "Variable Redefinida";
		break;
		case 2:
		    cout << "\tERROR No Definida: " << dato << " Variable No Definida\n";
			errorStr = "\tERROR No Definida: " + dato + " Variable No Definida";
		break;
		case 3:
		    cout << "\tERROR Tipo:  \tExpresion de tipo distinto: " << dato << endl;
			errorStr = "\tERROR Tipo:  \tExpresion de tipo distinto: " + dato ;
		break;
		case 4:
		    cout << "\tERROR Tipo:  \tExpresion de tipo distinto: " << dato << endl;
            errorStr = "\tERROR Tipo:  \tExpresion de tipo distinto: " + dato ;
        break;
        case 5:
			cout << "\tERROR 5: \""<< dato << "\""" Esta funcion no se ha declarado anteriormente" << endl;
			errorStr = "\tERROR 5: \"" + dato + "\""" Esta funcion no se ha declarado anteriormente";
		break;
		case 6:
			cout << "\tERROR 6: \""<< dato << "\""" El Valor Regresa NO es del mismo tipo que la funcion" << endl;
			errorStr = "\tERROR 6: \"" + dato + "\"""  El Valor Regresa NO es del mismo tipo que la funcion";
		break;
		case 7:
			cout << "\tERROR 7: \""<< dato << "\""" No hay suficientes argumentos para la definicion de la funcion" << endl;
			errorStr = "\tERROR 7: \"" + dato + "\""" No hay suficientes argumentos para la definicion de la funcion";
		break;
		case 8:
			cout << "\tERROR 8: \""<< dato << "\""" La llamada a funcion no concuerda en argumentos con la declaracion de la Funcion " << endl;
			errorStr = "\tERROR 8: \"" + dato + "\""" La llamada a funcion no concuerda en argumentos con la declaracion de la Funcion ";
		break;
	}

    nodo<T>* aux = new nodo<T>(errorStr);

    if(vacia()){
        encabezado = aux;
        aux->setsiguiente(NULL);
        aux->setanterior(NULL);
    }
    else{
        aux->setsiguiente(encabezado);
        aux->setanterior(NULL);
        encabezado->setanterior(aux);
        encabezado = aux;
    }
}

template <class T>
bool lista<T>::buscarVar(string id, string ambito){
    nodo<T>* temporal = encabezado;
    while(temporal != NULL){
        if(temporal->getdato().getID() == id and temporal->getdato().getAMB() == ambito){
            return true;
        }
        temporal = temporal->getsiguiente();
    }
    return false;
}

template <class T>
char lista<T>::buscarTIP(string id, string ambito){
    nodo<T>* temporal = encabezado;
    while(temporal != NULL){
        if(temporal->getdato().getID() == id and temporal->getdato().getAMB() == ambito){
            return temporal->getdato().getTIPO();
        }
        temporal = temporal->getsiguiente();
    }
}

template <class T>
T lista<T>::buscarPAR(string id, string ambito){
    nodo<T>* temporal = encabezado;
    while(temporal != NULL){
        if(temporal->getdato().getID() == id and temporal->getdato().getAMB() == ambito){
            return temporal->getdato();
        }
        temporal = temporal->getsiguiente();
    }
}


#endif // LISTA_TOKENS_H_INCLUDED
