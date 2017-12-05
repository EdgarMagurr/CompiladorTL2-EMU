#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class File
{
    public:

    File();
    File(string);
    string readFromFile();
    void parse();
    string *separaElementos(string, unsigned int);

    int **tablaLR;
    int *idReglas;
    int *lonReglas;
    string *nomReglas;

    string nombreArchivo;
};

File::File(){

}

File::File(string nombreArchivo){
    this->nombreArchivo = nombreArchivo;
}


string File::readFromFile(){

    ifstream file;
    const char* archivo = nombreArchivo.c_str();
    file.open(archivo);

    string output = "", line = "";

    if(file.is_open()){
        while(getline(file, line)){
           output +=  line;
        }
    }
    file.close();

return output;
}

void File::parse(){

    ifstream file;
    const char* archivo = nombreArchivo.c_str();
    file.open(archivo);

    if(file.is_open()){

        string line = "";
        getline(file, line);
        unsigned int numero1 = atoi(line.c_str());

        idReglas = new int[numero1];
        lonReglas = new int[numero1];
        nomReglas = new string[numero1];

        for(unsigned int i=0; i<numero1; i++){
            line.clear();
            getline(file, line);
            string *bloque = separaElementos(line, 2);
            idReglas[i] = atoi(bloque[0].c_str());
            lonReglas[i] = atoi(bloque[1].c_str());
            nomReglas[i] = bloque[2];
			cout << "Regla: " << idReglas[i] << " Linea: " << lonReglas[i] << " Nombre: " << nomReglas[i] << "P" << endl;
        }

        line.clear();

        unsigned int filas = 0, columnas = 0;

        getline(file, line);

        string *bloque = separaElementos(line, 1);

        filas = atoi(bloque[0].c_str());
        columnas = atoi(bloque[1].c_str());

        cout << "Filas: " << filas << " Columnas: " << columnas << endl;

        tablaLR = new int*[filas];

        for(unsigned int i = 0; i<filas; i++){
            tablaLR[i] = new int[columnas];
        }

        for(unsigned int i = 0; i<filas; i++){
            line.clear();
            getline(file, line);
            bloque = separaElementos(line, columnas);
            for(unsigned int j = 0; j<columnas; j++){
                tablaLR[i][j] = atoi(bloque[j].c_str());
                //cout << tablaLR[i][j] << "  ,";
            }
            //cout << endl;
            bloque->clear();
        }

    }else{
        cout<<"Error al leer el archivo"<<endl;
    }
    file.close();
}

string* File::separaElementos(string linea, unsigned int numTabuladores){

    string *bloque = new string[60];
    string elemento;

    unsigned int i = 0;
    unsigned int j = 0;

    for(;j<numTabuladores; j++){
        while(linea[i] != '\t' && linea[i] != '\0'){
            elemento += linea[i];
            i++;
        }
        i++;
        bloque[j] = elemento;
        elemento.clear();
    }
    while(linea[i] != '\0'){
        elemento += linea[i];
        i++;
    }
    bloque[j++] = elemento;



return bloque;
}



#endif // FILE_H
