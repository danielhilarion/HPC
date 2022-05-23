/*

  Autor: Daniel Hilarión Rojas


*/

#include "EXTRACTION/extractiondata.h"
#include "regresionlineal.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <boost/algorithm/string.hpp>

using namespace std;

int main(int argc, char* argv[]){

    /*Se instancia el objeto de la clase extracción a extraer*/
    ExtractionData extraer(argv[1], argv[2], argv[3]);

    /*Se instancia el objeto Regresión lineal a RL*/
    RegresionLineal RL;

    vector<vector<string>> dataSET = extraer.ReadCSV();

    int filas = dataSET.size() + 1;
    int columnas = dataSET[0].size();


    Eigen::MatrixXd DataFrame = extraer.CSVtoEigen(dataSET, filas, columnas);


    /*
    cout<<DataFrame<<endl;
*/

    //Imprimir función promedio
    cout<<" Promedio de los datos:"<<endl;
    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
    cout<<extraer.Promedio(DataFrame)<<endl;
    cout<<endl;
    cout<<endl;

    //Imprimir función desviación
    cout<<" Desviación Standard de los datos:"<<endl;
    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
    cout<<extraer.DesvStandard(DataFrame)<<endl;
    cout<<endl;
    cout<<endl;

    //Imprimir función normalización
    cout<<" Normalización:"<<endl;
    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
    cout<<extraer.Normalizador(DataFrame)<<endl;
    cout<<endl;
    cout<<endl;

    Eigen::MatrixXd matNormal = extraer.Normalizador(DataFrame);


    /*
    1. Se hara el primer modulo para machine learning
    2. Se requiere clase regresión líneal, implementación e interfaz
    3. Debe definir el constructor
    4. Importar bibliotecas, tener en cuenta que el metodo de regresión lineal es estadistico
    5. El metodo define la relacion entre las variables dependientes con las independientes
    6. Objetivo, definir una línea recta(Hiperplano)
    */


    Eigen::MatrixXd X_train, y_train, X_test, y_test;

    //Empaquetado de tupla
    tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> empaquetado = extraer.TrainTestDiv(matNormal, 0.8);

    //Desempaquetado en cuatro grupos de datos
    tie(X_train, y_train, X_test, y_test) = empaquetado;

    //Se imprime total de filas, las filas para entrenamiento, las filas para prueba en sus dos sabores
/*
    cout<<matNormal.rows()<<endl;
    cout<<X_train.rows()<<endl;
    cout<<y_train.rows()<<endl;
    cout<<X_test.rows()<<endl;
    cout<<y_test.rows()<<endl;

    //Se necesita imprimir la cantidad de columns por sabor
    cout<<matNormal.cols()<<endl;
    cout<<X_train.cols()<<endl;
    cout<<y_train.cols()<<endl;
    cout<<X_test.cols()<<endl;
    cout<<y_test.cols()<<endl;
*/

    /*Se tiene en cuenta que la regresión líneal es un metodo estadistico
     * La ide principal es crear un hiperplano con tantas dimensioens como
     * variables independientes tenga el conjunto de datos de entrada
     * (pendientes/pesos y punto de corte).
     * Se hace la prueba del modelo: Se crea un vector para prueba y
     * entrenamiento inicializado en "unos", que corrersponden a nuestros
     * features o variables independientes*/
    Eigen::VectorXd vectorTrain = Eigen::VectorXd::Ones(X_train.rows());
    Eigen::VectorXd vectorTest = Eigen::VectorXd::Ones(X_test.rows());

    /*Se redimensionan las matrices para ser ubicadas en los vectores
     * anteriores. Similar a reshape de numpy*/

    X_train.conservativeResize(X_train.rows(), X_train.cols()+1);
    X_train.col(X_train.cols()-1)=vectorTrain;

    X_test.conservativeResize(X_test.rows(), X_test.cols()+1);
    X_test.col(X_test.cols()-1)=vectorTest;

    /*Se define el vector theta, para pasar al algoritmo del GD,
     * basicamente es un vector de ceros del mismo tamaño de entrenamiento
     * Adicionalmente se declara alfa y el número de iteraciones*/

    Eigen::VectorXd vectorTheta = Eigen::VectorXd::Zero(X_train.cols());
    float alfa = 0.01;
    int iterator = 1000;
    /*Se definen las variables de salida que representan los coeficientes
     * del vector de costo*/
    Eigen::VectorXd thetaOut;
    std::vector<float> costo;

    /*Tocara desempaquetar la tupla obtenida del objeto de la clase
     * RegresionLineal*/
    std::tuple<Eigen::VectorXd, std::vector<float>> salidaGD = RL.Gradiente(X_train, y_train, vectorTheta, alfa, iterator);
    std::tie(thetaOut, costo) = salidaGD;
    /*std::cout<<thetaOut<<std::endl;
     Se quiere observar como decrece la función de costo*/
    /*for(auto v: costo){
        std::cout<<v<<std::endl;
    }*/

    /* A continucaion por propositos de trazabilidad se exportan el vector Theta a ficheros */

   /*
   extraer.vectorToFile(costo, "vectorCosto.txt");
   extraer.matrixToFile(thetaOut, "vectorTheta.txt");
   */

   /* Con el propsosito de ajustar el modelo y hacer predicciones necesarias, calculamos
    * el nuevo promedio y la desviacion estandar basada en los datos para cacular y_hat
    *(o prediccion de los valores y según el modelo)
   */
    auto MuPromedio = extraer.Promedio(DataFrame);
    auto MuFeatures = MuPromedio(0,6);
    auto EscaldaData = DataFrame.rowwise()-DataFrame.colwise().mean();
    auto MuEstandar = extraer.DesvStandard(EscaldaData);
    auto DevFeatures = MuEstandar(0,6);

    Eigen::MatrixXd y_train_hat=(X_train*thetaOut*DevFeatures).array()+MuFeatures;
    Eigen::MatrixXd y=DataFrame.col(6).topRows(1070);

    /* A continuacion se determina que tan bueno es el modelo*/
    float Result = RL.MetricaR2(y, y_train_hat);
    std::cout<<"Rendimiento Train:"<<std::endl;
    std::cout<<Result<<std::endl;

    extraer.matrixToFile(y_train_hat, "Prediccion.txt");

    /* Se define el vector theta, para pasar el alortimo del GD,
            * basicamento es un vector de 0 del mismo tamaño de entrenamiento,
            * adicional se declara alfa y el numero de iteraciones*/
            Eigen::VectorXd vectorThetaTest = Eigen::VectorXd::Zero(X_test.cols());


            Eigen::VectorXd thetaOutTest;
            std::vector<float>costoTest;


            std::tuple<Eigen::VectorXd, std::vector<float>> salidaGDTest = RL.Gradiente(X_test, y_test,vectorThetaTest,alfa,iterator);
            std::tie(thetaOutTest, costoTest) = salidaGDTest;
            /* std::cout<<thetaOut<<std::endl; */

           /* Se quiere observar como decrese la función de costo */
           /*for(auto v: costo){
                std::cout<<v<<std::endl;
            }*/

            /* Acontinuación por propositos de seguridad se exportan el vector de costo y el
             * vector theta a ficheros*/
            extraer.vectorToFile(costoTest, "vectorCostoT.txt");
            extraer.matrixToFile(thetaOutTest, "vectorThetaT.txt");

            //TEST
            auto MuPromedioTest= extraer.Promedio(DataFrame);
            auto MuFeaturesTest= MuPromedioTest(0,6);
            auto EscaladaDataTest= DataFrame.rowwise()-DataFrame.colwise().mean();
            auto MuEstandarTest= extraer.DesvStandard(EscaladaDataTest);
            auto DevFeaturesTest= MuEstandarTest(0,6);
            Eigen::MatrixXd y_test_hat= (X_test*thetaOutTest*DevFeaturesTest).array()+MuFeaturesTest;
            Eigen::MatrixXd y_t= DataFrame.col(6).bottomRows(268);

            /*A continuacion se determina que tan bueno es nuestro modelo
             * utilizando la metrica R2*/

             float ComprobacionMetricaTest= RL.MetricaR2(y_t, y_test_hat);
             std::cout<<"Rendimiento Test:"<<std::endl;
             std::cout<<ComprobacionMetricaTest<<std::endl;

             extraer.matrixToFile(y_test_hat, "PrediccionT.txt");


    return EXIT_SUCCESS;
}
