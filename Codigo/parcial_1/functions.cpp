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
