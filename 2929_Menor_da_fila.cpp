#include<stdio.h>  // Inclui a biblioteca para entrada e sa�da padr�o
#include<string.h> // Inclui a biblioteca para manipula��o de strings (usada para a fun��o strcmp)

struct No {
    long long valor;  // Atributo que armazena o valor do n� (elemento da pilha)
    No* prox;         // Ponteiro para o pr�ximo n� da pilha

    // Construtor padr�o do n�, inicializa o valor como 0 e o ponteiro prox como NULL
    No() {
        valor = 0;
        prox = NULL;
    }

    // Construtor do n� com valor fornecido pelo usu�rio, o prox � inicializado como NULL
    No(long long _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Pilha {
    No* topo;  // Ponteiro para o topo da pilha
    int n;     // Atributo que armazena o n�mero de elementos na pilha

    // Construtor da pilha, inicializa o topo como NULL e o n�mero de elementos como 0
    Pilha() {
        topo = NULL;
        n = 0;
    }

    // M�todo que insere um valor na pilha
    void inserir(long long valor) {
        No* novo = new No(valor);  // Cria um novo n� com o valor fornecido
        if (topo == NULL) {  // Se a pilha estiver vazia
            topo = novo;  // O topo da pilha ser� o novo n�
        } else {
            novo->prox = topo;  // O novo n� aponta para o antigo topo
            topo = novo;  // O topo agora � o novo n�
        }
        n++;  // Incrementa o contador de elementos na pilha
    }

    // M�todo que remove o topo da pilha
    void remover() {
        if (n == 0) return;  // Se a pilha estiver vazia, n�o faz nada
        if (n == 1) {  // Se houver apenas um elemento na pilha
            delete(topo);  // Deleta o n� do topo
            topo = NULL;  // A pilha fica vazia
            n = 0;  // O n�mero de elementos � 0
            return;
        }
        No* aux = topo;  // Armazena o topo atual
        topo = topo->prox;  // O topo agora passa a ser o pr�ximo n�
        delete(aux);  // Deleta o antigo topo
        n--;  // Decrementa o contador de elementos
    }

    // M�todo que retorna o valor do topo da pilha
    int topoPilha() {
        if (topo == NULL) return 0;  // Se a pilha estiver vazia, retorna 0 (n�o h� valor)
        return topo->valor;  // Retorna o valor do topo
    }
};

int main() {
    Pilha p, m;  // Cria duas pilhas: 'p' para a pilha principal e 'm' para a pilha de m�nimos

    int n;
    scanf("%d", &n);  // L� o n�mero de opera��es a serem realizadas
    while (n--) {  // Realiza as opera��es enquanto houver entradas
        char tmp[10];  // String para armazenar a opera��o
        scanf("%s", tmp);  // L� a opera��o (PUSH, POP ou MIN)

        // Caso a opera��o seja "PUSH"
        if (strcmp(tmp, "PUSH") == 0) {
            long long x;
            scanf("%lld", &x);  // L� o valor a ser inserido
            p.inserir(x);  // Insere o valor na pilha principal

            // Verifica se a pilha de m�nimos est� vazia ou se o valor inserido � menor ou igual ao m�nimo atual
            if (m.n == 0) {
                m.inserir(x);  // Se a pilha de m�nimos estiver vazia, insere o valor
            } else if (m.topoPilha() >= x) {
                m.inserir(x);  // Se o valor inserido for menor ou igual ao topo da pilha de m�nimos, insere na pilha de m�nimos
            }
        }
        // Caso a opera��o seja "MIN"
        else if (strcmp(tmp, "MIN") == 0) {
            if (m.n == 0) {  // Se a pilha de m�nimos estiver vazia
                printf("EMPTY\n");  // Imprime "EMPTY" pois n�o h� valor m�nimo
            } else {
                printf("%d\n", m.topoPilha());  // Caso contr�rio, imprime o valor do topo da pilha de m�nimos
            }
        }
        // Caso a opera��o seja "POP"
        else if (strcmp(tmp, "POP") == 0) {
            if (m.n == 0) {  // Se a pilha de m�nimos estiver vazia
                printf("EMPTY\n");  // Imprime "EMPTY" porque a pilha est� vazia
            } else {
                // Se o topo da pilha principal for igual ao topo da pilha de m�nimos, remove o topo da pilha de m�nimos tamb�m
                if (m.topoPilha() == p.topoPilha()) {
                    m.remover();  // Remove da pilha de m�nimos
                }
                p.remover();  // Remove da pilha principal
            }
        }
    }

    return 0;  // Retorna 0, indicando que o programa terminou corretamente
}

