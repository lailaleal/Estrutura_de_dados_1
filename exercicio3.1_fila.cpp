#include<stdio.h>


// Lista se inicia vazia

struct Node { // n�

    int value;  // A Struct de n� � composta de uma parte que ser� vari�vel que ir� representar este n�,
    Node* next; //  Ponteiro = armazena a referencia o endere�o de mem�ria para a proxima posi��o a ser lida

    Node() {
        value = 0; // inicializa o valor= 0 e o pr�ximo = null, vazio. Ao inserir qnd a lista est� vazia, o in�cio e o fim da lista passam a ser o
        next = NULL;  // valor que acabou de ser inserido. fist e last ir�o receber o endere�o de mem�ria do primeiro valor inserido.
    }

    Node(int _value) { _valor // _value = proximo ou ultimo elemento a adicionado a lista,
        value = _value; // o a vari�vel valor ir� recebe-lo,
        next = NULL; // e por ter sido o ultimo adicionado o next q direciona o ponteiro para o proximo a ser lido ficar� fazio.
    }

};

struct List {

    Node* first; // Criando a posi��o inicio e fim, endere�o de mem�ria da primeira e ultima posi��o, a lista � composta do endereco do primeiro e ultimo
    Node* last; // elemento da lista.

    List() {
        first = NULL; // Lista vazia, ambas as posi��es, endere�os de mem�ria se iniciam com vazio. Ao criar a lista, � criado dois espa�os, primeiro e ultimo
        last = NULL; // e ambos s�o inicializados vazios.
    }


    bool empty() {
        return first == NULL; // Se a primeira posi��o est� fazia, retorna verdadeiro, Sei que a lista est� vazia se o in�cio retornar NULL = Vazio
    }
    // PRIMEIRA INSER��O NA LISTA: INICIO DA LISTA
    void pushFront(int value) { // Fun��o para inserir no IN�CIO
        Node *n = new Node(value); // cria um novo n�. n= local q recebe endere�o do valor inserido, *S = endere�o do proximo valor a ser lido |__n__|__*S__|
        if (empty()) { // Se a condi��o do booleano acima (primeira posi��o est� vazia? Sim = V)
            first = n; // O ponteiro do in�cio e fim da lista ir� apontar para este novo n� criado. O primeiro n� criado � tanto o in�cio qnt o fim da lista.
            last = n;
            return;
        } // LISTA N�O EST� VAZIA
        n->next = first; // O endere�o da proxima posi��o ir� apontar para o first atual da lista
        first = n; // first aponta para o novo n�
    }

    void pushBack(int value) { // Fun��o para inserir no FINAL
        Node *n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        } // LISTA N�O EST� VAZIA
        last->next = n; // Ultimo elemento aponta para o novo n�
        last = n; // last aponta para o novo n�
    }

    void print() {
        Node* aux = first; // aux vai percorrer a lista e come�a no primeiro elemento (como se fosse i do for)
        while (aux != NULL) { // N�o foi usado for, pois n�o temos um tamanho fixo
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
