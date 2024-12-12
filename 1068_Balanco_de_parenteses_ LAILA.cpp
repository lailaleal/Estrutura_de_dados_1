// COPIAR A PILHA DINAMICA = VETOR NÃO TEM TAMANHO FIXO
// COMO ( E ) SÃO CHAR, MUDAR INT PARA CHAR, SÓ CHAR QUE SERÁ ARMAZENADO NA PILHA
#include <iostream>  // Inclui a biblioteca padrão de entrada e saída
#include <cstring>  // size_
using namespace std;  // Usa o namespace padrão para simplificar o uso de std

struct Node {

    char value; // valor armazenado no nó
    Node* next;// ponterio para o proximo da lista

    // construtor padrão com valor 0
    Node() {
        value = 0;
        next = NULL;
    }
    // construtor com valor fornecido pelo usuario
    Node(char _value) {
        value = _value;
        next = NULL;
    }
};

struct stack {

    Node* t; // ponteiro para o ultimo termo da lista e topo da pilha

    stack() {
        t = NULL; // pilha começa fazia
    }

    bool empty() { // O(1) // verificando se a pilha começa vazia
        return t == NULL;
    }

    void push(char value) { // O(1)  // adiciona um elemento no topo da pilha
        Node* n = new Node(value); // cria um nó com o valor dado
        if (empty()) {  // se a pilha estiver vazia
            t = n; // o topo será o novo valor digitado
            return;
        }
        n->next = t;// o next do novo nó aponta para o antigo topo
        t = n; // topo agora é o novo nó
    }
    //  REMOVE O TOPO DA PILHA
    void pop() { // O(1)
        if (empty()) { // se a pilha estiver vazia
            return;
        }
        if (t->next == NULL) { // se houver 1 unico elemento
            delete(t); // deleta o topo
            t = NULL; // o topo agora é null
            return;
        }
        Node* toDel = t;// armazena o topo atual na variável doDel
        t = t->next; // o tpo agora será o proximo elemento
        delete(toDel); // deleta a variavel q está no toDel
    }
    // RETORNA O VALOR DO TOPO DA PILHA
    int top() { // O(1) // se a pilha estiver vazia
        if (empty()) {
            cout << "Empty\n";
            return -1; // retorna -1 , pois da lista encadeada se inicia com a posição 0, -1 retorna sem posição
        }
        return t->value; // retorna o valor do topo.
    }

};
    int main(){
        stack s;
        char tmp[10001];
        int correct = 1; // VERDADEIRO

        while (cin >> tmp){ // vai ler todas as linhas de entrada
               // cin não retorna EOF como acontece com o scanf
                // exemplo: a+(b*c)-2-a
                for(int i = 0; i < strlen(tmp); i++) { // começa na primeira letra até o tamanho maximo de caracteres da string
                    // fechar parenteses no for
                    if(tmp[i] =='('){ // Se tiver (
                        s.push('('); // adiciona na pilha (pilha contem 1 )
                       }else if (tmp[i] == ')') {
                            if(s.empty()){// se pilha estiver vazia, não foi observado (
                            correct = 0; // incorreto
                            break;} // finaliza o for pq a formula não possui nenhuma (, se tiver so ) não foi adicionado na pilha
                        }s.pop();// Encontrou ), remove o ultimo elemento e continua sendo correto
                }
            // SAI DO FOR ex: (a*b-(2+c) (Pilha recebe dois, e no final retira 1, sobrando 1)
            // Apos percorrer
            if(!s.empty()) return correct = 0; // falso, pois pilha estará com um (, retornando falso
        // exibir resultado

        if (correct == 1){
            cout << "correct\n";

        }cout << "incorrect\n";
    } // fecha o while

    return 0;
    }



