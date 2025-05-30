#include "mediciones.cpp"



int main() {
    // datos originales de enunciado
    Posicion pos1(-34.6f, -58.4f, 950.0f, 5.3f);
    Presion  pr1 (101.3f,  5.8f,   6.1f);
    SaveFlightData vuelo1(pos1, pr1);

    cout << "Datos ORIGINALES:\n";
    vuelo1.imprimir();

    //  Serializacion de la info a binario 
    {
        ofstream out("vuelo.bin", ios::binary);
        if (!out.is_open()) {
            cerr << "Error abriendo archivo\n";
            return 1;
        }
        vuelo1.serializar(out);
    }

    // creacion un nuevo objeto con constructor default y leemos de vuelo.bin 
    SaveFlightData vuelo2;
    {
        ifstream in("vuelo.bin", ios::binary);
        if (!in.is_open()) {
            cerr << "Error abriendo archivo\n";
            return 1;
        }
        vuelo2.deserializar(in);
    }

    // se muestran los datos deserializados 
    cout << "\nDatos DESERIALIZADOS:\n";
    vuelo2.imprimir();

    return 0;
}