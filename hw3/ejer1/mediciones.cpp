#include <iostream>
#include <memory>
#include <fstream>
using namespace std;


class IMediciones {
    public:
        virtual void serializar(ofstream& out)const=0;
        virtual void deserializar( ifstream& in)=0;
};
// Clase base abstracta
class MedicionBase : virtual public IMediciones {
protected:
    unique_ptr<float> tiempoMedicion;  // # tiempoMedicion: unique_ptr<float>

public:
    // Constructor que inicializa el tiempo
    MedicionBase(float t)
      : tiempoMedicion(std::make_unique<float>(t))
    {}


    // + getTiempo(): float
    float getTiempo() const {
        return *tiempoMedicion;
    }

    // + imprimir(): void {virtual puro}
    virtual void imprimir() const = 0;
    void serializar(ofstream& out) const override {
        out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
    } 

    void deserializar( ifstream& in) override {
        tiempoMedicion = make_unique<float>(); 
        in.read(reinterpret_cast< char*>(tiempoMedicion.get()), sizeof(float));
    }
};

// Clase derivada Presion
class Presion : virtual public MedicionBase {
private:
    float presionEstatica;   // + presionEstatica: float
    float presionDinamica;   // + presionDinamica: float

public:
    // + Presion(p: float, q: float, t: float)
    Presion(float p, float q, float t)
      : MedicionBase(t)
      , presionEstatica(p)
      , presionDinamica(q)
    {}
    // constructor default para poder deserealizar
    Presion() : MedicionBase(0.0f), presionEstatica(0.0f), presionDinamica(0.0f) {}
    // copy constructor para resolver el problema de ownership de unique_ptr
    Presion(Presion& p)
      : MedicionBase(p.getTiempo())
      , presionEstatica(p.presionEstatica)
      , presionDinamica(p.presionDinamica)
    {}


    // Override de imprimir()
    void imprimir() const override {
        std::cout << "Presión estática:  " << presionEstatica  << " Pa\n";
        std::cout << "Presión dinámica:  " << presionDinamica  << " Pa\n";
        std::cout << "Tiempo:            " << getTiempo()      << " s\n";
    }

    void serializar(ofstream& out) const override {
        MedicionBase::serializar(out);
        out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
        out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
    } 

    void deserializar( ifstream& in) override {
        MedicionBase::deserializar(in);
        in.read(reinterpret_cast< char*>(&presionEstatica), sizeof(float));
        in.read(reinterpret_cast< char*>(&presionDinamica), sizeof(float));
    }
};

// Clase derivada Posicion
class Posicion : virtual public MedicionBase {
private:
    float latitud;   // + latitud: float
    float longitud;  // + longitud: float
    float altitud;   // + altitud: float

public:
    // + Posicion(lat: float, lon: float, alt: float, t: float)
    Posicion(float lat, float lon, float alt, float t)
      : MedicionBase(t)
      , latitud(lat)
      , longitud(lon)
      , altitud(alt)
    {}
    // copy constructor para resolver el problema de ownership de unique_ptr
    Posicion(Posicion& p)
      : MedicionBase(p.getTiempo())
      , latitud(p.latitud)
      , longitud(p.longitud)
      , altitud(p.altitud)
    {}
    // constructor default para poder deserealizar
    Posicion () : MedicionBase(0.0f), latitud(0.0f), longitud(0.0f), altitud(0.0f) {};
    
    void imprimir() const override {
        std::cout << "Latitud:  " << latitud   << "°\n";
        std::cout << "Longitud: " << longitud  << "°\n";
        std::cout << "Altitud:  " << altitud   << " m\n";
        std::cout << "Tiempo:   " << getTiempo() << " s\n";
    }
    void serializar(ofstream& out) const override {
        MedicionBase::serializar(out);
        out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
        out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
        out.write(reinterpret_cast<const char*>(&altitud), sizeof(float));
    }
    void deserializar( ifstream& in) override {
        MedicionBase::deserializar(in);
        in.read(reinterpret_cast< char*>(&latitud), sizeof(float));
        in.read(reinterpret_cast< char*>(&longitud), sizeof(float));
        in.read(reinterpret_cast< char*>(&altitud), sizeof(float));
    }
};

// clase relacionada con Posicion y Presion
class SaveFlightData  {
    public:
        Posicion posicion;
        Presion presion;  

        SaveFlightData(Posicion& p, Presion& pr) : posicion(p), presion(pr) {} // crea una copia de los objetos Posicion y Presion con un unique_ptr<float> nuevo en cada uno
        // constructor default para poder deserealizar
        SaveFlightData() : posicion(), presion() {}

        
        void imprimir() {
            cout << "Presión\n";
            presion.imprimir();
            cout << "\nPosición\n";
            posicion.imprimir();
        }
        
        void serializar(ofstream& out) const  {
            posicion.serializar(out);
            presion.serializar(out);
        }
        void deserializar(ifstream& in) {
            posicion.deserializar(in);
            presion.deserializar(in);
        }   

};

