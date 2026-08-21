// ============================================================
// Exercicio 1 - Criar o primeiro no
// Estrutura de Dados - IFSP Campus Campos do Jordao
// ============================================================
//
// Objetivo: declarar a struct No e criar um no com o valor 10.
//
// Saida esperada:
// 10
//
// Siga os passos comentados na ordem em que aparecem.
// Compile com:  g++ exercicio1_no.cpp -o exercicio1 && ./exercicio1
// ============================================================

#include <iostream>
using namespace std;

// ------------------------------------------------------------
// PASSO 1
// Declare a struct No.
// ------------------------------------------------------------
struct No {
    int valor;
    No* proximo;
};

int main() {

    // --------------------------------------------------------
    // PASSO 2
    // Crie uma variavel do tipo No chamada primeiro.
    // --------------------------------------------------------
    No primeiro;

    // --------------------------------------------------------
    // PASSO 3
    // Coloque o valor 10 no campo valor do no primeiro.
    // --------------------------------------------------------
    primeiro.valor = 10;

    // --------------------------------------------------------
    // PASSO 4
    // Coloque nullptr no campo proximo.
    // --------------------------------------------------------
    primeiro.proximo = nullptr;

    // --------------------------------------------------------
    // PASSO 5
    // Imprima o valor guardado no no primeiro, usando cout.
    // --------------------------------------------------------
    cout << primeiro.valor << endl; // Ajustado para imprimir exatamente "10"

    return 0;
}
