//Headers
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include "eigen3/Eigen/Dense"


class functions
{
    std::string tamanoM;

public:
    functions(std::string tamano):
            tamanoM(tamano){}

    //Caso 1
        Eigen::Matrix3i GenerateA();
        Eigen::Matrix3i GenerateB();
    //Caso 2
        Eigen::Matrix3i GeneratetwoA();
        Eigen::Matrix3i GenerateI();
    //Caso 3
        Eigen::Matrix3i GeneratePow();
        Eigen::Matrix3i expo(Eigen::Matrix3i m, int n);
    //Caso 4
        Eigen::Matrix3d GeneratefourA();
    //Caso 5
        Eigen::MatrixXd matrizza();
        Eigen::MatrixXd matrizzb();
    //Caso 6
        Eigen::MatrixXd MatrixP();
        Eigen::MatrixXd MatrixC();
    //Caso 8
        Eigen::Matrix2d GenA();
        Eigen::Matrix2d GenB();
        Eigen::Matrix2d GenC();
        Eigen::Matrix2d GenI();
};

#endif // FUNCTIONS_H
