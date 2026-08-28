#include <iostream>
using namespace std;

int main() {
    int numeros[5];

    for (int i = 0; i < 5; i++) {
        cout << "Digite o " << i + 1 << " numero: ";
        cin >> numeros[i];
    }

    cout << "--------------------------" << endl;

    for (int i = 4; i >= 0; i--) {
        cout << numeros[i] << " ";
    }

    return 0;
}
