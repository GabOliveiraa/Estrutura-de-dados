#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt;
    int quant = 0;

    cout << "Digite uma frase: ";
    getline(cin, txt);

    for (int i = 0; i < txt.length(); i++) {
        if (txt[i] == 'a' || txt[i] == 'A') {
            quant++;
        }
    }

    cout << "A letra 'a' aparece " << quant << " vezes." << endl;

    return 0;
}
