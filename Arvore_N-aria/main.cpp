#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct No
{
    string nome;
    bool ehPasta;
    long long tamanho;
    No* pai;
    vector<unique_ptr<No>> filhos;

    No(string nome, bool ehPasta = true, long long tamanho = 0, No* pai = nullptr)
        : nome(nome), ehPasta(ehPasta), tamanho(tamanho), pai(pai)
    {
    }
};

class Sistema
{
private:
    unique_ptr<No> raiz;
    No* atual;

    vector<string> dividir(const string& caminho) const
    {
        vector<string> partes;
        string parte;
        istringstream entrada(caminho);

        while (getline(entrada, parte, '/'))
        {
            if (!parte.empty())
            {
                partes.push_back(parte);
            }
        }
        return partes;
    }

    No* filhoDe(No* pai, const string& nome) const
    {
        if (!pai || !pai->ehPasta)
        {
            return nullptr;
        }
        for (const auto& filho : pai->filhos)
        {
            if (filho->nome == nome)
            {
                return filho.get();
            }
        }
        return nullptr;
    }

    No* buscarCaminho(const string& caminho) const
    {
        if (caminho.empty())
        {
            return nullptr;
        }
        No* no = caminho[0] == '/' ? raiz.get() : atual;
        for (const string& parte : dividir(caminho))
        {
            if (parte == ".")
            {
                continue;
            }
            if (parte == "..")
            {
                no = no->pai ? no->pai : no;
            }
            else
            {
                no = filhoDe(no, parte);
                if (!no)
                {
                    return nullptr;
                }
            }
        }
        return no;
    }

    string caminhoDe(const No* no) const
    {
        if (no == raiz.get())
        {
            return "/";
        }
        vector<string> partes;
        while (no && no != raiz.get())
        {
            partes.push_back(no->nome);
            no = no->pai;
        }
        string resultado;
        for (auto it = partes.rbegin(); it != partes.rend(); ++it)
        {
            resultado += "/" + *it;
        }
        return resultado;
    }

    bool separarPai(const string& caminho, No*& pai, string& nome) const
    {
        if (caminho.empty() || caminho.back() == '/')
        {
            return false;
        }
        size_t barra = caminho.find_last_of('/');
        string caminhoPai;
        if (barra == string::npos)
        {
            caminhoPai = ".";
            nome = caminho;
        }
        else
        {
            caminhoPai = barra == 0 ? "/" : caminho.substr(0, barra);
            nome = caminho.substr(barra + 1);
        }
        pai = buscarCaminho(caminhoPai);
        return pai && pai->ehPasta && !nome.empty() && nome != "." && nome != "..";
    }

    No* criar(No* pai, const string& nome, bool pasta, long long tamanho = 0)
    {
        if (!pai || !pai->ehPasta || nome.empty() || nome == "." || nome == ".." || nome.find('/') != string::npos || filhoDe(pai, nome))
        {
            return nullptr;
        }
        auto novo = make_unique<No>(nome, pasta, tamanho, pai);
        No* resultado = novo.get();
        pai->filhos.push_back(move(novo));
        return resultado;
    }

    void mostrarArvore(const No* no, const string& prefixo = "", bool ultimo = true, bool raizDaExibicao = true) const
    {
        if (!raizDaExibicao)
        {
            cout << prefixo << (ultimo ? "`-- " : "|-- ");
        }
        cout << no->nome << (no->ehPasta && no != raiz.get() ? "/" : "") << "\n";
        string novoPrefixo = prefixo + (raizDaExibicao ? "" : (ultimo ? "    " : "|   "));
        for (size_t i = 0; i < no->filhos.size(); ++i)
        {
            mostrarArvore(no->filhos[i].get(), novoPrefixo, i + 1 == no->filhos.size(), false);
        }
    }

    struct Estatisticas
    {
        int nos = 1;
        int folhas = 0;
        int altura = 0;
        int grauMaximo = 0;
    };

    Estatisticas estatisticas(const No* no) const
    {
        Estatisticas e;
        e.folhas = no->filhos.empty() ? 1 : 0;
        e.grauMaximo = static_cast<int>(no->filhos.size());
        for (const auto& filho : no->filhos)
        {
            Estatisticas f = estatisticas(filho.get());
            e.nos += f.nos;
            e.folhas += f.folhas;
            e.altura = max(e.altura, f.altura + 1);
            e.grauMaximo = max(e.grauMaximo, f.grauMaximo);
        }
        return e;
    }

    long long tamanhoTotal(const No* no) const
    {
        if (!no->ehPasta)
        {
            return no->tamanho;
        }
        long long total = 0;
        for (const auto& filho : no->filhos)
        {
            total += tamanhoTotal(filho.get());
        }
        return total;
    }

    void localizar(const No* no, const string& termo, int& quantidade) const
    {
        if (no->nome.find(termo) != string::npos)
        {
            cout << caminhoDe(no) << "\n";
            ++quantidade;
        }
        for (const auto& filho : no->filhos)
        {
            localizar(filho.get(), termo, quantidade);
        }
    }

    bool eDescendenteOuIgual(const No* no, const No* possivelAncestral) const
    {
        for (const No* p = no; p; p = p->pai)
        {
            if (p == possivelAncestral)
            {
                return true;
            }
        }
        return false;
    }

    void salvarNo(ofstream& saida, const No* no, int nivel) const
    {
        // Formato interno simples: nivel, tipo, tamanho e nome (separados por tab).
        saida << nivel << '\t' << (no->ehPasta ? 'P' : 'A') << '\t' << no->tamanho << '\t' << no->nome << '\n';
        for (const auto& filho : no->filhos)
        {
            salvarNo(saida, filho.get(), nivel + 1);
        }
    }

    bool carregarArquivo(const string& arquivo)
    {
        ifstream entrada(arquivo);
        if (!entrada)
        {
            return false;
        }
        unique_ptr<No> novaRaiz;
        vector<No*> caminho;
        string linha;
        int linhas = 0;
        while (getline(entrada, linha))
        {
            if (linha.empty())
            {
                return false;
            }
            istringstream parser(linha);
            int nivel;
            char tipo;
            long long tamanho;
            string nome;
            if (!(parser >> nivel >> tipo >> tamanho) || parser.get() != '\t' || !getline(parser, nome))
            {
                return false;
            }
            if (nivel < 0 || nivel > 1000 || (tipo != 'P' && tipo != 'A') || tamanho < 0 || nome.empty() || (nome.find('/') != string::npos && nivel != 0) || nome.find('\t') != string::npos)
            {
                return false;
            }
            if (linhas == 0)
            {
                if (nivel != 0 || tipo != 'P' || nome != "/")
                {
                    return false;
                }
                novaRaiz = make_unique<No>(nome, true);
                caminho = {novaRaiz.get()};
            }
            else
            {
                if (nivel == 0 || static_cast<size_t>(nivel) > caminho.size())
                {
                    return false;
                }
                No* pai = caminho[nivel - 1];
                if (!pai->ehPasta)
                {
                    return false;
                }
                for (const auto& filho : pai->filhos)
                {
                    if (filho->nome == nome)
                    {
                        return false;
                    }
                }
                auto novo = make_unique<No>(nome, tipo == 'P', tamanho, pai);
                No* p = novo.get();
                pai->filhos.push_back(move(novo));
                caminho.resize(nivel);
                caminho.push_back(p);
            }
            ++linhas;
        }
        if (!novaRaiz)
        {
            return false;
        }
        raiz = move(novaRaiz);
        atual = raiz.get();
        return true;
    }

public:
    Sistema()
    {
        raiz = make_unique<No>("/");
        atual = raiz.get();
    }

    void demo()
    {
        raiz = make_unique<No>("/");
        atual = raiz.get();
        No* home = criar(raiz.get(), "home", true);
        No* sistema = criar(raiz.get(), "sistema", true);
        No* tmp = criar(raiz.get(), "tmp", true);
        No* ana = criar(home, "ana", true);
        No* bruno = criar(home, "bruno", true);
        criar(ana, "documentos", true);
        No* fotos = criar(ana, "fotos", true);
        criar(fotos, "viagem.jpg", false, 2000);
        No* musicas = criar(bruno, "musicas", true);
        criar(musicas, "rock.mp3", false, 3500);
        criar(musicas, "samba.mp3", false, 3100);
        No* projetos = criar(bruno, "projetos", true);
        No* jogo = criar(projetos, "jogo", true);
        criar(jogo, "jogador.cpp", false, 1200);
        criar(jogo, "jogador.h", false, 420);
        criar(jogo, "main.cpp", false, 1800);
        criar(projetos, "README.md", false, 350);
        criar(sistema, "config", true);
        criar(sistema, "log.txt", false, 800);
        criar(tmp, "cache.tmp", false, 120);
        cout << "Exemplo carregado.\n";
    }

    void executar(const string& linha)
    {
        istringstream entrada(linha);
        string comando, a, b;
        entrada >> comando;
        if (comando.empty())
        {
            return;
        }
        if (comando == "ajuda" || comando == "help")
        {
            cout << "Comandos: demo, tree [caminho], info [caminho], pwd, ls [caminho], cd <caminho>,\n"
                 << "mkdir <caminho>, touch <caminho> <bytes>, rm <caminho>, mv <origem> <pasta-destino>,\n"
                 << "find <nome>, niveis [caminho], du [caminho], salvar [arquivo], carregar [arquivo], sair\n";
        }
        else if (comando == "demo")
        {
            demo();
        }
        else if (comando == "pwd")
        {
            cout << caminhoDe(atual) << "\n";
        }
        else if (comando == "cd")
        {
            entrada >> a;
            No* destino = buscarCaminho(a);
            if (!destino || !destino->ehPasta)
            {
                cout << "Erro: pasta nao encontrada.\n";
            }
            else
            {
                atual = destino;
            }
        }
        else if (comando == "ls")
        {
            entrada >> a;
            No* no = a.empty() ? atual : buscarCaminho(a);
            if (!no || !no->ehPasta)
            {
                cout << "Erro: pasta nao encontrada.\n";
            }
            else
            {
                for (const auto& filho : no->filhos)
                {
                    cout << (filho->ehPasta ? "[PASTA] " : "[ARQUIVO] ") << filho->nome;
                    if (!filho->ehPasta)
                    {
                        cout << " (" << filho->tamanho << " bytes)";
                    }
                    cout << "\n";
                }
            }
        }
        else if (comando == "tree" || comando == "info" || comando == "niveis" || comando == "du")
        {
            entrada >> a;
            No* no = a.empty() ? raiz.get() : buscarCaminho(a);
            if (!no)
            {
                cout << "Erro: caminho nao encontrado.\n";
                return;
            }
            if (comando == "tree")
            {
                mostrarArvore(no);
            }
            else if (comando == "info")
            {
                auto e = estatisticas(no);
                cout << "Nos: " << e.nos << " | Folhas: " << e.folhas << " | Altura: " << e.altura << " | Grau maximo: " << e.grauMaximo << "\n";
            }
            else if (comando == "du")
            {
                cout << tamanhoTotal(no) << " bytes\n";
            }
            else
            {
                queue<pair<No*, int>> fila;
                fila.push({no, 0});
                int nivelAtual = -1;
                while (!fila.empty())
                {
                    auto item = fila.front();
                    fila.pop();
                    if (item.second != nivelAtual)
                    {
                        nivelAtual = item.second;
                        cout << (nivelAtual == 0 ? "" : "\n") << "Nivel " << nivelAtual << ": ";
                    }
                    cout << item.first->nome << (item.first->ehPasta && item.first != raiz.get() ? "/" : "") << " ";
                    for (const auto& filho : item.first->filhos)
                    {
                        fila.push({filho.get(), item.second + 1});
                    }
                }
                cout << "\n";
            }
        }
        else if (comando == "find")
        {
            entrada >> a;
            if (a.empty())
            {
                cout << "Uso: find <nome>\n";
                return;
            }
            int qtd = 0;
            localizar(raiz.get(), a, qtd);
            if (!qtd)
            {
                cout << "Nenhum resultado.\n";
            }
        }
        else if (comando == "mkdir" || comando == "touch")
        {
            entrada >> a;
            long long bytes = 0;
            if (comando == "touch" && (!(entrada >> bytes) || bytes < 0))
            {
                cout << "Uso: touch <caminho> <bytes>=0\n";
                return;
            }
            No* pai = nullptr;
            string nome;
            if (!separarPai(a, pai, nome) || !criar(pai, nome, comando == "mkdir", bytes))
            {
                cout << "Erro: caminho invalido, nome repetido ou pasta pai inexistente.\n";
            }
            else
            {
                cout << "Criado: " << a << "\n";
            }
        }
        else if (comando == "rm")
        {
            entrada >> a;
            No* no = buscarCaminho(a);
            if (!no || no == raiz.get())
            {
                cout << "Erro: nao pode remover esse caminho.\n";
                return;
            }
            if (eDescendenteOuIgual(atual, no))
            {
                atual = no->pai;
            }
            auto& filhos = no->pai->filhos;
            filhos.erase(remove_if(filhos.begin(), filhos.end(), [no](const auto& f) { return f.get() == no; }), filhos.end());
            cout << "Removido.\n";
        }
        else if (comando == "mv")
        {
            entrada >> a >> b;
            No* origem = buscarCaminho(a);
            No* destino = buscarCaminho(b);
            if (!origem || !destino || !destino->ehPasta || origem == raiz.get())
            {
                cout << "Erro: origem ou destino invalido.\n";
                return;
            }
            if (eDescendenteOuIgual(destino, origem))
            {
                cout << "Erro: movimento criaria um ciclo.\n";
                return;
            }
            if (filhoDe(destino, origem->nome))
            {
                cout << "Erro: destino ja tem um item com esse nome.\n";
                return;
            }
            auto& antigos = origem->pai->filhos;
            auto it = find_if(antigos.begin(), antigos.end(), [origem](const auto& f) { return f.get() == origem; });
            unique_ptr<No> movido = move(*it);
            antigos.erase(it);
            movido->pai = destino;
            destino->filhos.push_back(move(movido));
            cout << "Movido.\n";
        }
        else if (comando == "salvar")
        {
            entrada >> a;
            if (a.empty()) a = "arvore.txt";
            ofstream saida(a);
            if (!saida)
            {
                cout << "Erro ao abrir arquivo para salvar.\n";
                return;
            }
            salvarNo(saida, raiz.get(), 0);
            cout << (saida.good() ? "Salvo em " : "Erro ao salvar em ") << a << "\n";
        }
        else if (comando == "carregar")
        {
            entrada >> a;
            if (a.empty()) a = "arvore.txt";
            cout << (carregarArquivo(a) ? "Arvore carregada.\n" : "Erro ao carregar arquivo.\n");
        }
        else
        {
            cout << "Comando desconhecido. Digite ajuda.\n";
        }
    }

    void iniciar()
    {
        cout << "Simulador de arquivos com arvore N-aria (C++). Digite ajuda.\n";
        string linha;
        while (true)
        {
            cout << "fs:" << caminhoDe(atual) << "$ ";
            if (!getline(cin, linha))
            {
                break;
            }
            if (linha == "sair" || linha == "exit")
            {
                break;
            }
            executar(linha);
        }
    }
};

int main()
{
    Sistema sistema;
    sistema.iniciar();
    return 0;
}
