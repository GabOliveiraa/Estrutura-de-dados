// ============================================================
// Exercicio 3 - Lista duplamente encadeada
// Estrutura de Dados - IFSP Campus Campos do Jordao
// ============================================================
//
// Objetivo: acrescentar o campo anterior ao no, ligar os tres
// nos nos dois sentidos e percorrer de tras para frente.
//
// Saida esperada:
// 30 20 10
//
// Compile com:  g++ exercicio3_duplamente.cpp -o exercicio3 && ./exercicio3
// ============================================================

#include <iostream>
using namespace std;

// ------------------------------------------------------------
// PASSO 1
// A struct abaixo ainda e a da lista simples.
// Acrescente um campo chamado anterior, do mesmo tipo do campo
// proximo, para que cada no saiba tambem quem vem antes dele.
// ------------------------------------------------------------

struct No {
    int valor;
    No* proximo;
    No* anterior; // Adicionado: ponteiro para o nó anterior
};

int main() {

    // --------------------------------------------------------
    // PASSO 2
    // Crie os tres nos com new, guardando os valores 10, 20 e 30
    // em ponteiros chamados primeiro, segundo e terceiro.
    // --------------------------------------------------------

    // Criação do primeiro nó
    No* primeiro = new No;
    primeiro->valor = 10;

    // Criação do segundo nó
    No* segundo = new No;
    segundo->valor = 20;

    // Criação do terceiro nó
    No* terceiro = new No;
    terceiro->valor = 30;


    // --------------------------------------------------------
    // PASSO 3
    // Ligue os nos nos DOIS sentidos.
    // --------------------------------------------------------

    // Configuração do primeiro nó
    primeiro->anterior = nullptr;
    primeiro->proximo = segundo;

    // Configuração do segundo nó
    segundo->anterior = primeiro;
    segundo->proximo = terceiro;

    // Configuração do terceiro nó
    terceiro->anterior = segundo;
    terceiro->proximo = nullptr;


    // --------------------------------------------------------
    // PASSO 4
    // Percorra a lista de tras para frente.
    // --------------------------------------------------------

    // Inicializa o ponteiro de navegação no último elemento
    No* atual = terceiro;

    // Percorre voltando até passar do primeiro nó (onde anterior é nullptr)
    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->anterior;
    }

    cout << endl;

    delete primeiro;
    delete segundo;
    delete terceiro;

    return 0;
}
