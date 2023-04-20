#include "functions.h"

int main(){
    char materiasTxtName[]="materias.txt";
    char horariosTxtName[]="horarios.txt";
    int materiasSize=txtLeng(materiasTxtName);
    int horariosSize=txtLeng(horariosTxtName);
    char* materiasArray;
    char* horariosArray;

    materiasArray=new char[materiasSize];
    horariosArray=new char[horariosSize];

    textToArray(materiasTxtName, materiasArray, materiasSize);
    textToArray(horariosTxtName, horariosArray, horariosSize);

    cout<<horariosArray<<endl;

    delete[] materiasArray;
    delete[] horariosArray;

    return 0;
}
