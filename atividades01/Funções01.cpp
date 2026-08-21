#include <iostream>
using namespace std;

int maximo(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }

    return b;
}

int main() {
    int num1, num2;

    cout << "Digite o primeiro numero: ";
    cin >> num1;

    cout << "Digite o segundo numero: ";
    cin >> num2;

    cout << "Maior numero: " << maximo(num1, num2) << endl;

    return 0;
}
