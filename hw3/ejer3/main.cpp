#include "procesador.cpp"


int main(){
    container<double> c1; //vector de doubles
    c1.add(1.3);
    c1.add(2.1);
    c1.add(3.2);
    container<string> c2; //vector de strings
    c2.add("H͟o͟l͟a͟");// subrayado porque mariano dijo que sumaba puntos.
    c2.add("Mundo");
    container<fila> c3; //matriz
    c3.add(vector<int>{1, 2});
    c3.add(vector<int>{3, 4});

    // Crear un objeto de la clase constructorjson y generar el JSON
    constructorjson json;
    json.give_name(c1);
    json.give_name(c2);
    json.give_name(c3);
    cout << json.formatojson();
    ofstream out("json.txt");
    if (!out.is_open()) {
        cerr << "Error abriendo archivo\n";
        return 1;
    }
    json.crearjson(out, json.formatojson());
    out.close();

}