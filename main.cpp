#include <iostream>
#include "display_tools.h"

int main(void){

    //TAREA 01 LABORATORIO SIMULACION

    Matrix example_matriz, matriz_inversa;

    zeroes(example_matriz, 3);

    example_matriz.at(0).at(0) = 2; example_matriz.at(0).at(1) = 2; example_matriz.at(0).at(2) = 3;
    example_matriz.at(1).at(0) = 4; example_matriz.at(1).at(1) = 5; example_matriz.at(1).at(2) = 6; 
    example_matriz.at(2).at(0) = 7; example_matriz.at(2).at(1) = 8; example_matriz.at(2).at(2) = 9;

    inverseMatrix(example_matriz,matriz_inversa);

    showMatrix(matriz_inversa);  


    /*Parte I Introduccion 
        Vector zeroes_vector; //creando un dato de tipo vector
        zeroes(zeroes_vector, 5);
        showVector(zeroes_vector);

        Matrix zeroes_matrix; //creando un dato de tipo matriz
        zeroes(zeroes_matrix, 5);
        showMatrix(zeroes_matrix); */

    /*Parte II Matematica como pseudocodigo
    Matrix example_matriz;

    zeroes(example_matriz, 3); //inicializacion de la matriz

    example_matriz.at(0).at(0) = 1; example_matriz.at(0).at(1) = 2; example_matriz.at(0).at(2) = 3;
    example_matriz.at(1).at(0) = 4; example_matriz.at(1).at(1) = 5; example_matriz.at(1).at(2) = 6;
    example_matriz.at(1).at(0) = 7; example_matriz.at(2).at(1) = 8; example_matriz.at(2).at(2) = 9;
    
    showMatrix(example_matriz); */

    /*Parte III Matrix * Vector 

    //Para multiplicar un numero real con una matriz
    Vector example_vector, copy_vector;

    zeroes(example_vector, 4); //se inicializa el vector original

    example_vector.at(0) = 3;
    example_vector.at(1) = 6;
    example_vector.at(2) = 9;
    example_vector.at(3) = 12;

    copy_vector(example_vector, copy_vector);

    showVector(copy_vector); 

    Vector example_vector, answer_vector;
    Matrix example_matrix;

    zeroes(example_vector, 3); //inicializando vector

    example_vector.at(0) = 2;
    example_vector.at(1) = 2;
    example_vector.at(2) = 2;

    zeroes(example_matrix, 3); //inicializando matriz

    example_matrix.at(0).at(0) = 1; example_matrix.at(0).at(1) = 1; example_matrix.at(0).at(2) = 1;
    example_matrix.at(1).at(0) = 1; example_matrix.at(1).at(1) = 1; example_matrix.at(1).at(2) = 1;
    example_matrix.at(2).at(0) = 1; example_matrix.at(2).at(1) = 1; example_matrix.at(2).at(2) = 1;
    
    zeroes(answer_vector,3); //inicializando vector respuesta ya que no se inicializo en la funcion
    showVector(answer_vector); */

    /* Parte IV Miscelaneos */
   /* Matrix example_matrix, answer_matrix;
    
    float real = 2.5;

    zeroes(example_matrix,3);

    example_matrix.at(0).at(0) = 1; example_matrix.at(0).at(1) = 1; example_matrix.at(0).at(2) = 1;
    example_matrix.at(1).at(0) = 1; example_matrix.at(1).at(1) = 1; example_matrix.at(1).at(2) = 1;
    example_matrix.at(2).at(0) = 1; example_matrix.at(2).at(1) = 1; example_matrix.at(2).at(2) = 1;

    productLinealMatrix(real,example_matrix,answer_matrix);
    showMatrix(answer_matrix); /*
    
    //Para sumar 2 vectores
    /*Vector a, b;

    zeroes(a, 5);
    zeroes(b, 5);

    a.at(0) = 1;
    a.at(1) = 2;
    a.at(2) = 3;
    a.at(3) = 4;
    a.at(4) = 5;

    b.at(0) = 1;
    b.at(1) = 2;
    b.at(2) = 3;
    b.at(3) = 4;
    b.at(4) = 5;

    showVector(sumVector(a,b,5));//Se manda la funcion de un solo porque esta ya retorna un dato

    //Para transponer una matriz
    Matrix example_matrix, transpose_matrix;

    zeroes(example_matrix,3);

    example_matrix.at(0).at(0) = 1; example_matrix.at(0).at(1) = 2; example_matrix.at(0).at(2) = 3;
    example_matrix.at(1).at(0) = 4; example_matrix.at(1).at(1) = 5; example_matrix.at(1).at(2) = 6;
    example_matrix.at(2).at(0) = 7; example_matrix.at(2).at(1) = 8; example_matrix.at(2).at(2) = 9;

    transpose(example_matrix, transpose_matrix);

    showMatrix(transpose_matrix); */

    /*Parte V Determinantes */
    
    return 0;
}