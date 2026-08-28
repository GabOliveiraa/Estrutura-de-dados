// ============================================================
// Exercicio 5 - Verificador de parenteses
// Estrutura de Dados - IFSP Campus Campos do Jordao
// ============================================================

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool verificar(string expressao) {
    stack<char> pilha;

    size_t i = 0;
    while(i < expressao.length()){
        char c = expressao[i];

        if( c == '('){
            pilha.push(c);
        }else if(c == ')'){
            if(pilha.empty()) return false;
            pilha.pop();
        }
        i++;
    }
    return pilha.empty();
}

int main() {

    string correta = "( a + b ) * ( c - d )";
    string incorreta = "( a + b * ( c - d )";

    cout << correta << " -> " << (verificar(correta) ? "correto" : "incorreto") << endl;
    cout << incorreta << " -> " << (verificar(incorreta) ? "correto" : "incorreto") << endl;

    return 0;
}
