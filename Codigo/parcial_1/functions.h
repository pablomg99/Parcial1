#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
using namespace std;

int txtLeng(char text[]);
void textToArray(char text[], char* arreglo, int leng);
int** makeMatrix(int hi, int hf);
void printMatrix(int** matriz, int filas, int columnas);


#endif // FUNCTIONS_H
