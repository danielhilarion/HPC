//Headers
#include "functions.h"
#include "eigen3/Eigen/Dense"

//Función que genera la matriz a
Eigen::Matrix3i functions::GenerateA(){
    Eigen::Matrix3i a;
    a << 2, 0, 1,
         3, 0, 0,
         5, 1, 1;
    return a;
}


//Función que genera la matriz b
Eigen::Matrix3i functions::GenerateB(){
    Eigen::Matrix3i b;
    b << 1, 0, 1,
         1, 2, 1,
         1, 1, 0;
    return b;
}

//°°°°°°°°°°°°°°°Funciones caso 2 menú principal

//Matriz a
Eigen::Matrix3i functions::GeneratetwoA(){
    Eigen::Matrix3i a;
    a << 0, 1, 1,
         1, 0, 1,
         1, 1, 0;
    return a;
}

//Matriz inversa
Eigen::Matrix3i functions::GenerateI(){
    Eigen::Matrix3i b;
    b << 1, 0, 0,
         0, 1, 0,
         0, 0, 1;
    return b;
}

//°°°°°°°°°°°°°°°Funciones caso 3 menú principal

//n-ésima potencia de la matriz
Eigen::Matrix3i functions::GeneratePow(){
    Eigen::Matrix3i b;
    b << 1, 0, 1,
         0, 1, 0,
         0, 0, 1;
    return b;
}
Eigen::Matrix3i functions::expo(Eigen::Matrix3i m, int n) {
    if(n < 1)
             throw;
         if(n == 1)
            return m;
         return (m*expo(m, n - 1));
}


//°°°°°°°°°°°°°°°Funciones caso 4 menú principal

//Matriz A
Eigen::Matrix3d functions::GeneratefourA(){
    Eigen::Matrix3d a;
    a << 1, -1, 0,
         0, 1, 0,
         2, 0, 1;
    return a;
}

//°°°°°°°°°°°°°°°Funciones caso 5 menú principal
Eigen::MatrixXd functions::matrizza(){
    Eigen::MatrixXd m(2,3);
    m << 1, 2, 2,
         -2, 1, 0;
    return m;
}

Eigen::MatrixXd functions::matrizzb(){
    Eigen::MatrixXd m(2,3);
    m << -4, -3, -2,
         -1, 0, -1;
    return m;
}

//°°°°°°°°°°°°°°Funciones caso 6°°°°°°°°°°
Eigen::MatrixXd functions::MatrixP(){
    Eigen::MatrixXd a(2,3);
    a << 400,200,50,
         300,100,30;
    return a;
}

Eigen::MatrixXd functions::MatrixC(){
    Eigen::MatrixXd a(3,2);
    a << 25,1,
         30,1.2,
         33,1.3;
    return a;
}

//°°°°°°°°°°°°°°Funciones caso 8°°°°°°°°°°
Eigen::Matrix3i functions::GenA(){
    Eigen::Matrix2i a;
    a << 1, 1,
         3, 4;
    return a;
}
Eigen::Matrix3i functions::GenB(){
    Eigen::Matrix2i b;
    b << 2, 1,
         1, 1;
    return a;
}
Eigen::Matrix2i functions::GenC(){
    Eigen::Matrix3i c;
    c << 1, 2,
         1, 3;
    return a;
}
