#include <iostream>
using namespace std;

int main() {
    float nota;
    int maior = 0;

    for (int i = 1; i <= 5; i++) {
        cout << "Digite a " << i << "a nota: ";
        cin >> nota;

        if (nota > 7) {
            maior++;
        }
    }

    cout << "Quantidade de notas maiores que 7: " << maior << endl;

    return 0;
}
