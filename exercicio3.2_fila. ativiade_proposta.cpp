#include <iostream> // Biblioteca usada para entrada e sa�da padr�o

// Lista se inicia vazia
struct Node { // n�

    int value;  // A Struct de n� � composta de uma parte que ser� vari�vel que ir� representar este n�
    Node* next; // Ponteiro que armazena a refer�ncia do endere�o de mem�ria para a pr�xima posi��o a ser lida

    Node() {
        value = 0; // Inicializa o valor com 0 e o pr�ximo com NULL, vazio
        next = nullptr;  // Usamos nullptr no C++ em vez de NULL
    }

    Node(int _value) { // _value = pr�ximo ou �ltimo elemento adicionado � lista
        value = _value; // A vari�vel value recebe o valor passado
        next = nullptr; // Como foi o �ltimo adicionado, next que direciona o ponteiro para o pr�ximo a ser lido fica vazio
    }
};

struct List {

    Node* first; // Criando a posi��o in�cio e fim, endere�o de mem�ria do primeiro e �ltimo elemento da lista
    Node* last;  // elemento da lista

    List() {
        first = nullptr; // Inicializa ambas as posi��es, in�cio e fim, com nullptr indicando que a lista est� vazia
        last = nullptr;
    }

    bool empty() {
        return first == nullptr; // Se a primeira posi��o est� vazia, retorna verdadeiro
    }

    // PRIMEIRA INSER��O NA LISTA: IN�CIO DA LISTA
    void pushFront(int value) { // Fun��o para inserir no IN�CIO
        Node *n = new Node(value); // Cria um novo n�
        if (empty()) { // Se a lista estiver vazia
            first = n; // O ponteiro do in�cio e fim da lista ir� apontar para este novo n� criado
            last = n;
            return;
        }
        n->next = first; // O endere�o do novo n� aponta para o first atual da lista
        first = n; // Atualiza o first para apontar para o novo n�
    }

    void pushBack(int value) { // Fun��o para inserir no FINAL
        Node *n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n; // O �ltimo elemento atualiza para apontar para o novo n�
        last = n; // Atualiza o last para ser o novo n�
    }

    void print() {
        Node* aux = first; // Come�a no primeiro elemento
        while (aux != nullptr) { // Continua enquanto n�o chegar ao fim da lista
            std::cout << aux->value << " -> "; // Usa cout em vez de printf no C++
            aux = aux->next;
        }
        std::cout << "nullptr" << std::endl; // Para indicar o fim da lista
    }
};

int main() {
    List l;

    l.pushFront(10); // colocando o n�mero 10 no �n�cio da lista
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

