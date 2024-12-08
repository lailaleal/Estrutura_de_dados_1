#include <bits/stdc++.h>  // Inclui a biblioteca padrão C++ com todos os cabeçalhos necessários.
using namespace std;  // Para usar as funções da biblioteca padrão sem precisar do prefixo 'std::'.

#define ll long long int  // Define 'll' como um alias para 'long long int', facilitando a declaração de variáveis desse tipo.

struct No {  // Declaração de uma estrutura chamada 'No', que representa um nó de uma lista encadeada.
    int valor;  // Variável para armazenar o valor do nó.
    No* prox;  // Ponteiro para o próximo nó na lista encadeada.

    No(int _valor) : valor(_valor), prox(nullptr) {}  // Construtor que inicializa o nó com um valor e coloca o ponteiro 'prox' como NULL.
};

struct Fila {  // Declaração de uma estrutura chamada 'Fila', que representa uma fila usando uma lista encadeada.
    No* inicio;  // Ponteiro para o primeiro nó da fila.
    No* fim;  // Ponteiro para o último nó da fila.
    int n;  // Variável para armazenar o tamanho atual da fila.

    Fila() : inicio(nullptr), fim(nullptr), n(0) {}  // Construtor que inicializa a fila com 'inicio' e 'fim' como NULL e 'n' como 0.

    void enfileirar(int valor) {  // Função que insere um novo valor no final da fila.
        No* novo = new No(valor);  // Cria um novo nó com o valor passado como parâmetro.
        if (fim == nullptr) {  // Se a fila estiver vazia (não há nenhum elemento).
            inicio = novo;  // O início e o fim da fila vão apontar para o novo nó.
            fim = novo;
        } else {  // Se a fila não estiver vazia.
            fim->prox = novo;  // O ponteiro 'prox' do último nó da fila vai apontar para o novo nó.
            fim = novo;  // O ponteiro 'fim' é atualizado para apontar para o novo nó.
        }
        n++;  // Incrementa o tamanho da fila.
    }

    void desenfileirar() {  // Função que remove o valor do início da fila.
        if (n == 0) return;  // Se a fila estiver vazia, não faz nada.
        No* aux = inicio;  // Cria um ponteiro 'aux' para armazenar o nó que será removido.
        inicio = inicio->prox;  // O ponteiro 'inicio' é movido para o próximo nó da fila.
        delete aux;  // Deleta o nó que foi removido da memória.
        n--;  // Decrementa o tamanho da fila.
        if (n == 0) fim = nullptr;  // Se a fila ficou vazia, 'fim' também deve ser NULL.
    }

    int frente() {  // Função que retorna o valor do primeiro elemento da fila (o elemento na frente).
        return (inicio == nullptr) ? -1 : inicio->valor;  // Se a fila estiver vazia, retorna -1; caso contrário, retorna o valor do primeiro nó.
    }
};

int main() {  // Função principal do programa.
    int n;  // Variável para armazenar o número de elementos a serem enfileirados.
    cin >> n;  // Lê o número de elementos.
    Fila fila;  // Cria um objeto 'fila' do tipo 'Fila' que usará as funções para manipular a fila.
    map<int, int> mapa;  // Cria um mapa (dicionário) para rastrear quais elementos devem ser removidos.

    // Lê os elementos que serão inseridos na fila.
    for (int i = 0; i < n; i++) {
        int val;  // Variável para armazenar cada valor.
        scanf("%d", &val);  // Lê o valor.
        fila.enfileirar(val);  // Insere o valor na fila.
        mapa[val] = 1;  // Marca o valor no mapa como "presente", ou seja, ele não foi removido.
    }

    int m;  // Variável para armazenar o número de elementos a serem removidos.
    cin >> m;  // Lê o número de elementos a serem removidos.

    // Processa os números que serão removidos da fila.
    while (m--) {  // Enquanto houver números a serem removidos.
        int val;  // Variável para armazenar o valor que será removido.
        scanf("%d", &val);  // Lê o valor.
        mapa[val] = 0;  // Marca o valor no mapa como "removido" (0).
    }

    // Percorre a fila e imprime os números que não foram removidos.
    bool primeiro = true;  // Variável para controlar o formato da impressão (sem espaço no início).
    while (fila.n > 0) {  // Enquanto a fila não estiver vazia.
        int val = fila.frente();  // Obtém o valor do primeiro elemento da fila.
        fila.desenfileirar();  // Remove o primeiro elemento da fila.

        // Verifica se o valor não foi removido.
        if (mapa[val] == 1) {
            if (primeiro) {  // Se for o primeiro valor a ser impresso.
                printf("%d", val);  // Imprime o valor sem um espaço antes.
                primeiro = false;  // Define que o próximo valor terá um espaço antes.
            } else {
                printf(" %d", val);  // Imprime o valor com um espaço antes.
            }
        }
    }

    printf("\n");  // Imprime uma nova linha após a saída.
    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso.
}
