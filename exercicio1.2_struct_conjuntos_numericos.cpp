#include <iostream>
using namespace std;

struct Conjunto {
    int elementos[20];
    int tam;
};

// Função para criar um conjunto vazio
void Criar_conj(Conjunto &conj) {
    conj.tam = 0; // conjunto começa com tamanho 0
}

// Função para ler os dados do conjunto
void Ler(Conjunto &conj) {
    int n;
    cout << "Quantos elementos deseja inserir no conjunto? (Máximo 20): ";
    cin >> n;

    if (n > 20) {
        cout << "O conjunto pode conter no máximo 20 elementos." << endl;
        return;
    }
    conj.tam = n;
    cout << "Digite os " << n << " elementos do conjunto: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> conj.elementos[i];
    }
}

// Função para a união de dois conjuntos
Conjunto Uniao(Conjunto &A, Conjunto &B) {
    Conjunto uniao;
    Criar_conj(uniao); // Inicializa a união como vazia

    // Adiciona todos os elementos de A no conjunto união
    for (int i = 0; i < A.tam; i++) {
        uniao.elementos[uniao.tam] = A.elementos[i];
        uniao.tam++; // Aumenta o tamanho do conjunto união
    }

    // Adiciona em união os elementos de B que não estão em A
    for (int i = 0; i < B.tam; i++) {
        bool encontrado = false; // Inicialmente, o elemento de B não foi encontrado em A
        for (int j = 0; j < A.tam; j++) {
            if (B.elementos[i] == A.elementos[j]) { // Se o elemento de B for igual a um de A, ele já está na união
                encontrado = true;
                break;
            }
        }
        if (!encontrado) { // Se o elemento de B não foi encontrado em A, adiciona ele na união
            uniao.elementos[uniao.tam] = B.elementos[i];
            uniao.tam++;
        }
    }

    return uniao;
}

// Função para a interseção de dois conjuntos
Conjunto Intersecao(Conjunto &A, Conjunto &B) {
    Conjunto intersecao;
    Criar_conj(intersecao); // Inicializa a interseção como vazia

    // Procura os elementos que estão tanto em A quanto em B
    for (int i = 0; i < A.tam; i++) {
        for (int j = 0; j < B.tam; j++) {
            if (A.elementos[i] == B.elementos[j]) { // Se o elemento de A estiver em B, adiciona na intersecao
                intersecao.elementos[intersecao.tam] = A.elementos[i];
                intersecao.tam++;
                break;
            }
        }
    }

    return intersecao;
}

// Função para imprimir os elementos de um conjunto
void Impressao(Conjunto &conj) {
    cout << "{ ";
    for (int i = 0; i < conj.tam; i++) {
        cout << conj.elementos[i];
        if (i < conj.tam - 1) { // Para não colocar vírgula depois do último elemento
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

int main() {
    Conjunto A, B, uniao, intersecao;
    int opcao;

    do {
        cout << "--- \nMENU ---" << endl;
        cout << "1. Criar conjunto A" << endl;
        cout << "2. Criar conjunto B" << endl;
        cout << "3. Fazer união de A e B" << endl;
        cout << "4. Fazer interseção de A e B" << endl;
        cout << "5. Imprimir conjunto A" << endl;
        cout << "6. Imprimir conjunto B" << endl;
        cout << "7. Sair" << endl;

        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                Ler(A);
                break;
            case 2:
                Ler(B);
                break;
            case 3:
                uniao = Uniao(A, B);
                cout << "União dos conjuntos A e B: ";
                Impressao(uniao);
                break;
            case 4:
                intersecao = Intersecao(A, B);
                cout << "Interseção dos conjuntos A e B: ";
                Impressao(intersecao);
                break;
            case 5:
                cout << "Conjunto A: ";
                Impressao(A);
                break;
            case 6:
                cout << "Conjunto B: ";
                Impressao(B);
                break;
            case 7:
                cout << "Encerrado" << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 7);

    return 0;
}
