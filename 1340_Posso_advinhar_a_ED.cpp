#include <iostream>
#include <cstring>  // Para utilizar memset
using namespace std;

// Definindo as estruturas de dados para Fila, Pilha e Fila de Prioridade
struct tipo_sacola {
    int elemento_fila[1000];           // Vetor que armazena os elementos da Fila
    int comeco_fila, final_fila;       // Índices de controle da Fila

    int elemento_pilha[1000];          // Vetor que armazena os elementos da Pilha
    int indice_pilha;                  // Índice de controle da Pilha

    int elemento_lista_prioridade[1000];  // Vetor que armazena os elementos da Fila de Prioridade
    int indice_lista_prioridade;          // Índice de controle da Fila de Prioridade
};

// Função de inserção na Fila
void insere_fila(int valor, tipo_sacola* dado) {
    dado->elemento_fila[dado->final_fila++] = valor;  // Adiciona o valor ao final da Fila
}

// Função de remoção da Fila
int remove_fila(tipo_sacola* dado) {
    if (dado->comeco_fila == dado->final_fila) {  // Se a Fila estiver vazia
        return -10000000;  // Retorna um valor inválido
    }
    return dado->elemento_fila[dado->comeco_fila++];  // Remove o valor da frente da Fila
}

// Função de inserção na Pilha
void insere_pilha(int valor, tipo_sacola* dado) {
    dado->elemento_pilha[++dado->indice_pilha] = valor;  // Adiciona o valor ao topo da Pilha
}

// Função de remoção da Pilha
int remove_pilha(tipo_sacola* dado) {
    if (dado->indice_pilha <= 0) {  // Se a Pilha estiver vazia
        return -10000000;  // Retorna um valor inválido
    }
    return dado->elemento_pilha[dado->indice_pilha--];  // Remove o valor do topo da Pilha
}

// Função de inserção na Fila de Prioridade
void insere_lista_prioridade(int valor, tipo_sacola* dado) {
    int indexador_auxiliar = ++dado->indice_lista_prioridade;
    // Realiza a inserção mantendo a ordem da Fila de Prioridade
    while (indexador_auxiliar > 1) {
        if (dado->elemento_lista_prioridade[indexador_auxiliar / 2] < valor) {
            dado->elemento_lista_prioridade[indexador_auxiliar] =
                dado->elemento_lista_prioridade[indexador_auxiliar / 2];
            indexador_auxiliar = indexador_auxiliar / 2;
        } else {
            break;
        }
    }
    dado->elemento_lista_prioridade[indexador_auxiliar] = valor;  // Insere o valor na posição correta
}

// Função de remoção da Fila de Prioridade
int remove_lista_prioridade(tipo_sacola* dado) {
    if (dado->indice_lista_prioridade <= 0) {  // Se a Fila de Prioridade estiver vazia
        return -10000000;  // Retorna um valor inválido
    }

    int temporario = dado->elemento_lista_prioridade[1];  // O maior valor está na posição 1
    int atual = 1, proximo = 2;
    dado->indice_lista_prioridade--;  // Decrementa o tamanho da Fila de Prioridade

    // Rearranja a Fila de Prioridade
    while (proximo <= dado->indice_lista_prioridade) {
        if (proximo < dado->indice_lista_prioridade &&
            dado->elemento_lista_prioridade[proximo + 1] > dado->elemento_lista_prioridade[proximo]) {
            proximo++;
        }
        if (dado->elemento_lista_prioridade[proximo] > dado->elemento_lista_prioridade[dado->indice_lista_prioridade + 1]) {
            dado->elemento_lista_prioridade[atual] = dado->elemento_lista_prioridade[proximo];
            atual = proximo;
            proximo = atual * 2;
        } else {
            break;
        }
    }
    dado->elemento_lista_prioridade[atual] = dado->elemento_lista_prioridade[dado->indice_lista_prioridade + 1];
    return temporario;  // Retorna o valor removido
}

int main() {
    int n;  // Número de comandos
    while (cin >> n) {  // Enquanto houver comandos para processar
        int flag[3] = {0, 0, 0};  // Flags para marcar se uma estrutura é válida (Fila, Pilha, Fila de Prioridade)
        tipo_sacola data;  // Variável para armazenar as estruturas de dados

        // Inicializa as variáveis de controle das estruturas
        data.comeco_fila = 0;
        data.final_fila = 0;
        data.indice_pilha = 0;
        data.indice_lista_prioridade = 0;

        for (int i = 0; i < n; i++) {
            int comando, valor;
            cin >> comando >> valor;  // Lê o comando e o valor associado

            if (comando == 1) {  // Comando de inserção
                insere_fila(valor, &data);  // Insere o valor na Fila
                insere_pilha(valor, &data);  // Insere o valor na Pilha
                insere_lista_prioridade(valor, &data);  // Insere o valor na Fila de Prioridade
            } else {  // Comando de remoção
                int recebido;

                // Remover da Fila
                recebido = remove_fila(&data);
                if (recebido != valor) {
                    flag[0] = 1;  // Marca a Fila como inválida
                }

                // Remover da Pilha
                recebido = remove_pilha(&data);
                if (recebido != valor) {
                    flag[1] = 1;  // Marca a Pilha como inválida
                }

                // Remover da Fila de Prioridade
                recebido = remove_lista_prioridade(&data);
                if (recebido != valor) {
                    flag[2] = 1;  // Marca a Fila de Prioridade como inválida
                }
            }
        }

        // Verificar o resultado com base nas flags
        if (flag[0] + flag[1] + flag[2] == 3) {
            cout << "impossible\n";  // Se todas as flags forem ativadas, é impossível
        } else if (flag[0] + flag[1] + flag[2] < 2) {
            cout << "not sure\n";  // Se não há certeza, imprime "not sure"
        } else {
            if (!flag[0]) {
                cout << "queue\n";  // Se a Fila for válida, imprime "queue"
            }
            if (!flag[1]) {
                cout << "stack\n";  // Se a Pilha for válida, imprime "stack"
            }
            if (!flag[2]) {
                cout << "priority queue\n";  // Se a Fila de Prioridade for válida, imprime "priority queue"
            }
        }
    }
    return 0;
}

