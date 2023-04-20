#include "functions.h"
fstream str;

int txtLeng(char text[]){
    int leng;
    str.open(text, ios_base::in | ios_base::ate);
    leng = str.tellg();
    str.close();

   return leng;
}

void textToArray(char text[], char* arreglo, int leng){
   str.open(text, ios_base::in);
   str.seekg(0);
   str.read(arreglo, leng);
   str.close();
}

int** makeMatrix(int hi, int hf){
    int filas=hf-hi;
    int** matriz=new int*[filas];
    for(int i=0; i<filas; i++){
        matriz[i]=new int[6];
    }

    return matriz;
}

void printMatrix(int** matriz, int filas, int columnas){
    cout << endl;
    for(int f=0; f<filas; f++){
        for(int c=0; c<columnas; c++){
            cout << matriz[f][c] << '\t';
        }
        cout << endl << endl;
    }

}

int tamanoSegmento(char primerCaracter, char segundoCaracter, int tamanoMaterias, char* arreglo, int sumaChar1, int sumaChar2, int* inicio){
    int contador=1;
    bool flag=false;
    for(int i=0; i<tamanoMaterias; i++){
        if(*(arreglo+i)==primerCaracter and *(arreglo+i+1)==segundoCaracter){
            *inicio=i+3;
            flag=true;
        }
        if(flag){
            contador++;
            cout<<*(arreglo+i);
        }

        if(*(arreglo+i+1)==(primerCaracter+sumaChar1) and *(arreglo+i+2)==(segundoCaracter+sumaChar2)){
            flag=false;
            break;
        }
    }
    return contador;
    /*auxArray=new char[contador];

    for(int i=inicio; i<(inicio+(contador-4)); i++){
       *(auxArray+i)=*(arreglo+i);
    }*/


    //return arregloAux;
}
