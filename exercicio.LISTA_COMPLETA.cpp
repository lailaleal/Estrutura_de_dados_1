#include <iostream>  // Inclui a biblioteca padrão de entrada e saída
using namespace std;  // Usa o namespace padrão para simplificar o uso de std

// Estrutura do nó para a lista encadeada
struct Node {
    int value;    // Armazena o valor do nó
    Node* next;   // Ponteiro para o próximo nó

    // Construtor padrão (sem parâmetros) que inicializa o nó com valor 0 e ponteiro nulo
    Node() {
        value = 0;
        next = NULL;
    }

    // Construtor que recebe um valor e inicializa o nó com esse valor e ponteiro nulo
    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

// Estrutura da lista encadeada
struct List {
    Node* inicio;  // Ponteiro para o primeiro nó da lista
    Node* fim;   // Ponteiro para o último nó da lista
    int c;        // Contador de elementos na lista

    // Construtor da lista, inicializa uma lista vazia
    List() {
        inicio = NULL;  // Nenhum nó no início
        fim = NULL;   // Nenhum nó no final
        c = 0;         // Contador de elementos começa em zero
    }

    // Método para verificar se a lista está vazia
    bool empty() {
        return inicio == NULL;  // Retorna true se o primeiro nó for nulo (lista vazia)
    }

    // Insere um valor no início da lista
    void pushInicio(int value) {
        Node *n = new Node(value);  // Cria um novo nó com o valor dado
        c++;  // Incrementa o contador de elementos
        if (empty()) {  // Caso a lista esteja vazia
            inicio = n;  // O novo nó será o primeiro
            fim = n;   // E também o último
            return;     // Sai do método
        }
        n->next = inicio;  // O próximo do novo nó aponta para o antigo primeiro
        inicio = n;        // Atualiza o primeiro para o novo nó
    }

    // Insere um valor no final da lista
    void pushFim(int value) {
        Node *n = new Node(value);  // Cria um novo nó com o valor dado
        c++;  // Incrementa o contador de elementos
        if (empty()) {  // Caso a lista esteja vazia
            inicio = n;  // O novo nó será o primeiro
            fim = n;   // E também o último
            return;     // Sai do método
        }
        fim->next = n;  // Atualiza o próximo do último nó para o novo nó
        fim = n;        // Atualiza o último nó para o novo nó
    }

    // Imprime todos os valores da lista
    void print() {
        Node* aux = inicio;  // Ponteiro auxiliar começa no primeiro nó
        while (aux != NULL) {  // Continua até o final da lista
            cout << aux->value << " -> ";  // Imprime o valor do nó atual
            aux = aux->next;  // Avança para o próximo nó
        }
        cout << "NULL" << endl;  // Indica o fim da lista com NULL
    }

    // Retorna o tamanho da lista em O(1)
    int size() {
        return c;  // Retorna o contador de elementos
    }

    // Remove o primeiro elemento da lista
    void removeInicio() {
        if (empty()) return;  // Se a lista estiver vazia, não faz nada
        if (c == 1) {  // Se a lista tiver apenas um elemento
            delete inicio;  // Deleta o único nó
            inicio = NULL;  // Define o primeiro como nulo
            fim = NULL;   // Define o último como nulo
            c = 0;         // Reseta o contador
            return;
        }
        Node* toDel = inicio;  // Armazena o primeiro nó para deletar
        inicio = inicio->next;  // Atualiza o primeiro para o próximo nó
        delete toDel;  // Deleta o nó antigo
        c--;  // Decrementa o contador
    }

    // Remove o último elemento da lista
    void removeFim() {
        if (empty()) return;  // Se a lista estiver vazia, não faz nada
        if (c == 1) {  // Se a lista tiver apenas um elemento
            delete inicio;  // Deleta o único nó
            inicio = NULL;  // Define o primeiro como nulo
            fim = NULL;   // Define o último como nulo
            c = 0;         // Reseta o contador
            return;
        }
        Node* toDel = fim;  // Armazena o último nó para deletar
        Node* aux = inicio;   // Ponteiro auxiliar para encontrar o penúltimo nó
        while (aux->next != fim) {  // Percorre até o penúltimo nó
            aux = aux->next;
        } // Caso o proximo seja igual ao fim
        fim = aux;  // Atualiza o último nó para o penúltimo
        fim->next = NULL;  // Define o próximo do último como NULL
        delete toDel;  // Deleta o nó antigo
        c--;  // Decrementa o contador
    }

    // Insere um valor em uma posição específica da lista // value = valor digitado, pos = posição na lista
    void insert(int value, int pos) {
        if (pos <= 0) {  // Caso a posição seja menor ou igual a 0
            pushInicio(value);  // Insere no início
            return;
        }
        if (pos >= c) {  // Caso a posição seja maior ou igual ao tamanho da lista
            pushFim(value);  // Insere no final
            return;
        }
        Node* aux = inicio;  // Ponteiro auxiliar para encontrar a posição desejada
        for (int i = 0; i < pos - 1; i++) {  // Avança até a posição anterior, começa na posição 0 e vai até chegar na posição anterior
            // na posição anterior, pq o aux-> next vai apontar para a posição onde iremos inserir.
            aux = aux->next; // Encontrou a posição anterior a posição desejada.
        }
        Node* n = new Node(value);  // Cria um novo nó com o valor dado
        n->next = aux->next;  // O próximo do novo nó é o próximo do auxiliar
        aux->next = n;  // Insere o novo nó na posição
        c++;  // Incrementa o contador
    }

    // Remove um nó que possui o valor especificado
    void remove(int value) {
        if (empty()) return;  // Primeiro, verifica se a lista está vazia usando a função empty(). Se estiver, a função termina imediatamente,
        //pois não há nada para remover.

        Node *aux = inicio;  // Define um ponteiro aux para o início da lista. Esse ponteiro é usado para percorrer cada nó da lista
        Node *prev = NULL;  // Declara prev, que aponta para o nó anterior ao aux. Inicialmente, é NULL porque aux começa no primeiro nó,
        // e não há nenhum nó antes dele.
        for (int i = 0; i < c; i++) {  // Inicia um loop para percorrer toda a lista. O loop usa c como limite, que é o contador do número de nós na lista.
            if (aux->value == value) {  // Verifica se o valor do nó atual (aux->value) é igual ao valor que queremos remover.
                if (prev == NULL) {  // Caso prev seja NULL, significa que o nó atual (aux) é o primeiro da lista.
                   removeInicio();  // Se for o primeiro, chama a função removeInicio() para removê-lo de maneira adequada.
                   // Se o nó a ser removido estiver no meio ou final da lista.
                } else { // Caso contrário, estamos em um nó interno ou final, e precisamos ajustá-lo manualmente
                    prev->next = aux->next;  // Atualiza o ponteiro next do nó anterior (prev) para apontar para o próximo nó de aux, "pulando" o nó atual.
                    delete aux;  // Remove o nó atual da memória para evitar vazamentos.
                    c--;  // Decrementa o contador c para refletir a remoção.
                    aux = prev;  // Define aux novamente para o nó anterior (prev) e continua o loop
                    // Ao deletar aux, o código define aux como prev para garantir que o próximo ciclo do for ocorra sem pular nenhum nó da lista.
                    // Se aux fosse simplesmente movido para aux->next logo após a remoção, o próximo nó após o que foi deletado seria ignorado no loop
                }
            }
            prev = aux;  // Define prev para o nó atual (aux), para que ele se torne o anterior no próximo ciclo.
            // No final de cada iteração, prev é atualizado para o valor de aux. Isso move prev para "uma posição atrás" de aux, de modo que no
            // próximo ciclo prev sempre será o nó anterior ao atual aux. Objetivo: Manter prev sincronizado com aux, para que prev aponte para o
            // nó correto ao pular um nó no caso de remoção.
            aux = aux->next;  // Avança aux para o próximo nó da lista, continuando a busca.
            // aux = aux->next; // Avança aux para o próximo nó da lista, continuando a busca.
    // Esse comando final move aux para o próximo nó da lista para que o loop possa continuar verificando cada nó.
    // Objetivo: Essa linha permite que o for percorra a lista de maneira sequencial.
        }
    }
};

int main() {
    List l;  // Cria uma nova lista

    l.pushInicio(10);  // Insere 10 no início da lista
    l.pushInicio(3);   // Insere 3 no início da lista
    l.pushFim(5);    // Insere 5 no final da lista

    l.removeFim();      // Remove o último elemento da lista

    l.print();  // Imprime todos os elementos da lista

    return 0;  // Fim do programa
}

