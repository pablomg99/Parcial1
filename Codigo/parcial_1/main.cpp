#include "functions.h"

int main(){
    // nombres de los archivos de texto, tamaño y asignación de memoria para
    // almacenar los datos
    char materiasTxtName[]="materias.txt";
    char horariosTxtName[]="horarios.txt";
    int materiasSize=txtLeng(materiasTxtName);
    int horariosSize=txtLeng(horariosTxtName);
    int inicioSegmentoMaterias=0;
    char semestre; //semestre a cursar
    char* materiasArray;
    char* materiasAux;
    char* horariosArray;
    char* horariosAux;
    materiasArray=new char[materiasSize];
    horariosArray=new char[horariosSize];
    unsigned int horaInicio, horaFin; // horas de inicio y fin de la jornada diaria de estudio
    int** horariosMatriz;  //matriz de horarios


    textToArray(materiasTxtName, materiasArray, materiasSize);
    textToArray(horariosTxtName, horariosArray, horariosSize);

    cout<<"Ingrese las horas de inicio y fin (en ese orden) de la jornada diaria de estudio,"<<endl<<"escriba solo la hora en formato de 24h, por ejemplo, 8 (enter), 19: "<<endl;
    cin>>horaInicio>>horaFin;

    while(horaFin<horaInicio or horaInicio>24 or horaInicio<0 or horaFin>24 or horaFin<0){
        cout<<"La hora de inicio debe ser menor que la de fin y ambas entre 0 y 24"<<endl<<"Ingrese nuevamente las horas: "<<endl;
        cin>>horaInicio>>horaFin;
    }

    cout<<endl<<"Usted dispone de "<<(horaFin-horaInicio)*6<<" horas semanales destinadas al estudio"<<endl;

    horariosMatriz=makeMatrix(horaInicio, horaFin);
    //printMatrix(horariosMatriz, horaFin-horaInicio, 6);

    cout<<"Ingrese el semestre a cursar: "<<endl;
    cin>>semestre;

    int tamanoSegmentoMaterias=tamanoSegmento(110, semestre, materiasSize, materiasArray, 0, 1, &inicioSegmentoMaterias);


    //=========================== DELETE =====================================
    delete[] materiasArray;
    delete[] horariosArray;

    for (int i=0; i<horaFin-horaInicio; i++) {
        delete[] horariosMatriz[i];
    }
    delete[] horariosMatriz;
    delete[] materiasAux;

    return 0;
}
