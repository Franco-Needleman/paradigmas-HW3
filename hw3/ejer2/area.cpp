#include <iostream>
#include <string>
#include "figuras.cpp"

template<typename T>
class ProcesarFigura {
public:
    std::string area(const T& figura) {
        return "No es posible calcular el area"; // Valor por defecto
    }
};

template<>
class ProcesarFigura<Circulo> {
public:
    double area(const Circulo& c) {
        return 3.14159 * c.getRadio() * c.getRadio();
    }
};

template<>
class ProcesarFigura<Elipse> { 
    public:
    double area(const Elipse& e) {
        return 3.14159 *  e.getSemiEjeMayor() * e.getSemiEjeMenor();
    }
};

template<>
class ProcesarFigura<Rectangulo> {
    public:
    double area(const Rectangulo& r) {
        return r.getAncho() * r.getLargo();
    }
};

