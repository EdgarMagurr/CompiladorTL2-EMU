#ifndef EJERCICIO1_H
#define EJERCICIO1_H

int tablaLR[3][3]=
{
    2, 0, 1,
    0, -1, 0,
    0, -2, 0
};

Pila pila;
int fila, columna, accion;
bool aceptacion = false;

Tokenizer token("a");
pila.push(token.cPESOS);
pila.push(0);
token.sigSimbolo();

fila = pila.top();
columna = token.getTipo();
accion = tablaLR[fila][columna];
cout << "stack: ";
pila.muestra();
cout << "entrada: " << token.getSimbolo() << endl;
cout << "accion: " << accion << endl << endl;

pila.push(token.getTipo());
pila.push(accion);
token.sigSimbolo();

fila = pila.top();
columna = token.getTipo();
accion = tablaLR[fila][columna];
cout << "stack: ";
pila.muestra();
cout << "entrada: " << token.getSimbolo() << endl;
cout << "accion: " << accion << endl << endl;

pila.pop();
pila.pop();
fila = pila.top();
columna = 2;
accion = tablaLR[fila][columna];
pila.push( 2 );
pila.push( accion );

cout << "stack: ";
pila.muestra();
cout << "entrada: " << token.getSimbolo() << endl;
cout << "accion: " << accion << endl << endl;
fila = pila.top();
columna = token.getTipo();
accion = tablaLR[fila][columna];

cout << "stack: ";
pila.muestra();
cout << "entrada: " << token.getSimbolo() << endl;
cout << "accion: " << accion << endl << endl;

aceptacion = accion == -1;

if (aceptacion){
    cout << "aceptación" << endl;
}

#endif // EJERCICIO1_H
