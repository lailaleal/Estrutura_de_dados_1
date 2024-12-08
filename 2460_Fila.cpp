#include <bits/stdc++.h>  // Inclui a biblioteca padr�o C++ com todos os cabe�alhos necess�rios.
using namespace std;  // Para usar as fun��es da biblioteca padr�o sem precisar do prefixo 'std::'.

#define ll long long int  // Define 'll' como um alias para 'long long int', facilitando a declara��o de vari�veis desse tipo.

struct No {  // Declara��o de uma estrutura chamada 'No', que representa um n� de uma lista encadeada.
    int valor;  // Vari�vel para armazenar o valor do n�.
    No* prox;  // Ponteiro para o pr�ximo n� na lista encadeada.

    No(int _valor) : valor(_valor), prox(nullptr) {}  // Construtor que inicializa o n� com um valor e coloca o ponteiro 'prox' como NULL.
};

struct Fila {  // Declara��o de uma estrutura chamada 'Fila', que representa uma fila usando uma lista encadeada.
    No* inicio;  // Ponteiro para o primeiro n� da fila.
    No* fim;  // Ponteiro para o �ltimo n� da fila.
    int n;  // Vari�vel para armazenar o tamanho atual da fila.

    Fila() : inicio(nullptr), fim(nullptr), n(0) {}  // Construtor que inicializa a fila com 'inicio' e 'fim' como NULL e 'n' como 0.

    void enfileirar(int valor) {  // Fun��o que insere um novo valor no final da fila.
        No* novo = new No(valor);  // Cria um novo n� com o valor passado como par�metro.
        if (fim == nullptr) {  // Se a fila estiver vazia (n�o h� nenhum elemento).
            inicio = novo;  // O in�cio e o fim da fila v�o apontar para o novo n�.
            fim = novo;
        } else {  // Se a fila n�o estiver vazia.
            fim->prox = novo;  // O ponteiro 'prox' do �ltimo n� da fila vai apontar para o novo n�.
            fim = novo;  // O ponteiro 'fim' � atualizado para apontar para o novo n�.
        }
        n++;  // Incrementa o tamanho da fila.
    }

    void desenfileirar() {  // Fun��o que remove o valor do in�cio da fila.
        if (n == 0) return;  // Se a fila estiver vazia, n�o faz nada.
        No* aux = inicio;  // Cria um ponteiro 'aux' para armazenar o n� que ser� removido.
        inicio = inicio->prox;  // O ponteiro 'inicio' � movido para o pr�ximo n� da fila.
        delete aux;  // Deleta o n� que foi removido da mem�ria.
        n--;  // Decrementa o tamanho da fila.
        if (n == 0) fim = nullptr;  // Se a fila ficou vazia, 'fim' tamb�m deve ser NULL.
    }

    int frente() {  // Fun��o que retorna o valor do primeiro elemento da fila (o elemento na frente).
        return (inicio == nullptr) ? -1 : inicio->valor;  // Se a fila estiver vazia, retorna -1; caso contr�rio, retorna o valor do primeiro n�.
    }
};

int main() {  // Fun��o principal do programa.
    int n;  // Vari�vel para armazenar o n�mero de elementos a serem enfileirados.
    cin >> n;  // L� o n�mero de elementos.
    Fila fila;  // Cria um objeto 'fila' do tipo 'Fila' que usar� as fun��es para manipular a fila.
    map<int, int> mapa;  // Cria um mapa (dicion�rio) para rastrear quais elementos devem ser removidos.

    // L� os elementos que ser�o inseridos na fila.
    for (int i = 0; i < n; i++) {
        int val;  // Vari�vel para armazenar cada valor.
        scanf("%d", &val);  // L� o valor.
        fila.enfileirar(val);  // Insere o valor na fila.
        mapa[val] = 1;  // Marca o valor no mapa como "presente", ou seja, ele n�o foi removido.
    }

    int m;  // Vari�vel para armazenar o n�mero de elementos a serem removidos.
    cin >> m;  // L� o n�mero de elementos a serem removidos.

    // Processa os n�meros que ser�o removidos da fila.
    while (m--) {  // Enquanto houver n�meros a serem removidos.
        int val;  // Vari�vel para armazenar o valor que ser� removido.
        scanf("%d", &val);  // L� o valor.
        mapa[val] = 0;  // Marca o valor no mapa como "removido" (0).
    }

    // Percorre a fila e imprime os n�meros que n�o foram removidos.
    bool primeiro = true;  // Vari�vel para controlar o formato da impress�o (sem espa�o no in�cio).
    while (fila.n > 0) {  // Enquanto a fila n�o estiver vazia.
        int val = fila.frente();  // Obt�m o valor do primeiro elemento da fila.
        fila.desenfileirar();  // Remove o primeiro elemento da fila.

        // Verifica se o valor n�o foi removido.
        if (mapa[val] == 1) {
            if (primeiro) {  // Se for o primeiro valor a ser impresso.
                printf("%d", val);  // Imprime o valor sem um espa�o antes.
                primeiro = false;  // Define que o pr�ximo valor ter� um espa�o antes.
            } else {
                printf(" %d", val);  // Imprime o valor com um espa�o antes.
            }
        }
    }

    printf("\n");  // Imprime uma nova linha ap�s a sa�da.
    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso.
}
