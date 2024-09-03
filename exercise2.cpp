#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double cantidad;
    
    // Solicita al usuario la cantidad de dinero
    cout << "Ingrese una cantidad de dinero: ";
    cin >> cantidad;

    // Convertir a centavos para evitar problemas de precisión
    int totalCentimos = round(cantidad * 100);

    // Denominaciones de billetes y monedas en centavos
    int billetes[] = {20000, 10000, 5000, 2000, 1000};   // 200, 100, 50, 20, 10 soles
    int monedas[] = {500, 200, 100, 50, 20};             // 5, 2, 1 soles, 0.5, 0.2 soles

    int cantidadBilletes[5] = {0};
    int cantidadMonedas[5] = {0};

    // Calcular la cantidad de billetes
    for (int i = 0; i < 5; i++) {
        cantidadBilletes[i] = totalCentimos / billetes[i];
        totalCentimos %= billetes[i];
    }

    // Calcular la cantidad de monedas
    for (int i = 0; i < 5; i++) {
        cantidadMonedas[i] = totalCentimos / monedas[i];
        totalCentimos %= monedas[i];
    }

    // Mostrar el desglose de billetes
    cout << "Billetes= " << endl;
    cout << "200 soles= " << cantidadBilletes[0] << endl;
    cout << "100 soles= " << cantidadBilletes[1] << endl;
    cout << "50 soles= " << cantidadBilletes[2] << endl;
    cout << "20 soles= " << cantidadBilletes[3] << endl;
    cout << "10 soles= " << cantidadBilletes[4] << endl;

    // Mostrar el desglose de monedas
    cout << "Monedas= " << endl;
    cout << "5 soles= " << cantidadMonedas[0] << endl;
    cout << "2 soles= " << cantidadMonedas[1] << endl;
    cout << "1 sol= " << cantidadMonedas[2] << endl;
    cout << "0.50 centimos= " << cantidadMonedas[3] << endl;
    cout << "0.20 centimos= " << cantidadMonedas[4] << endl;

    return 0;
}