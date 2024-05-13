#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

double calcularPromedio(vector<double>& numeros) {
    double suma = 0.0;
    for (int i = 0; i < numeros.size(); ++i) {
        suma += numeros[i];
    }
    return suma / numeros.size();
}

double calcularMediana(vector<double>& numeros) {
    sort(numeros.begin(), numeros.end());
    int tamano = numeros.size();
    if (tamano % 2 == 0) {
        return (numeros[tamano / 2 - 1] + numeros[tamano / 2]) / 2.0;
    } else {
        return numeros[tamano / 2];
    }
}

double calcularModa(vector<double>& numeros) {
    vector<int> frecuencia(100000, 0); 
    for (int i = 0; i < numeros.size(); ++i) {
        frecuencia[static_cast<int>(numeros[i])]++;
    }
    int max_frecuencia = *max_element(frecuencia.begin(), frecuencia.end());
    double moda = find(frecuencia.begin(), frecuencia.end(), max_frecuencia) - frecuencia.begin();
    return moda;
}

int main() {
    string archivoEntrada = "entrada.txt";
    string archivoSalida = "salida.txt";

    ifstream entrada(archivoEntrada.c_str());
    ofstream salida(archivoSalida.c_str());

    if (!entrada.is_open()) {
        cout << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    vector<double> numeros;
    double numero;
    while (entrada >> numero) {
        numeros.push_back(numero);
    }
    entrada.close();

    if (numeros.empty()) {
        cout << "El archivo de entrada está vacío." << endl;
        return 1;
    }

    double promedio = calcularPromedio(numeros);
    double mediana = calcularMediana(numeros);
    double moda = calcularModa(numeros);

    salida << "El promedio es: " << promedio << endl;
    salida << "La mediana es: " << mediana << endl;
    salida << "La moda es: " << moda << endl;
    salida.close();

    cout << "Se ha calculado el promedio, la mediana y la moda, y se han guardado en el archivo de salida." << endl;

    return 0;
}