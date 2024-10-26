#include <iostream> // Inclui biblioteca padrão de entrada e saída

using namespace std; // Usa o namespace padrão para simplificar chamadas de funções (ex.: cout em vez de std::cout)

// Estrutura do nó individual da lista encadeada
struct Node {
    int value;        // Armazena o valor do nó
    Node* next;       // Ponteiro para o próximo nó na lista

    // Construtor que inicializa um nó com um valor dado
    Node(int val) {
        value = val;      // Atribui o valor recebido ao campo value do nó
        next = nullptr;   // Inicializa o ponteiro 'next' como nulo (último nó por padrão)
    }
};

// Estrutura da lista encadeada
struct List {
    Node* first;  // Ponteiro para o primeiro nó da lista
    Node* last;   // Ponteiro para o último nó da lista
    int size;     // Contador de nós na lista para otimizar operações de tamanho

    // Construtor que inicializa uma lista vazia
    List() {
        first = nullptr; // Primeiro nó é nulo, lista está vazia
        last = nullptr;  // Último nó é nulo, lista está vazia
        size = 0;        // Tamanho inicial da lista é zero
    }

    // Método para verificar se a lista está vazia
    bool empty() {
        return first == nullptr; // Retorna verdadeiro se o primeiro nó for nulo (lista vazia)
    }

    // Método para adicionar um valor ao final da lista
    void pushBack(int value) {
        Node* newNode = new Node(value); // Cria um novo nó com o valor fornecido
        size++;                          // Incrementa o contador de tamanho da lista
        if (empty()) {                   // Se a lista estiver vazia,
            first = last = newNode;      // Define o novo nó como o primeiro e o último
        } else {                         // Caso contrário,
            last->next = newNode;        // Aponta o último nó atual para o novo nó
            last = newNode;              // Atualiza o último nó para o novo nó
        }
    }

    // Método para remover os últimos N elementos da lista
    void removeLastN(int n) {
        // Se N for maior ou igual ao tamanho da lista, esvazia a lista inteira
        if (n >= size) {
            while (!empty()) { // Enquanto a lista não estiver vazia
                popFront();    // Remove o primeiro elemento repetidamente
            }
            return;            // Sai da função
        }

        // Calcula quantos elementos devem permanecer após a remoção
        int elementsToKeep = size - n;
        Node* current = first; // Começa do primeiro nó

        // Move o ponteiro 'current' até o nó que será o novo último da lista
        for (int i = 1; i < elementsToKeep; i++) {
            current = current->next; // Avança para o próximo nó até atingir a posição desejada
        }

        // Define os nós finais a serem removidos
        Node* toDelete = current->next; // Marca o nó após o 'current' para exclusão
        current->next = nullptr;        // Define o próximo de 'current' como nulo, finalizando a lista
        last = current;                 // Atualiza o último nó para o 'current'

        // Libera a memória dos nós removidos
        while (toDelete) {
            Node* next = toDelete->next; // Armazena o próximo nó antes de deletar
            delete toDelete;             // Deleta o nó atual
            toDelete = next;             // Move para o próximo nó a ser deletado
        }

        size = elementsToKeep;           // Atualiza o tamanho da lista
    }

    // Método auxiliar para remover o primeiro elemento da lista (usado ao esvaziar a lista)
    void popFront() {
        if (empty()) return;           // Se a lista está vazia, não faz nada
        Node* toDelete = first;         // Marca o primeiro nó para exclusão
        first = first->next;            // Move o ponteiro 'first' para o próximo nó
        delete toDelete;                // Deleta o nó anterior (agora fora da lista)
        size--;                         // Reduz o tamanho da lista
        if (empty()) last = nullptr;    // Se a lista ficou vazia, também zera o último nó
    }

    // Método para remover o segundo elemento da lista
    void removeSecond() {
        // Verifica se a lista possui pelo menos dois elementos
        if (size <= 1) {
            return; // Se a lista tem um ou nenhum elemento, não faz nada
        }

        // Marca o segundo nó para remoção
        Node* secondNode = first->next;

        // Conecta o primeiro nó ao nó que está após o segundo,
        // efetivamente removendo o segundo nó da lista
        first->next = secondNode->next;

        // Libera a memória do nó removido
        delete secondNode;

        // Reduz o tamanho da lista
        size--;
    }

    // Método para imprimir todos os elementos da lista
    void print() {
        Node* current = first;              // Inicia a partir do primeiro nó
        while (current) {                   // Enquanto houver nós,
            cout << current->value << " ";  // Imprime o valor do nó
            current = current->next;        // Avança para o próximo nó
        }
        cout << endl;                       // Nova linha após imprimir a lista
    }
};

// Função principal que interage com o usuário
int main() {
    List l;          // Cria uma nova lista encadeada
    int n, inputValue;

    // Solicita e lê a quantidade de valores a serem inseridos na lista
    cout << "Digite a quantidade de valores a inserir na lista: ";
    cin >> n;

    // Lê os valores e adiciona à lista
    cout << "Digite os valores para adicionar à lista:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> inputValue;      // Lê o valor
        l.pushBack(inputValue); // Adiciona ao final da lista
    }

    // Imprime a lista antes de qualquer remoção
    cout << "Lista original: ";
    l.print();

    // Remove o segundo elemento
    l.removeSecond();

    // Imprime a lista após remover o segundo elemento
    cout << "Lista apos remover o segundo elemento: ";
    l.print();

    int removeCount;
    // Solicita a quantidade de elementos finais a serem removidos e executa a remoção
    cout << "Digite quantos elementos finais deseja remover: ";
    cin >> removeCount;
    l.removeLastN(removeCount);

    // Imprime a lista após a remoção
    cout << "Lista apos remocao dos ultimos elementos: ";
    l.print();

    return 0; // Encerra o programa
}
