#include <iostream>
#include "math_tools.h"

using namespace std;
//Funcion para mostrar vectores
//No se manda por referencia ya que no se desea modificar su contenido sino que solo desea visualizarse
void showVector(Vector b){
    cout << "[\t" ;
    for(int i=0; i<b.size(); i++)
    cout << b.at(i) << "\t";
    cout << "]\n";
}

//Funcion para mostrar matrices
void showMatrix(Matrix k){
    for(int i=0; i<k.at(0).size(); i++){
        cout << "[\t";
        for(int j=0; j<k.size(); j++)
        cout << k.at(i).at(j) << "\t";
        cout << "]\n";
    }
}