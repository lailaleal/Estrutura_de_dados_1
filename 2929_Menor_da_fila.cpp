#include<stdio.h>  // Inclui a biblioteca para entrada e saída padrão
#include<string.h> // Inclui a biblioteca para manipulação de strings (usada para a função strcmp)

struct No {
    long long valor;  // Atributo que armazena o valor do nó (elemento da pilha)
    No* prox;         // Ponteiro para o próximo nó da pilha

    // Construtor padrão do nó, inicializa o valor como 0 e o ponteiro prox como NULL
    No() {
        valor = 0;
        prox = NULL;
    }

    // Construtor do nó com valor fornecido pelo usuário, o prox é inicializado como NULL
    No(long long _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Pilha {
    No* topo;  // Ponteiro para o topo da pilha
    int n;     // Atributo que armazena o número de elementos na pilha

    // Construtor da pilha, inicializa o topo como NULL e o número de elementos como 0
    Pilha() {
        topo = NULL;
        n = 0;
    }

    // Método que insere um valor na pilha
    void inserir(long long valor) {
        No* novo = new No(valor);  // Cria um novo nó com o valor fornecido
        if (topo == NULL) {  // Se a pilha estiver vazia
            topo = novo;  // O topo da pilha será o novo nó
        } else {
            novo->prox = topo;  // O novo nó aponta para o antigo topo
            topo = novo;  // O topo agora é o novo nó
        }
        n++;  // Incrementa o contador de elementos na pilha
    }

    // Método que remove o topo da pilha
    void remover() {
        if (n == 0) return;  // Se a pilha estiver vazia, não faz nada
        if (n == 1) {  // Se houver apenas um elemento na pilha
            delete(topo);  // Deleta o nó do topo
            topo = NULL;  // A pilha fica vazia
            n = 0;  // O número de elementos é 0
            return;
        }
        No* aux = topo;  // Armazena o topo atual
        topo = topo->prox;  // O topo agora passa a ser o próximo nó
        delete(aux);  // Deleta o antigo topo
        n--;  // Decrementa o contador de elementos
    }

    // Método que retorna o valor do topo da pilha
    int topoPilha() {
        if (topo == NULL) return 0;  // Se a pilha estiver vazia, retorna 0 (não há valor)
        return topo->valor;  // Retorna o valor do topo
    }
};

int main() {
    Pilha p, m;  // Cria duas pilhas: 'p' para a pilha principal e 'm' para a pilha de mínimos

    int n;
    scanf("%d", &n);  // Lê o número de operações a serem realizadas
    while (n--) {  // Realiza as operações enquanto houver entradas
        char tmp[10];  // String para armazenar a operação
        scanf("%s", tmp);  // Lê a operação (PUSH, POP ou MIN)

        // Caso a operação seja "PUSH"
        if (strcmp(tmp, "PUSH") == 0) {
            long long x;
            scanf("%lld", &x);  // Lê o valor a ser inserido
            p.inserir(x);  // Insere o valor na pilha principal

            // Verifica se a pilha de mínimos está vazia ou se o valor inserido é menor ou igual ao mínimo atual
            if (m.n == 0) {
                m.inserir(x);  // Se a pilha de mínimos estiver vazia, insere o valor
            } else if (m.topoPilha() >= x) {
                m.inserir(x);  // Se o valor inserido for menor ou igual ao topo da pilha de mínimos, insere na pilha de mínimos
            }
        }
        // Caso a operação seja "MIN"
        else if (strcmp(tmp, "MIN") == 0) {
            if (m.n == 0) {  // Se a pilha de mínimos estiver vazia
                printf("EMPTY\n");  // Imprime "EMPTY" pois não há valor mínimo
            } else {
                printf("%d\n", m.topoPilha());  // Caso contrário, imprime o valor do topo da pilha de mínimos
            }
        }
        // Caso a operação seja "POP"
        else if (strcmp(tmp, "POP") == 0) {
            if (m.n == 0) {  // Se a pilha de mínimos estiver vazia
                printf("EMPTY\n");  // Imprime "EMPTY" porque a pilha está vazia
            } else {
                // Se o topo da pilha principal for igual ao topo da pilha de mínimos, remove o topo da pilha de mínimos também
                if (m.topoPilha() == p.topoPilha()) {
                    m.remover();  // Remove da pilha de mínimos
                }
                p.remover();  // Remove da pilha principal
            }
        }
    }

    return 0;  // Retorna 0, indicando que o programa terminou corretamente
}

