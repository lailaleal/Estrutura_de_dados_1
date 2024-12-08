#include <iostream>  // Inclui a biblioteca padr�o de entrada e sa�da
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
    cin >> n; // L� o n�mero de casos de teste

    while (n--) { // Executa o la�o para cada caso de teste
        int m;
        cin >> m; // L� o tamanho da sequ�ncia
        Fila f1, f2; // Cria duas filas: uma normal e outra ordenada

        // L� os elementos da sequ�ncia e os insere nas filas
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x; // L� o elemento
            f1.enfileirar(x); // Insere na fila original
            f2.enfileirarOrdenado(x); // Insere na fila ordenada
        }

        int r = 0; // Contador para o n�mero de elementos iguais nas mesmas posi��es

        // Compara as filas elemento por elemento
        for (int i = 0; i < m; i++) {
            if (f1.frente() == f2.frente()) { // Verifica se os elementos na frente das filas s�o iguais
                r++; // Incrementa o contador se forem iguais
            }
            // Desenfileira os elementos de ambas as filas
            f1.desenfileirar();
            f2.desenfileirar();
        }

        cout << r << endl; // Imprime o n�mero de elementos iguais nas mesmas posi��es
    }

    return 0; // Finaliza o programa
}


