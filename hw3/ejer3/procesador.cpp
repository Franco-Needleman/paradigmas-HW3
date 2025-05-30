#include <iostream>
#include <fstream>
#include <concepts>
#include <string>
#include <vector>
#include <type_traits>
#include <stdexcept>
using namespace std;
using fila = vector<int>;


template<typename T>
concept esDouble = is_same_v<T, double>;

template<typename T>
concept esString = is_same_v<T, string>;


template<typename T>
concept esFila = is_same_v<T, fila>;

template<typename T>
class container {
    private:
        vector<T> info;
    public:
        void add(T value) {
            info.push_back(value);
        }

        vector<T> get_info(){
            return info;
        }

        string toString() {
            string result;
            result = "[";
            for (const auto& item : info) {
                if constexpr (esDouble<T>) {
                    result += to_string(item) ;
                    if (item != info.back()) {
                        result += ", ";
                    }
                } else if constexpr (esString<T>) {
                    result += "\""+item+"\"" ;
                    if (item != info.back()) {
                        result += ", ";
                    }
                } else if constexpr (esFila<T>) {
                    result += "\n           [";
                    for (const auto& elem : item) {
                        result += to_string(elem) ;
                        if (elem != item.back()) {
                        result += ", ";
                    }
                    }
                    result+= "]";
                    if (item != info.back()) {
                        result += ", ";
                    }
                    else {
                    result += "\n           ";
                    }
                }
            }
            result += "]";
            return result;
        }
};




class constructorjson{

    vector<pair<string, string>> datos;
    public: 
    template<typename T>
    void give_name(container<T>& contenedor){
        
        if constexpr (is_same_v<decltype(contenedor.get_info()),vector<double>>) {
            return datos.push_back(pair("\"vec_doubles\"",contenedor.toString()));
        } else if constexpr (is_same_v<decltype(contenedor.get_info()),vector<string>>) {
            return datos.push_back(pair("  \"palabras\"",contenedor.toString()));
        } else if constexpr (is_same_v<decltype(contenedor.get_info()),vector<fila>>) {
            return datos.push_back(pair("  \"listas\"",contenedor.toString()));
        }    
        else {
            throw invalid_argument("Tipo no soportado");
        }
    }

    
    string formatojson(){
        string json = "{ ";
        for (const auto& dato : datos) {
            json +=  dato.first + " : " + dato.second + ", \n";
        }

        
        json += "}\n";
        return json;
    }

    void crearjson(ofstream& out, const string& json) {
        out << json;
    }

};





