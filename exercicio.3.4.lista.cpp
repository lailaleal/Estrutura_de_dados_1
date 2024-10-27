#include <iostream>

using namespace std;

// Estrutura do nó individual da lista encadeada
struct Node {
    int value;         // Armazena o valor do nó
    Node* next;        // Ponteiro para o próximo nó na lista

    // Construtor que inicializa um nó com um valor dado
    Node(int val) {
        value = val;   // Atribui o valor recebido ao campo value do nó
        next = nullptr; // Inicializa o ponteiro 'next' como nulo (último nó por padrão)
    }
};

// Estrutura da lista encadeada
struct List {
    Node* first;  // Ponteiro para o primeiro nó da lista
    Node* last;   // Ponteiro para o último nó da lista
    int size;     // Contador de nós na lista para otimizar operações de tamanho

    // Construtor que inicializa uma lista vazia
    List() {
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    // Método para verificar se a lista está vazia
    bool empty() {
        return first == nullptr;
    }

    // Método para adicionar um valor ao final da lista
    void pushBack(int value) {
        Node* newNode = new Node(value); // Cria um novo nó com o valor fornecido
        size++;
        if (empty()) {
            first = last = newNode;      // Define o novo nó como o primeiro e o último
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    // Método para inserir no final da lista o tamanho atual da lista
    void insertSizeAtEnd() {
        pushBack(size); // Insere o tamanho da lista como um novo elemento no final
    }

    // Método para inserir todos os números de 1 até N no final da lista
    void insertRange(int N) {
        for (int i = 1; i <= N; i++) { // Itera de 1 até N
            pushBack(i);               // Insere cada número ao final da lista
        }
    }

    // Método para remover os últimos N elementos da lista
    void removeLastN(int n) {
        if (n >= size) { // Se N é maior ou igual ao tamanho, esvazia a lista
            while (!empty()) {
                popFront();
            }
            return;
        }

        int elementsToKeep = size - n;
        Node* current = first;
        for (int i = 1; i < elementsToKeep; i++) {
            current = current->next;
        }

        Node* toDelete = current->next;
        current->next = nullptr;
        last = current;

        while (toDelete) {
            Node* next = toDelete->next;
            delete toDelete;
            toDelete = next;
        }

        size = elementsToKeep;
    }

    // Método auxiliar para remover o primeiro elemento da lista
    void popFront() {
        if (empty()) return;
        Node* toDelete = first;
        first = first->next;
        delete toDelete;
        size--;
        if (empty()) last = nullptr;
    }

    // Método para imprimir todos os elementos da lista
    void print() {
        Node* current = first;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    List l;
    int n, inputValue;

    cout << "Digite a quantidade de valores a inserir na lista: ";
    cin >> n;

    cout << "Digite os valores para adicionar à lista:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> inputValue;
        l.pushBack(inputValue);
    }

    cout << "Lista antes das inserções especiais: ";
    l.print();

    // Exemplo de uso do método insertSizeAtEnd
    l.insertSizeAtEnd();
    cout << "Lista após inserir o tamanho atual ao final: ";
    l.print();

    // Exemplo de uso do método insertRange
    int rangeN;
    cout << "Digite o valor de N para inserir de 1 até N: ";
    cin >> rangeN;
    l.insertRange(rangeN);
    cout << "Lista após inserir todos os valores de 1 até " << rangeN << ": ";
    l.print();

    return 0;
}

