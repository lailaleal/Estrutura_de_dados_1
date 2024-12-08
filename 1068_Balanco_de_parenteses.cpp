#include <iostream> // Biblioteca padr�o para entrada e sa�da
#include <cstring>  // Biblioteca para manipula��o de strings, usada para `strlen`
using namespace std;

// Estrutura para representar um n� na pilha
struct No {
    char valor;  // Valor armazenado no n�
    No* prox;    // Ponteiro para o pr�ximo n�

    // Construtor padr�o
    No() {
        valor = 0;   // Inicializa o valor como 0
        prox = NULL; // Inicializa o ponteiro como NULL
    }

    // Construtor que recebe um valor
    No(char _valor) {
        valor = _valor; // Define o valor do n�
        prox = NULL;    // Inicializa o ponteiro como NULL
    }
};

// Estrutura para representar a pilha
struct Pilha {
    No* topo; // Ponteiro para o n� no topo da pilha
    int n;    // Contador de elementos na pilha

    // Construtor da pilha
    Pilha() {
        topo = NULL; // Inicializa o topo como NULL
        n = 0;       // Inicializa o contador como 0
    }

    // M�todo para inserir um elemento na pilha
    void inserir(char valor) {
        No* novo = new No(valor); // Cria um novo n�
        if (topo == NULL) {       // Se a pilha estiver vazia
            topo = novo;          // O novo n� ser� o topo
        } else {                  // Caso contr�rio
            novo->prox = topo;    // O novo n� aponta para o n� atual no topo
            topo = novo;          // Atualiza o topo para o novo n�
        }
        n++; // Incrementa o contador de elementos
    }

    // M�todo para remover um elemento da pilha
    void remover() {
        if (n == 0) return;  // Se a pilha estiver vazia, n�o h� o que remover
        if (n == 1) {        // Se a pilha tiver apenas um elemento
            delete topo;     // Libera a mem�ria do �nico n�
            topo = NULL;     // Atualiza o topo para NULL
            n = 0;           // Zera o contador
            return;
        }
        No* aux = topo;       // Cria um ponteiro auxiliar para o n� do topo
        topo = topo->prox;    // Atualiza o topo para o pr�ximo n�
        delete aux;           // Libera a mem�ria do n� removido
        n--;                  // Decrementa o contador de elementos
    }

    // M�todo para obter o valor do n� no topo
    int topoPilha() {
        if (topo == NULL) return 0; // Se a pilha estiver vazia, retorna 0
        return topo->valor;         // Caso contr�rio, retorna o valor do topo
    }
};

// Fun��o principal
int main() {
    char tmp[1001]; // Array para armazenar a entrada do usu�rio

    // L� v�rias linhas de entrada at� o final do arquivo (EOF)
    while (scanf("%s", tmp) != EOF) {
        Pilha p;       // Cria uma pilha para verificar os par�nteses
        int correto = 1; // Vari�vel para indicar se a sequ�ncia est� correta

        // Percorre cada caractere da string `tmp`
        for (int i = 0, len = strlen(tmp); i < len; i++) {
            // Se o caractere atual for um par�ntese de abertura '('
            if (tmp[i] == '(') {
                p.inserir('('); // Insere um '(' na pilha
            }
            // Se o caractere atual for um par�ntese de fechamento ')'
            else if (tmp[i] == ')') {
                if (p.n > 0) {  // Verifica se h� elementos na pilha
                    p.remover(); // Remove o elemento do topo
                } else {         // Se a pilha estiver vazia
                    correto = 0; // Marca como incorreto
                }
            }
        }

        // Se ainda houver elementos na pilha, a sequ�ncia � incorreta
        if (p.n > 0) {
            correto = 0; // Marca como incorreto
        }

        // Exibe o resultado
        if (correto == 1) {
            cout << "correct\n"; // Sequ�ncia v�lida
        } else {
            cout << "incorrect\n"; // Sequ�ncia inv�lida
        }
    }

    return 0; // Finaliza o programa
}

