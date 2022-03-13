/*
    *Fecha: 07/03/2022
    *Autor: Daniel HIlarión Rojas.
    *Materia: HPC.
    *Tema: Primer Parcial Operación con matrices
*/


#include "Functions/functions.h"
#include <iostream>
#include "eigen3/Eigen/Dense"

using namespace std;

typedef Eigen::Matrix<double,3,2> Matrix32d;
typedef Eigen::Matrix<double,2,3> Matrix23d;

int main(){



    functions objeto("5");
    //Objetos caso 1 menú principal
    Eigen::Matrix3i matrixA = objeto.GenerateA();
    Eigen::Matrix3i matrixB = objeto.GenerateB();
    //Objetos caso 2 menú principal
    Eigen::Matrix3i matrixtwoA = objeto.GeneratetwoA();
    Eigen::Matrix3i matrixI = objeto.GenerateI();
    //Objetos caso 3 menú principal
    Eigen::Matrix3i matrixPow = objeto.GeneratePow();
    //Objetos caso 4 menú principal
    Eigen::Matrix3d matrixfourA = objeto.GeneratefourA();
    //Objetos caso 5 menú principal
    Matrix23d matriza = objeto.matrizza();
    Matrix23d matrizb = objeto.matrizzb();
    //Objetos caso 6 menú principal
    Matrix23d MatrizP = objeto.MatrixP();
    Matrix32d MatrizC = objeto.MatrixC();
    //Objetos caso 8 menú principal
    Eigen::Matrix2d matrixesA = objeto.GenA();
    Eigen::Matrix2d matrixesB = objeto.GenB();
    Eigen::Matrix2d matrixesC = objeto.GenC();
    Eigen::Matrix2d matrixesI = objeto.GenI();



    int start=0;

//Menú principal
    do
    {

        cout<<"°°°°°°°°°°°°°°°°°°°HPC°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
        cout << "1. Operación básica con matrices"<<endl;
        cout << "2. Realizar demostración A^{2} - A -2I = 0"<<endl;
        cout << "3. n-ésima potencia de la matriz"<<endl;
        cout << "4. Matriz inversa"<<endl;
        cout << "5. Sistema de ecuaciones con matrices "<<endl;
        cout << "6. Análisis de problemas usando matrices "<<endl;
        cout << "7. Rango de una matriz "<<endl;
        cout << "8. Ecuaciones de una matr Eigen::Matrix2i Genc();ixA+matrixBincógnita en matrices "<<endl;
        cout << "9. De un sistema de ecuaciones a una matriz"<<endl;
        cout << "10. EXIT "<<endl;

        int opcion = 0;

        cin >> opcion;

        system("clear");

        switch(opcion)
        {
        int opcion1;
        int opcion3;

            case 1:
            //Menú secundario para opción 1
                system("clear");

                cout<<"°°°°°°°°°°°°°°°°°°°°HPC°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cout << "Operación básica con matrices"<<endl;
                cout << "1. Suma entre matrices"<<endl;
                cout << "2. Resta entre matrices"<<endl;
                cout << "3. Multiplicación entre matrices (A*B)"<<endl;
                cout << "4. Multiplicación ent<<re matrices (B*A)"<<endl;
                cout << "5.  A^{t}"<<endl;
                cout<<"°°°°°°°°°°°°°°°°°°°°HPC°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cin >> opcion1;

                switch(opcion1)
                {

                    case 1:
                       cout << "Suma entre matrices"<<endl;
                       cout << matrixA+matrixB<<endl;
                    break;

                    case 2:
                       cout << "Resta entre matrices"<<endl;
                       cout << matrixA-matrixB<<endl;
                    break;

                    case 3:
                       cout << "Multiplicación entre matrices (A*B)"<<endl;
                       cout << matrixA*matrixB<<endl;
                    break;

                    case 4:
                       cout << "Multiplicación entre matrices (B*A)"<<endl;
                       cout << matrixB*matrixA<<endl;
                    break;

                    case 5:
                       cout << "A^{t}"<<endl;
                       cout << matrixA.transpose()<<endl;
                    break;
                     default: cout << "Usted ha ingresado una opción incorrecta";
                 }


            break;

            case 2:
                cout << "2. Demostración"<<endl;
                cout <<(matrixtwoA*matrixtwoA) - matrixtwoA - 2*matrixI <<endl;
            break;

            case 3:
                cout << "3. n-ésima potencia de la matriz"<<endl;
                cout << objeto.expo(matrixPow,2)<<endl;
            break;

            case 4:
                cout << "4. Matriz inversa"<<endl;
                cout << matrixfourA.inverse()<<endl;
            break;

            case 5:
                cout << "5. Sistema de ecuaciones con matrices"<<endl;
                cout<<"Ecuacion 1"<<endl;
                cout<<matriza<<endl;
                cout<<""<<endl;
                cout<<""<<endl;
                cout<<"Ecuacion 2"<<endl;
                cout<<matrizb<<endl;
                cout<<""<<endl;
                cout<<"Ecuacion 2 por -2"<<endl;
                cout<<matrizb*(-2)<<endl;
                cout<<""<<endl;
                cout<<"Suma elemento a elemento para B"<<endl;
                cout<<matriza+(matrizb*-2)<<endl;
                cout<<""<<endl;
                cout<<"Se despeja B"<<endl;
                cout<<(matriza+(matrizb*-2))/7<<endl;
                cout<<""<<endl;
                cout<<"Ecuación 1 * 3 y suma por elemento"<<endl;
                cout<<(matriza*3)+matrizb<<endl;
                cout<<""<<endl;
                cout<<"___________----Se despeja A----______"<<endl;
                cout<<((matriza*3)+matrizb)/7<<endl;
                cout<<""<<endl;
                cout<<"___________----Matriz--------__________ resultante\n"<<endl;
                cout<<(matriza+(matrizb*-2))/7<<endl;


            break;

            case 6:
                cout << "6. Matriz inversa"<<endl;
                cout<<"------------Matriz de produccion------------"<<endl;
                cout<<MatrizP<<endl;
                cout<<""<<endl;
                cout<<""<<endl;
                cout<<"------------Matriz de costo------------------"<<endl;
                cout<<MatrizC<<std::endl;
                cout<<""<<endl;
                cout<<""<<endl;
                cout<<"------------Horas de taller y de administración-----------"<<endl;
                cout<<MatrizP*MatrizC<<endl;
                cout<<""<<endl;
                cout<<""<<endl;
            break;

            case 7:
                cout << "7. Ecuaciones de una incógnita en matrices"<<endl;
            break;

            case 8:
                cout << "8. De un sistema de ecuaciones a una matriz"<<endl;

                cout<<"°°°°°°°°°°°°°°°°°°°°HPC°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cout << "Operaciones"<<endl;
                cout << "1. XA=B+I"<<endl;
                cout << "2. AX+B=C"<<endl;
                cout << "3. AX+B=2C"<<endl;
                cout << "4. AX+BX=C"<<endl;
                cout << "5. XAB-XC=2"<<endl;

                cin>>opcion3;

                switch(opcion3){
                    case 1:
                        system("clear");
                        cout << "1. XA = B + I"<<endl;
                        cout<<""<<(matrixesB+matrixesI)*(matrixesA.inverse())<<endl<<endl;
                        break;
                     case 2:
                        system("clear");
                        cout << "2. C  = B + AX"<<endl;
                        cout<<"\n"<<(matrixesA.inverse())*(matrixesC-matrixesB)<<endl<<endl;
                        break;
                     case 3:
                        system("clear");
                        cout << "3. 2C = B + XA"<<endl;
                        cout<<"\n"<<((2*matrixesC)-matrixesB)*(matrixesA.inverse())<<endl<<endl;
                        break;
                     case 4:
                        system("clear");
                        cout << "4. C = BX + AX"<<endl;
                        cout<<"\n"<<((matrixesA+matrixesB).inverse())*matrixesC<<endl<<endl;
                        break;
                     case 5:
                        system("clear");
                        cout << "5. 2C = XC + XAB"<<endl;
                        cout<<"\n"<<((2*matrixesC)*((matrixesA*matrixesB)-matrixesC).inverse())<<endl<<endl;
                        break;

                     default:cout<<"Incorrecto";
             }

        }
    }while(start==0);

        return 0;
      }

