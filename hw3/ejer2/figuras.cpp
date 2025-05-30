#include <iostream>

#pragma once

class Punto {
private:
    double x;
    double y;
public:
    // Constructor por defecto y con parámetros
    Punto(double xVal = 0.0, double yVal = 0.0)
        : x(xVal), y(yVal)
    {}

    // Getters
    double getX() const { return x; }
    double getY() const { return y; }

    // Setters
    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }
};


class Circulo {
private:
    Punto centro;
    double radio;
public:
    // Constructor que recibe coordenadas y radio, usando el constructor de Punto
    Circulo(double xCentro, double yCentro, double r)
        : centro(Punto(xCentro, yCentro)), radio(r)
    {}

    // Getters
    Punto  getCentro() const { return centro; }
    double getRadio()  const { return radio; }

    // Setters
    void setCentro(double xCentro, double yCentro)      { centro       = Punto(xCentro, yCentro);     }
    void setRadio(double r)         { radio  = r; }
};


class Elipse {
private:
    Punto centro;
    double a;
    double b;
public:
    // Constructor que recibe coordenadas y semiejes, usando el constructor de Punto
    Elipse(double xCentro, double yCentro, double mayor, double menor)
        : centro(Punto(xCentro, yCentro)), a(mayor), b(menor)
    {if (b>a){
        double temp = a;
        a = b;
        b = temp;
        } 
    }

    // Getters
    Punto  getCentro()       const { return centro; }
    double getSemiEjeMayor() const { return a; }
    double getSemiEjeMenor() const { return b; }

    // Setters
    void setCentro(double xCentro, double yCentro)      { centro       = Punto(xCentro, yCentro);     }
    void setSemiEjeMayor(double mayor)  { a = mayor; }
    void setSemiEjeMenor(double menor)  { b = menor; }
};


class Rectangulo {
private:
    Punto verticeInferiorIzquierdo;
    double ancho;
    double largo;
public:
    // Constructor que recibe coordenadas, ancho y largo, usando el constructor de Punto
    Rectangulo(double xVi, double yVi, double a, double l)
        : verticeInferiorIzquierdo(Punto(xVi, yVi)), ancho(a), largo(l)
    {}

    // Getters
    Punto  getVerticeInferiorIzquierdo() const { return verticeInferiorIzquierdo; }
    double getAncho()                        const { return ancho;                         }
    double getLargo()                        const { return largo;                         }

    // Setters
    void setVerticeInferiorIzquierdo(double xVi, double yVi) { verticeInferiorIzquierdo = Punto(xVi, yVi); }
    void setAncho(double a)                            { ancho                    = a;  }
    void setLargo(double l)                            { largo                    = l;  }
};
