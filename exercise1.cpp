#include <iostream>
#include <string>

using namespace std;

// Funciones que convierten los numeros
string unidades(int num); // Convierte numeros de 1 a 9 a palabras
string decenas(int num); // Convierte numeros de 10 a 99 a palabras, incluyendo los números especiales del 11 al 19
string centenas(int num); // Convierte numeros de 100 a 999 a palabras
string miles(int num); //  Maneja numeros de 1000 a 999999

string unidades(int num) {
    string palabras[] = { "", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };
    return palabras[num];
}

string decenas(int num) { // Convierte numeros entre 10 y 99 en su representación textual
    string palabras[] = { "", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" }; // Arreglo con palabras para las decenas "diez", "veinte", etc.
    
    if (num < 10) return unidades(num); // Si el número es menor a 10, lo maneja como una unidad llamando a la función unidades(num)

    if (num >= 10 && num < 20) { // Los numeros entre 10 y 19, se manejan por separado usando un arreglo especiales[] con las palabras correspondientes
        string especiales[] = { "diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve" };
        return especiales[num - 10];
    }
    
    int unidad = num % 10; // Calcula el valor de la unidad
    if (unidad == 0) return palabras[num / 10]; // Si la unidad es 0, devuelve solo la palabra correspondiente a la decena
    return palabras[num / 10] + " y " + unidades(unidad); // Para otros casos, se combinan la decena y la unidad, por ejemplo, "treinta y cinco"
}

string centenas(int num) {
    string palabras[] = { "", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos" };
    
    if (num == 100) return "cien";
    
    int decena = num % 100;
    if (num >= 100) return palabras[num / 100] + " " + decenas(decena);
    return decenas(num);
}

string miles(int num) {
    if (num < 1000) return centenas(num);
    
    int millar = num / 1000;
    int resto = num % 1000;
    
    string milesTexto = (millar == 1) ? "mil" : centenas(millar) + " mil";
    
    if (resto == 0) return milesTexto;
    return milesTexto + " " + centenas(resto);
}

int main() {
    int numero;
    
    cout << "Introduce un numero (1 - 999999): ";
    cin >> numero;

    if (numero < 1 || numero > 999999) {
        cout << "Número fuera del rango permitido." << endl;
    } else {
        cout << numero << " = " << miles(numero) << endl;
    }

    return 0;
}