#include <iostream> // Biblioteca padrão para entrada e saída
#include <cstring>  // Biblioteca para manipulação de strings
using namespace std;

struct No {

    char valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(char _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Pilha {

    No* topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    void inserir(char valor) {
        No* novo = new No(valor);
        if (topo == NULL) {
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    void remover() {
        if (n == 0) return;
        if (n == 1) {
            delete(topo);
            topo = NULL;
            n = 0;
            return;
        }
        No* aux = topo;
        topo = topo->prox;
        delete(aux);
        n--;
    }

    int topoPilha() {
        if (topo == NULL) return 0;
        return topo->valor;
    }

    bool match(char a, char b, char c, char d) {
        No *aux = topo;
        if (aux->valor == a) {
            aux = aux->prox;
            if (aux->valor == b) {
                aux = aux->prox;
                if (aux->valor == c) {
                    aux = aux->prox;
                    if (aux->valor == d) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

};

#include <iostream>
using namespace std;

int main() {
    int n, q = 0; // n: número de operações, q: contador de partidas bem-sucedidas
    cin >> n;
    cin.ignore(); // Ignora o caractere de nova linha após a entrada de n

    Pilha p; // Cria a pilha

    while (n--) {
        char a, b, c, d; // Quatro caracteres a serem lidos
        cin >> a >> b >> c >> d;
        cin.ignore(); // Ignora o caractere de nova linha após os 4 caracteres

        // Se a pilha estiver vazia, insere os elementos "FACE"
        if (p.n == 0) {
            p.inserir('F');
            p.inserir('A');
            p.inserir('C');
            p.inserir('E');
        }

        // Verifica se os caracteres formam um "match" com o topo da pilha
        if (p.match(a, b, c, d)) {
            // Remove os 4 elementos do topo da pilha
            p.remover();
            p.remover();
            p.remover();
            p.remover();
            q++; // Incrementa o contador de partidas bem-sucedidas
        } else {
            // Adiciona os 4 caracteres na pilha
            p.inserir(a);
            p.inserir(b);
            p.inserir(c);
            p.inserir(d);
        }
    }

    cout << q << endl; // Imprime o número de partidas bem-sucedidas

    return 0;
}

