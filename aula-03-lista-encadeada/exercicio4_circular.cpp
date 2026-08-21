// ============================================================
// Exercicio 4 - Lista circular
// Estrutura de Dados - IFSP Campus Campos do Jordao
// ============================================================
//
// Objetivo: fechar o ciclo, fazendo o ultimo no apontar de volta
// para o primeiro, e percorrer dando exatamente uma volta.
//
// Saida esperada:
// 10 20 30
//
// Compile com:  g++ exercicio4_circular.cpp -o exercicio4 && ./exercicio4
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
    // Crie os tres nos com new, guardando os valores 10, 20 e 30
    // em ponteiros chamados primeiro, segundo e terceiro.
    // --------------------------------------------------------

    // Criação dos três nós dinamicamente
    No* primeiro = new No;
    primeiro->valor = 10;

    No* segundo = new No;
    segundo->valor = 20;

    No* terceiro = new No;
    terceiro->valor = 30;


    // --------------------------------------------------------
    // PASSO 2
    // Ligue o primeiro ao segundo e o segundo ao terceiro,
    // como voce ja fez no exercicio 2.
    // --------------------------------------------------------

    primeiro->proximo = segundo;
    segundo->proximo = terceiro;


    // --------------------------------------------------------
    // PASSO 3
    // Aqui esta a diferenca da lista circular.
    // Em vez de receber nullptr, o campo proximo do terceiro no
    // deve guardar o endereco do primeiro no.
    // A lista passa a nao ter fim.
    // --------------------------------------------------------

    terceiro->proximo = primeiro;


    // --------------------------------------------------------
    // PASSO 4
    // Percorra a lista dando exatamente uma volta completa.
    // --------------------------------------------------------

    No* atual = primeiro;
    do {
        cout << atual->valor << " ";
        atual = atual->proximo;
    } while (atual != primeiro);

    cout << endl;

    delete primeiro;
    delete segundo;
    delete terceiro;

    return 0;
}
