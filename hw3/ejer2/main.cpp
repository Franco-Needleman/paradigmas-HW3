#include "area.cpp"

int main() {
    // Crear un círculo con centro en (1, 2) y radio 3
    Circulo c(1, 2, 3);
    // Crear una elipse con centro en (4, 5), semieje mayor 6 y semieje menor 7
    Elipse e(4, 5, 6, 7);
    // Crear un rectángulo con ancho 8 y largo 9
    Rectangulo r(0,0,8, 9);

    // Calcular el área de cada figura
    ProcesarFigura<Circulo> areaCirculo;
    ProcesarFigura<Elipse> areaElipse;
    ProcesarFigura<Rectangulo> areaRectangulo;

    std::cout << "Area del circulo: " << areaCirculo.area(c) << std::endl;
    std::cout << "Area de la elipse: " << areaElipse.area(e) << std::endl;
    std::cout << "Area del rectangulo: " << areaRectangulo.area(r) << std::endl;

    return 0;
}