#include <iostream>
using namespace std;

bool ehPar(int n) {
    return n % 2 == 0;
}

int main() {
    int x;

    cout << "Digite um numero: ";
    cin >> x;

    if (ehPar(x)) {
        cout << "O numero e par." << endl;
    } else {
        cout << "O numero e impar." << endl;
    }

    return 0;
}
