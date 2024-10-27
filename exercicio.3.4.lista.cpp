#include <iostream>

using namespace std;

// Estrutura do n� individual da lista encadeada
struct Node {
    int value;         // Armazena o valor do n�
    Node* next;        // Ponteiro para o pr�ximo n� na lista

    // Construtor que inicializa um n� com um valor dado
    Node(int val) {
        value = val;   // Atribui o valor recebido ao campo value do n�
        next = nullptr; // Inicializa o ponteiro 'next' como nulo (�ltimo n� por padr�o)
    }
};

// Estrutura da lista encadeada
struct List {
    Node* first;  // Ponteiro para o primeiro n� da lista
    Node* last;   // Ponteiro para o �ltimo n� da lista
    int size;     // Contador de n�s na lista para otimizar opera��es de tamanho

    // Construtor que inicializa uma lista vazia
    List() {
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    // M�todo para verificar se a lista est� vazia
    bool empty() {
        return first == nullptr;
    }

    // M�todo para adicionar um valor ao final da lista
    void pushBack(int value) {
        Node* newNode = new Node(value); // Cria um novo n� com o valor fornecido
        size++;
        if (empty()) {
            first = last = newNode;      // Define o novo n� como o primeiro e o �ltimo
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    // M�todo para inserir no final da lista o tamanho atual da lista
    void insertSizeAtEnd() {
        pushBack(size); // Insere o tamanho da lista como um novo elemento no final
    }

    // M�todo para inserir todos os n�meros de 1 at� N no final da lista
    void insertRange(int N) {
        for (int i = 1; i <= N; i++) { // Itera de 1 at� N
            pushBack(i);               // Insere cada n�mero ao final da lista
        }
    }

    // M�todo para remover os �ltimos N elementos da lista
    void removeLastN(int n) {
        if (n >= size) { // Se N � maior ou igual ao tamanho, esvazia a lista
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

    // M�todo auxiliar para remover o primeiro elemento da lista
    void popFront() {
        if (empty()) return;
        Node* toDelete = first;
        first = first->next;
        delete toDelete;
        size--;
        if (empty()) last = nullptr;
    }

    // M�todo para imprimir todos os elementos da lista
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

    cout << "Digite os valores para adicionar � lista:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> inputValue;
        l.pushBack(inputValue);
    }

    cout << "Lista antes das inser��es especiais: ";
    l.print();

    // Exemplo de uso do m�todo insertSizeAtEnd
    l.insertSizeAtEnd();
    cout << "Lista ap�s inserir o tamanho atual ao final: ";
    l.print();

    // Exemplo de uso do m�todo insertRange
    int rangeN;
    cout << "Digite o valor de N para inserir de 1 at� N: ";
    cin >> rangeN;
    l.insertRange(rangeN);
    cout << "Lista ap�s inserir todos os valores de 1 at� " << rangeN << ": ";
    l.print();

    return 0;
}

