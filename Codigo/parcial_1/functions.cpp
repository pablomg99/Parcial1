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
    //matriz[horas][6]
    //filas=hf-hi, columnas=6
    int filas=hf-hi;
    int** matriz=new int*[filas];
    for(int i=0; i<filas; i++){
        matriz[i]=new int[6];

        for(int j=0; j<6; j++){
            matriz[i][j]=0;
        }
    }

    return matriz;
}

void printMatrix(int** matriz, int filas, int columnas){
    for(int f=0; f<filas; f++){
        for(unsigned short c=0;c<columnas;c++){
            cout << matriz[f][c] << '\t';
        }
        cout << endl << endl;
    }

}
