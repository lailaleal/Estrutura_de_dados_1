#include <iostream>  // Inclui a biblioteca padrão de entrada e saída
using namespace std;
#include<stdio.h>

struct No {

    int valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Fila {

    No* inicio;
    No* fim;
    int n;

    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void enfileirar(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void enfileirarOrdenado(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            if (valor >= inicio->valor) {
                novo->prox = inicio;
                inicio = novo;
            } else if (valor <= fim->valor) {
                fim->prox = novo;
                fim = novo;
            } else {
                No *aux = inicio, *aux2;
                while (valor < aux->valor) {
                    aux2 = aux;
                    aux = aux->prox;
                }
                novo->prox = aux;
                aux2->prox = novo;
            }
        }
        n++;
    }

    void desenfileirar(){
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    int frente() {
        if (inicio == NULL) return 0;
        return inicio->valor;
    }

};

int main() {
    int n;
    cin >> n; // Lê o número de casos de teste

    while (n--) { // Executa o laço para cada caso de teste
        int m;
        cin >> m; // Lê o tamanho da sequência
        Fila f1, f2; // Cria duas filas: uma normal e outra ordenada

        // Lê os elementos da sequência e os insere nas filas
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x; // Lê o elemento
            f1.enfileirar(x); // Insere na fila original
            f2.enfileirarOrdenado(x); // Insere na fila ordenada
        }

        int r = 0; // Contador para o número de elementos iguais nas mesmas posições

        // Compara as filas elemento por elemento
        for (int i = 0; i < m; i++) {
            if (f1.frente() == f2.frente()) { // Verifica se os elementos na frente das filas são iguais
                r++; // Incrementa o contador se forem iguais
            }
            // Desenfileira os elementos de ambas as filas
            f1.desenfileirar();
            f2.desenfileirar();
        }

        cout << r << endl; // Imprime o número de elementos iguais nas mesmas posições
    }

    return 0; // Finaliza o programa
}


