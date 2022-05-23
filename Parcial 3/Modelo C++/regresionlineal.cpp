#include "regresionlineal.h"
#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>
#include <cmath>

/*Se necesita entrenar el modelo, lo que significa minimizar la función de costo
 * De esta forma se puede medir la función de hipotesis
 * Una función de costo es la forma de penalizar al modelo por cometer un error
 * Se implementa un función de tipo flotante que toma como entrada los valores (X,y)
*/


float RegresionLineal::OLS_costo(Eigen::MatrixXd X,
                                 Eigen::MatrixXd y,
                                 Eigen::MatrixXd Theta){
    Eigen::MatrixXd Diferencia = pow((X*Theta - y).array(),2);
    return ((Diferencia.sum())/(2*X.rows()));
}


/* Se provee aa programa una función para dar al algoritmo un valor inicial para theta
 * el cual cambiara iterativamente hasta que converga al valor minimo de la
 * función de costo. Basicamente describe el Gradiente Descendiente: La ide es calcular
 * el gradiente para la función de costo, dado por la derivada parcial de la función
 * La función debe tener un Alfa que representa el salto del gradiente.
 * Las entradas para la función son X, y, theta, Alfa y e lnúmero de iteraciones
 */

std::tuple<Eigen::VectorXd, std::vector<float>> RegresionLineal::Gradiente(Eigen::MatrixXd X,
                                                                           Eigen::MatrixXd y,
                                                                           Eigen::VectorXd Theta,
                                                                           float alfa,
                                                                           int iterator){
    /*Se almacenan parametros de theta*/
    Eigen::MatrixXd temporal = Theta;
    /*Se captura el número de variables independientes*/
    int parametros = Theta.rows();
    /*Se ubica el costo inicial, que se actualiza cada vez con los nuevos pesos(pendientes)*/
    std::vector<float> costo;
    costo.push_back(OLS_costo(X,y,Theta));
    /*Por cada iteracion calculamos la funcion de error de cada variable independiente, para
     *ser alamacenado en la variable temporal(tempTheta) basada en el nuevo valor de theta*/
    for(int i=0; i<iterator; ++i){
        Eigen::MatrixXd error = X*Theta - y;
        for(int j=0; j<parametros; ++j){
            Eigen::MatrixXd X_i = X.col(j);
            Eigen::MatrixXd tempTheta = error.cwiseProduct(X_i);
            temporal(j,0) = Theta(j,0) - ((alfa/X.rows())*tempTheta.sum());
        }
        Theta = temporal;
        costo.push_back(OLS_costo(X,y,Theta));
    }
    /*Se empaqueta la tupla y se retorna*/
    return std::make_tuple(Theta, costo);
}

/*
 * Para determinar que tan bueno es nuestro modelo es necesario recurri a una metrixa de rendimiento.
 * Para ello se escoge el R², el cuál representa que tan bueno es nuestro modelo
*/

float RegresionLineal::MetricaR2(Eigen::MatrixXd y, Eigen::MatrixXd y_had){
    auto Numerador=pow((y-y_had).array(),2).sum();
    auto Denominador=pow(y.array()-y.mean(),2).sum();

    return 1-Numerador/Denominador;
}







