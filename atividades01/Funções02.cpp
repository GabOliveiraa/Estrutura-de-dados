#include <iostream>
using namespace std;

void trocar(int &a, int &b) {
    int x = a;
    a = b;
    b = x;
}

int main() {
    int num1, num2;

    cout << "Digite o primeiro numero: ";
    cin >> num1;

    cout << "Digite o segundo numero: ";
    cin >> num2;

    cout << endl;

    cout << "Antes: " << num1 << " e " << num2 << endl;

    trocar(num1, num2);

    cout << "Depois: " << num1 << " e " << num2 << endl;

    return 0;
}
