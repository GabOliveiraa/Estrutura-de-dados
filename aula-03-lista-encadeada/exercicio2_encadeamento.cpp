// ============================================================
// Exercicio 2 - Ligar os nos e percorrer a lista
// Estrutura de Dados - IFSP Campus Campos do Jordao
// ============================================================
//
// Objetivo: criar tres nos, liga-los em sequencia e percorrer
// a lista do primeiro ate o ultimo, imprimindo os valores.
//
// Saida esperada:
// 10 20 30
//
// Compile com:  g++ exercicio2_encadeamento.cpp -o exercicio2 && ./exercicio2
// ============================================================

#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;
};

int main() {

    // --------------------------------------------------------
    // PASSO 1
    // Crie o primeiro no usando new e guarde o endereco dele
    // em um ponteiro chamado primeiro.
    // --------------------------------------------------------

    No* primeiro = new No;
    primeiro->valor = 10;


    // --------------------------------------------------------
    // PASSO 2
    // Faca o mesmo para criar o segundo no, com o valor 20,
    // e o terceiro no, com o valor 30.
    // --------------------------------------------------------

    No* segundo = new No;
    segundo->valor = 20;

    No* terceiro = new No;
    terceiro->valor = 30;


    // --------------------------------------------------------
    // PASSO 3
    // Agora ligue os nos, formando a corrente.
    // --------------------------------------------------------

    primeiro->proximo = segundo;
    segundo->proximo = terceiro;
    terceiro->proximo = nullptr;


    // --------------------------------------------------------
    // PASSO 4
    // Crie um ponteiro chamado atual e faca ele apontar para
    // o primeiro no. Esse ponteiro vai caminhar pela lista.
    // --------------------------------------------------------

    No* atual = primeiro;


    // --------------------------------------------------------
    // PASSO 5
    // Escreva um while que repete enquanto atual for diferente
    // de nullptr.
    // --------------------------------------------------------

    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    
    cout << endl;


    delete primeiro;
    delete segundo;
    delete terceiro;

    return 0;
}
