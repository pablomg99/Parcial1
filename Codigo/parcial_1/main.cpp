#include "functions.h"

int main(){
    // nombres de los archivos de texto, tamaño y asignación de memoria para
    // almacenar los datos
    char materiasTxtName[]="materias.txt";
    char horariosTxtName[]="horarios.txt";
    int materiasSize=txtLeng(materiasTxtName);
    int horariosSize=txtLeng(horariosTxtName);
    char* materiasArray;
    char* horariosArray;
    materiasArray=new char[materiasSize];
    horariosArray=new char[horariosSize];

    // horas de inicio y fin de la jornada diaria de estudio
    unsigned int horaInicio, horaFin;

    //matriz de horarios
    int** horariosMatriz;


    textToArray(materiasTxtName, materiasArray, materiasSize);
    textToArray(horariosTxtName, horariosArray, horariosSize);

    cout<<"Ingrese las horas de inicio y fin (en ese orden) de la jornada diaria de estudio,"<<endl<<"escriba solo la hora en formato de 24h, por ejemplo, 8 (enter), 19: "<<endl;
    cin>>horaInicio>>horaFin;

    while(horaFin<horaInicio){
        cout<<"La hora de inicio debe ser menor que la de fin"<<endl<<"Ingrese nuevamente las horas: "<<endl;
        cin>>horaInicio>>horaFin;
    }

    cout<<endl<<"Usted dispone de "<<(horaFin-horaInicio)*6<<" horas semanales destinadas al estudio"<<endl;

    horariosMatriz=makeMatrix(horaInicio, horaFin);
    printMatrix(horariosMatriz, horaFin-horaInicio, 6);


    //=========================== DELETE =====================================
    delete[] materiasArray;
    delete[] horariosArray;

    for (int i=0; i<horaFin-horaInicio; i++){
        delete[] horariosMatriz[i];
    }
    delete[] horariosMatriz;

    return 0;
}
