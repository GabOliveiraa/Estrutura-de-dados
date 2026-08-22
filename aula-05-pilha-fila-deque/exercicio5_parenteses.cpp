// ============================================================
// Exercicio 5 - Verificador de parenteses
// Estrutura de Dados - IFSP Campus Campos do Jordao
// ============================================================
//
// Um compilador precisa saber se os parenteses de uma expressao
// estao corretamente fechados.
//
// O ultimo parentese aberto e o primeiro que precisa ser
// fechado. Essa e exatamente a regra da pilha.
//
// Saida esperada:
// ( a + b ) * ( c - d ) -> correto
// ( a + b * ( c - d ) -> incorreto
//
// ============================================================

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// ------------------------------------------------------------
// PASSO 1
// Complete a funcao verificar.
//
// Ela recebe uma string e devolve true se os parenteses
// estiverem corretamente fechados.
//
// Dentro dela:
//   1. declare uma stack<char> chamada pilha
//   2. percorra a string caractere a caractere, com
//      for (char c : expressao) { ... }
//   3. se o caractere for abre parenteses, empilhe ele
//   4. se for fecha parenteses:
//        se a pilha estiver vazia, devolva false, porque
//        apareceu um fechamento sem abertura correspondente
//        caso contrario, desempilhe
//   5. no fim, devolva true apenas se a pilha estiver vazia.
//      Se sobrou algo, faltou fechar.
// ------------------------------------------------------------

bool verificar(string expressao) {
    stack<char> pilha;

    for (char c : expressao) {
        if(c == '('){
            pilha.push(c);
        } else if(c == ')'){
            if(pilha.empty()){
                return false;
            } else {
                pilha.pop();
            }
        }
    }
    return pilha.empty();
}

int main() {

    string correta = "( a + b ) * ( c - d )";
    string incorreta = "( a + b * ( c - d )";

    // --------------------------------------------------------
    // PASSO 2
    // Chame verificar para cada expressao e imprima o resultado
    // no formato da saida esperada.
    //
    // Dica: use o operador ternario para escolher entre as
    // palavras correto e incorreto.
    // --------------------------------------------------------

    // escreva aqui
    cout << correta << " -> " << (verificar(correta) ? "correto" : "incorreto") << endl;
    cout << incorreta << " -> " << (verificar(incorreta) ? "correto" : "incorreto") << endl;

    return 0;
}
