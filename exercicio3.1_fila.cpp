#include<stdio.h>


// Lista se inicia vazia

struct Node { // nó

    int value;  // A Struct de nó é composta de uma parte que será variável que irá representar este nó,
    Node* next; //  Ponteiro = armazena a referencia o endereço de memória para a proxima posição a ser lida

    Node() {
        value = 0; // inicializa o valor= 0 e o próximo = null, vazio. Ao inserir qnd a lista está vazia, o início e o fim da lista passam a ser o
        next = NULL;  // valor que acabou de ser inserido. fist e last irão receber o endereço de memória do primeiro valor inserido.
    }

    Node(int _value) { _valor // _value = proximo ou ultimo elemento a adicionado a lista,
        value = _value; // o a variável valor irá recebe-lo,
        next = NULL; // e por ter sido o ultimo adicionado o next q direciona o ponteiro para o proximo a ser lido ficará fazio.
    }

};

struct List {

    Node* first; // Criando a posição inicio e fim, endereço de memória da primeira e ultima posição, a lista é composta do endereco do primeiro e ultimo
    Node* last; // elemento da lista.

    List() {
        first = NULL; // Lista vazia, ambas as posições, endereços de memória se iniciam com vazio. Ao criar a lista, é criado dois espaços, primeiro e ultimo
        last = NULL; // e ambos são inicializados vazios.
    }


    bool empty() {
        return first == NULL; // Se a primeira posição está fazia, retorna verdadeiro, Sei que a lista está vazia se o início retornar NULL = Vazio
    }
    // PRIMEIRA INSERÇÃO NA LISTA: INICIO DA LISTA
    void pushFront(int value) { // Função para inserir no INÍCIO
        Node *n = new Node(value); // cria um novo nó. n= local q recebe endereço do valor inserido, *S = endereço do proximo valor a ser lido |__n__|__*S__|
        if (empty()) { // Se a condição do booleano acima (primeira posição está vazia? Sim = V)
            first = n; // O ponteiro do início e fim da lista irá apontar para este novo nó criado. O primeiro nó criado é tanto o início qnt o fim da lista.
            last = n;
            return;
        } // LISTA NÃO ESTÁ VAZIA
        n->next = first; // O endereço da proxima posição irá apontar para o first atual da lista
        first = n; // first aponta para o novo nó
    }

    void pushBack(int value) { // Função para inserir no FINAL
        Node *n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        } // LISTA NÃO ESTÁ VAZIA
        last->next = n; // Ultimo elemento aponta para o novo nó
        last = n; // last aponta para o novo nó
    }

    void print() {
        Node* aux = first; // aux vai percorrer a lista e começa no primeiro elemento (como se fosse i do for)
        while (aux != NULL) { // Não foi usado for, pois não temos um tamanho fixo
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
    }

};

int main() {

    List l;

    l.pushFront(10);
    l.pushFront(20);
    l.pushFront(30);
    l.pushBack(30);
    l.pushBack(50);
    l.print();

    return 0;
}
