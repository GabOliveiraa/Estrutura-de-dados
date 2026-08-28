#include <iostream>
using namespace std;

int main() {
    int numeros[5];
    int maior;

    for (int i = 0; i < 5; i++) {
        cout << "Digite o " << i + 1 << " numero: ";
        cin >> numeros[i];
    }

    maior = numeros[0];

    for (int i = 1; i < 5; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }

    cout << "O maior numero e: " << maior << endl;

    return 0;
}
