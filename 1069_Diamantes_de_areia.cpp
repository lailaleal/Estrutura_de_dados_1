#include <iostream> // Biblioteca padr�o para entrada e sa�da
#include <cstring>  // Biblioteca para manipula��o de strings, usada para `length`
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

};

int main() {
    int n;
    cin >> n; // L� a quantidade de casos de teste

    while (n--) { // Executa o la�o `n` vezes
        string tmp;
        cin >> tmp; // L� a sequ�ncia de caracteres
        Pilha p;    // Inicializa uma pilha para a an�lise
        int diamantes = 0; // Vari�vel para contar os diamantes encontrados

        // Percorre cada caractere da string `tmp`
        for (int i = 0; i < tmp.length(); i++) {
            if (tmp[i] == '<') { // Se for o s�mbolo de abertura '<'
                p.inserir('<');  // Insere na pilha
            } else if (tmp[i] == '>') { // Se for o s�mbolo de fechamento '>'
                if (p.n > 0) {  // Verifica se h� elementos na pilha
                    p.remover(); // Remove um elemento correspondente da pilha
                    diamantes++; // Incrementa o contador de diamantes
                }
            }
        }

        cout << diamantes << endl; // Imprime o n�mero de diamantes encontrados
    }

    return 0; // Finaliza o programa
}


