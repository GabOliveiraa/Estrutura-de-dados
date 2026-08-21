#include <iostream>
using namespace std;

int main() {
    float numero;
    float soma = 0;

    cout << "Digite um numero ou 0 para encerrar: "; cin >> numero;
    cin.ignore(80,'\n');

    while (numero != 0) {
        soma += numero;

        cout << "Digite outro numero ou 0 para encerrar: ";
        cin >> numero;
    }

    cout << "Soma dos numeros: " << soma << endl;

    return 0;
}
