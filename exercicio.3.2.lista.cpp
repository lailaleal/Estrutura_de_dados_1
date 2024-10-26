#include <iostream> // Inclui biblioteca padr�o de entrada e sa�da

using namespace std; // Usa o namespace padr�o para simplificar chamadas de fun��es (ex.: cout em vez de std::cout)

// Estrutura do n� individual da lista encadeada
struct Node {
    int value;        // Armazena o valor do n�
    Node* next;       // Ponteiro para o pr�ximo n� na lista

    // Construtor que inicializa um n� com um valor dado
    Node(int val) {
        value = val;      // Atribui o valor recebido ao campo value do n�
        next = nullptr;   // Inicializa o ponteiro 'next' como nulo (�ltimo n� por padr�o)
    }
};

// Estrutura da lista encadeada
struct List {
    Node* first;  // Ponteiro para o primeiro n� da lista
    Node* last;   // Ponteiro para o �ltimo n� da lista
    int size;     // Contador de n�s na lista para otimizar opera��es de tamanho

    // Construtor que inicializa uma lista vazia
    List() {
        first = nullptr; // Primeiro n� � nulo, lista est� vazia
        last = nullptr;  // �ltimo n� � nulo, lista est� vazia
        size = 0;        // Tamanho inicial da lista � zero
    }

    // M�todo para verificar se a lista est� vazia
    bool empty() {
        return first == nullptr; // Retorna verdadeiro se o primeiro n� for nulo (lista vazia)
    }

    // M�todo para adicionar um valor ao final da lista
    void pushBack(int value) {
        Node* newNode = new Node(value); // Cria um novo n� com o valor fornecido
        size++;                          // Incrementa o contador de tamanho da lista
        if (empty()) {                   // Se a lista estiver vazia,
            first = last = newNode;      // Define o novo n� como o primeiro e o �ltimo
        } else {                         // Caso contr�rio,
            last->next = newNode;        // Aponta o �ltimo n� atual para o novo n�
            last = newNode;              // Atualiza o �ltimo n� para o novo n�
        }
    }

    // M�todo para remover os �ltimos N elementos da lista
    void removeLastN(int n) {
        // Se N for maior ou igual ao tamanho da lista, esvazia a lista inteira
        if (n >= size) {
            while (!empty()) { // Enquanto a lista n�o estiver vazia
                popFront();    // Remove o primeiro elemento repetidamente
            }
            return;            // Sai da fun��o
        }

        // Calcula quantos elementos devem permanecer ap�s a remo��o
        int elementsToKeep = size - n;
        Node* current = first; // Come�a do primeiro n�

        // Move o ponteiro 'current' at� o n� que ser� o novo �ltimo da lista
        for (int i = 1; i < elementsToKeep; i++) {
            current = current->next; // Avan�a para o pr�ximo n� at� atingir a posi��o desejada
        }

        // Define os n�s finais a serem removidos
        Node* toDelete = current->next; // Marca o n� ap�s o 'current' para exclus�o
        current->next = nullptr;        // Define o pr�ximo de 'current' como nulo, finalizando a lista
        last = current;                 // Atualiza o �ltimo n� para o 'current'

        // Libera a mem�ria dos n�s removidos
        while (toDelete) {
            Node* next = toDelete->next; // Armazena o pr�ximo n� antes de deletar
            delete toDelete;             // Deleta o n� atual
            toDelete = next;             // Move para o pr�ximo n� a ser deletado
        }

        size = elementsToKeep;           // Atualiza o tamanho da lista
    }

    // M�todo auxiliar para remover o primeiro elemento da lista (usado ao esvaziar a lista)
    void popFront() {
        if (empty()) return;           // Se a lista est� vazia, n�o faz nada
        Node* toDelete = first;         // Marca o primeiro n� para exclus�o
        first = first->next;            // Move o ponteiro 'first' para o pr�ximo n�
        delete toDelete;                // Deleta o n� anterior (agora fora da lista)
        size--;                         // Reduz o tamanho da lista
        if (empty()) last = nullptr;    // Se a lista ficou vazia, tamb�m zera o �ltimo n�
    }

    // M�todo para remover o segundo elemento da lista
    void removeSecond() {
        // Verifica se a lista possui pelo menos dois elementos
        if (size <= 1) {
            return; // Se a lista tem um ou nenhum elemento, n�o faz nada
        }

        // Marca o segundo n� para remo��o
        Node* secondNode = first->next;

        // Conecta o primeiro n� ao n� que est� ap�s o segundo,
        // efetivamente removendo o segundo n� da lista
        first->next = secondNode->next;

        // Libera a mem�ria do n� removido
        delete secondNode;

        // Reduz o tamanho da lista
        size--;
    }

    // M�todo para imprimir todos os elementos da lista
    void print() {
        Node* current = first;              // Inicia a partir do primeiro n�
        while (current) {                   // Enquanto houver n�s,
            cout << current->value << " ";  // Imprime o valor do n�
            current = current->next;        // Avan�a para o pr�ximo n�
        }
        cout << endl;                       // Nova linha ap�s imprimir a lista
    }
};

// Fun��o principal que interage com o usu�rio
int main() {
    List l;          // Cria uma nova lista encadeada
    int n, inputValue;

    // Solicita e l� a quantidade de valores a serem inseridos na lista
    cout << "Digite a quantidade de valores a inserir na lista: ";
    cin >> n;

    // L� os valores e adiciona � lista
    cout << "Digite os valores para adicionar � lista:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> inputValue;      // L� o valor
        l.pushBack(inputValue); // Adiciona ao final da lista
    }

    // Imprime a lista antes de qualquer remo��o
    cout << "Lista original: ";
    l.print();

    // Remove o segundo elemento
    l.removeSecond();

    // Imprime a lista ap�s remover o segundo elemento
    cout << "Lista apos remover o segundo elemento: ";
    l.print();

    int removeCount;
    // Solicita a quantidade de elementos finais a serem removidos e executa a remo��o
    cout << "Digite quantos elementos finais deseja remover: ";
    cin >> removeCount;
    l.removeLastN(removeCount);

    // Imprime a lista ap�s a remo��o
    cout << "Lista apos remocao dos ultimos elementos: ";
    l.print();

    return 0; // Encerra o programa
}
