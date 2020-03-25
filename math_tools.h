#include <vector>
#include "stdlib.h"
#include "math.h"
using namespace std;

typedef vector<float> Vector; 

typedef vector<Vector> Matrix; //vector de numeros reales

//Creacion de funciones para hacer operaciones

//Funcion de un vector que tenga 0 en todas sus posiciones
void zeroes(Vector &v, int n){
    for(int i=0; i<n; i++)
    v.push_back(0.0); //agregando un dato a un vector
}

//Funcion que llena de ceros una matriz
void zeroes(Matrix &M, int n){
    for(int i=0; i<n; i++){
        Vector row(n, 0.0); //Creando un vector que en su posicion (fila) tenga ceros
        M.push_back(row);
    }
}

//Funcion para copiar la informacion de un vector a otro vector
void copyVector(Vector v, Vector &copy){
    zeroes(copy, v.size());
    //recorriendo el vector original para guardar los datos en la copia
    for(int i=0; i<v.size(); i++)
    copy.at(i) = v.at(i); //guardando el valor del vector original
}

//Funcion para copiar la informacion de una matriz a otra matriz
void copyMatrix(Matrix A, Matrix &copy){
    zeroes(copy, A.size());

    for(int i=0;i<A.size(); i++)
        for(int j=0; j<A.at(0).size(); j++)
        copy.at(i).at(j) = A.at(i).at(j);
}

//Funcion para multiplicar una matriz y un vector
void productMatrixVector(Matrix A, Vector v, Vector &R){
//Bucle para inicializar una fila
    for(int fila=0; fila<A.size(); fila++){
        float cell = 0.0;
        //Bucle para inicializar una columna
        for(int col=0; col<v.size(); col++)
        cell += A.at(fila).at(col) = v.at(col);
        R.at(fila) += cell;
    }
}

//Funcion que multiplica un numero real con una matriz
void productLinealMatrix(float real, Matrix M, Matrix &R){
    zeroes(R, M.size()); //Inicializando la matriz resultado

    for(int i=0; i<M.size(); i++)
        for(int j=0; j<M.at(0).size(); j++)
        R.at(i).at(j) = real * M.at(i).at(j);
}

//Funcion para sumar 2 vectores y que retorne la suma en un vector
Vector sumVector(Vector A, Vector B, int n){
    Vector R; //Vector resultado
    zeroes(R, n);
    for(int i=0; i<n; i++)
    R.at(i) = A.at(i) + B.at(i);
    return R;
}

//Funcion para sumar matrices y que devuelva una matriz
Matrix sumMatrix(Matrix A, Matrix B, int n, int m){
    Matrix R; //Matriz resultado
    zeroes(R, n); //Para matriz cuadrada

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            R.at(i).at(j) = A.at(i).at(j) + B.at(i).at(j);
}

//Funcion para transponer una matriz
void transpose(Matrix M, Matrix &T){
    zeroes(T, M.size()); //Inicializando la matriz transpuesta

    for(int i=0; i<M.size(); i++)
        for(int j=0;j<M.at(0).size(); j++)
        T.at(j).at(i) = M.at(i).at(j);
}

//Funcion para eliminar fila y columna de la matriz
void getMinor(Matrix &M, int i, int j){
    M.erase(M.begin()+i);

    for(int i=0; i<M.size(); i++)
        M.at(i).erase(M.at(i).begin()+j);
}

//Funcion para calcular el determinante de una matriz
float determinante(Matrix M){
    if(M.size() == 1) //caso trivial
    return M.at(0).at(0);
    else{
        float det = 0.0;
        for(int i=0; i<M.at(0).size(); i++){
            Matrix minor;
            copyMatrix(M, minor);
            getMinor(minor, 0, i);
            det += pow(-1, i) * M.at(0).at(i) * determinante(minor);
        }
        return det;
    }
}

//La funcion recibe saca el cofactor de una matriz.
//La funcion recibe: Una matriz y la matriz que contendra los cofactores de la primera.
void cofactors(Matrix M, Matrix &Cof){
    //Se prepara la matriz de cofactores para que sea de las mismas
    //dimensiones de la matriz original
    zeroes(Cof,M.size());
    //Se recorre la matriz original
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            //Se obtiene el menor de la posicion actual
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);
            //Se calcula el cofactor de la posicion actual
            //      alternante * determinante del menor de la posicion actual
            Cof.at(i).at(j) = pow(-1,i+j)*determinante(minor);
        }
    }
}

//INICIO TAREA 01 LABORATORIO SIMULACION (FUNCION MATRIZ INVERSA)
void inverseMatrix(Matrix M, Matrix &inversa){

    //calculando el determinante de la matriz ingresada
    float mDeterminante = determinante(M);

    //Matriz adjunta y la transpuesta
    Matrix mTranspuesta;
    Matrix mAdjunta;

    if(mDeterminante != 0){

        float inverseM = 1/mDeterminante;
        //transponiendo la matriz original en la matriz adjunta
        transpose(M, mTranspuesta);
        //calculando los cofactores de la matriz adjunta
        cofactors(mTranspuesta, mAdjunta);

        productLinealMatrix(inverseM, mAdjunta, inversa);

    }else{
        exit(EXIT_FAILURE);
    }
}