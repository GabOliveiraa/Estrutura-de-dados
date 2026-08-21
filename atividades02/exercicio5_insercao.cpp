// ============================================================
// Exercicio 5 - Insercao no inicio da lista
// Estrutura de Dados - IFSP Campus Campos do Jordao
// ============================================================
//
// Objetivo: adicionar um novo no no inicio de uma lista
// encadeada.
//
// Lista inicial:
//
// 10 -> 20 -> 30 -> nullptr
//
// Depois da insercao:
//
// 5 -> 10 -> 20 -> 30 -> nullptr
//
// Saida esperada:
//
// Lista antes da insercao:
// 10 20 30
//
// Lista depois da insercao:
// 5 10 20 30
//
// Compile com:
// g++ exercicio5_insercao.cpp -o exercicio5 && ./exercicio5
// ============================================================

#include <iostream>
using namespace std;

struct No
{
    int valor;
    No *proximo;
};

int main()
{

    // --------------------------------------------------------
    // PASSO 1
    // Crie tres nos com new, contendo os valores:
    //
    // 10, 20 e 30
    //
    // Guarde os enderecos em ponteiros chamados:
    //
    // primeiro
    // segundo
    // terceiro
    // --------------------------------------------------------

    // escreva aqui
    No *primeiro = new No;
    primeiro->valor = 10;

    No *segundo = new No;
    segundo->valor = 20;

    No *terceiro = new No;
    terceiro->valor = 30;

    // --------------------------------------------------------
    // PASSO 2
    // Ligue os tres nos formando a lista:
    //
    // 10 -> 20 -> 30 -> nullptr
    //
    // O primeiro deve apontar para o segundo.
    // O segundo deve apontar para o terceiro.
    // O terceiro deve apontar para nullptr.
    // --------------------------------------------------------

    // escreva aqui
    primeiro->proximo = segundo;
    segundo->proximo = terceiro;
    terceiro->proximo = nullptr;

    // --------------------------------------------------------
    // PASSO 3
    // Mostre a lista antes da insercao.
    //
    // Use um ponteiro chamado atual para percorrer a lista
    // comecando pelo primeiro no.
    //
    // Continue enquanto atual for diferente de nullptr.
    //
    // Saida:
    //
    // 10 20 30
    // --------------------------------------------------------

    // escreva aqui
    No *atual = primeiro;

    cout << "Lista inicial: ";
    while (atual != nullptr)
    {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << endl;

    // --------------------------------------------------------
    // PASSO 4
    // Crie um novo no com new contendo o valor 5.
    //
    // Guarde o endereco dele em um ponteiro chamado novo.
    //
    // Por enquanto ele ainda nao faz parte da lista.
    // --------------------------------------------------------

    // escreva aqui
    No *novo = new No;
    novo->valor = 5;

    // --------------------------------------------------------
    // PASSO 5
    // Insira o novo no no inicio da lista.
    //
    // Antes:
    //
    // primeiro
    //    |
    //    v
    //   10 -> 20 -> 30 -> nullptr
    //
    // Depois:
    //
    // primeiro
    //    |
    //    v
    //    5 -> 10 -> 20 -> 30 -> nullptr
    //
    // Pense em duas coisas:
    //
    // 1. Para quem o campo proximo do novo no deve apontar?
    //
    // 2. Depois disso, para qual no o ponteiro primeiro
    //    deve passar a apontar?
    //
    // A ordem dessas operacoes importa.
    // --------------------------------------------------------

    // escreva aqui
    novo->proximo = primeiro;
    primeiro = novo;

    // --------------------------------------------------------
    // PASSO 6
    // Percorra novamente a lista e mostre os valores depois
    // da insercao.
    //
    // Saida esperada:
    //
    // 5 10 20 30
    // --------------------------------------------------------

    // escreva aqui
    cout << "Depois de adicinonar um valor novo: ";

    atual = primeiro;

    while (atual != nullptr)
    {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << endl;

    return 0;
}