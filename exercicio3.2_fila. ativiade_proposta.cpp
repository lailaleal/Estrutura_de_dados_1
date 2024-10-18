#include <iostream> // Biblioteca usada para entrada e saída padrão

// Lista se inicia vazia
struct Node { // nó

    int value;  // A Struct de nó é composta de uma parte que será variável que irá representar este nó
    Node* next; // Ponteiro que armazena a referência do endereço de memória para a próxima posição a ser lida

    Node() {
        value = 0; // Inicializa o valor com 0 e o próximo com NULL, vazio
        next = nullptr;  // Usamos nullptr no C++ em vez de NULL
    }

    Node(int _value) { // _value = próximo ou último elemento adicionado à lista
        value = _value; // A variável value recebe o valor passado
        next = nullptr; // Como foi o último adicionado, next que direciona o ponteiro para o próximo a ser lido fica vazio
    }
};

struct List {

    Node* first; // Criando a posição início e fim, endereço de memória do primeiro e último elemento da lista
    Node* last;  // elemento da lista

    List() {
        first = nullptr; // Inicializa ambas as posições, início e fim, com nullptr indicando que a lista está vazia
        last = nullptr;
    }

    bool empty() {
        return first == nullptr; // Se a primeira posição está vazia, retorna verdadeiro
    }

    // PRIMEIRA INSERÇÃO NA LISTA: INÍCIO DA LISTA
    void pushFront(int value) { // Função para inserir no INÍCIO
        Node *n = new Node(value); // Cria um novo nó
        if (empty()) { // Se a lista estiver vazia
            first = n; // O ponteiro do início e fim da lista irá apontar para este novo nó criado
            last = n;
            return;
        }
        n->next = first; // O endereço do novo nó aponta para o first atual da lista
        first = n; // Atualiza o first para apontar para o novo nó
    }

    void pushBack(int value) { // Função para inserir no FINAL
        Node *n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n; // O último elemento atualiza para apontar para o novo nó
        last = n; // Atualiza o last para ser o novo nó
    }

    void print() {
        Node* aux = first; // Começa no primeiro elemento
        while (aux != nullptr) { // Continua enquanto não chegar ao fim da lista
            std::cout << aux->value << " -> "; // Usa cout em vez de printf no C++
            aux = aux->next;
        }
        std::cout << "nullptr" << std::endl; // Para indicar o fim da lista
    }
};

int main() {
    List l;

    l.pushFront(10); // colocando o número 10 no ínício da lista
    l.pushFront(3);
    l.pushBack(5);
    l.pushBack(3);
    l.pushFront(8);
    l.pushBack(50);
    l.pushFront(78);//
    l.pushBack(1);
    l.pushBack(75);
    l.pushFront(25);
    l.pushBack(60);
    l.pushFront(34);
    l.pushBack(80);
    l.pushBack(30);
    l.pushBack(23);
    l.pushFront(5);
    l.pushFront(66);
    l.print();

    return 0;
}

