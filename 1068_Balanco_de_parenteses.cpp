#include <iostream> // Biblioteca padrão para entrada e saída
#include <cstring>  // Biblioteca para manipulação de strings, usada para `strlen`
using namespace std;

// Estrutura para representar um nó na pilha
struct No {
    char valor;  // Valor armazenado no nó
    No* prox;    // Ponteiro para o próximo nó

    // Construtor padrão
    No() {
        valor = 0;   // Inicializa o valor como 0
        prox = NULL; // Inicializa o ponteiro como NULL
    }

    // Construtor que recebe um valor
    No(char _valor) {
        valor = _valor; // Define o valor do nó
        prox = NULL;    // Inicializa o ponteiro como NULL
    }
};

// Estrutura para representar a pilha
struct Pilha {
    No* topo; // Ponteiro para o nó no topo da pilha
    int n;    // Contador de elementos na pilha

    // Construtor da pilha
    Pilha() {
        topo = NULL; // Inicializa o topo como NULL
        n = 0;       // Inicializa o contador como 0
    }

    // Método para inserir um elemento na pilha
    void inserir(char valor) {
        No* novo = new No(valor); // Cria um novo nó
        if (topo == NULL) {       // Se a pilha estiver vazia
            topo = novo;          // O novo nó será o topo
        } else {                  // Caso contrário
            novo->prox = topo;    // O novo nó aponta para o nó atual no topo
            topo = novo;          // Atualiza o topo para o novo nó
        }
        n++; // Incrementa o contador de elementos
    }

    // Método para remover um elemento da pilha
    void remover() {
        if (n == 0) return;  // Se a pilha estiver vazia, não há o que remover
        if (n == 1) {        // Se a pilha tiver apenas um elemento
            delete topo;     // Libera a memória do único nó
            topo = NULL;     // Atualiza o topo para NULL
            n = 0;           // Zera o contador
            return;
        }
        No* aux = topo;       // Cria um ponteiro auxiliar para o nó do topo
        topo = topo->prox;    // Atualiza o topo para o próximo nó
        delete aux;           // Libera a memória do nó removido
        n--;                  // Decrementa o contador de elementos
    }

    // Método para obter o valor do nó no topo
    int topoPilha() {
        if (topo == NULL) return 0; // Se a pilha estiver vazia, retorna 0
        return topo->valor;         // Caso contrário, retorna o valor do topo
    }
};

// Função principal
int main() {
    char tmp[1001]; // Array para armazenar a entrada do usuário

    // Lê várias linhas de entrada até o final do arquivo (EOF)
    while (scanf("%s", tmp) != EOF) {
        Pilha p;       // Cria uma pilha para verificar os parênteses
        int correto = 1; // Variável para indicar se a sequência está correta

        // Percorre cada caractere da string `tmp`
        for (int i = 0, len = strlen(tmp); i < len; i++) {
            // Se o caractere atual for um parêntese de abertura '('
            if (tmp[i] == '(') {
                p.inserir('('); // Insere um '(' na pilha
            }
            // Se o caractere atual for um parêntese de fechamento ')'
            else if (tmp[i] == ')') {
                if (p.n > 0) {  // Verifica se há elementos na pilha
                    p.remover(); // Remove o elemento do topo
                } else {         // Se a pilha estiver vazia
                    correto = 0; // Marca como incorreto
                }
            }
        }

        // Se ainda houver elementos na pilha, a sequência é incorreta
        if (p.n > 0) {
            correto = 0; // Marca como incorreto
        }

        // Exibe o resultado
        if (correto == 1) {
            cout << "correct\n"; // Sequência válida
        } else {
            cout << "incorrect\n"; // Sequência inválida
        }
    }

    return 0; // Finaliza o programa
}

