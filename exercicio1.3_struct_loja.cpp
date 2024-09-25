#include <iostream>
#include <string>
using namespace std;

struct Funcionario
    {
    string nome;
    string cargo;
    float salBase;
    float beneficios;
    float descontos;
    float salLiquido;
    };

// Função cadastrar funcionário

void Cadastro(Funcionario &f)
    {
    cout << "Nome: " << endl;
    cin.ignore(); // Limpa o buffer de entrada do cin
    getline(cin, f.nome); // Permite que o nome tenha espaços, evitando looping
    cout << "Cargo: ";
    getline(cin, f.cargo); // Permite que o cargo tenha espaços, evitando looping
    cout << "Salário Base: " << endl;
    cin >> f.salBase;
    cout << "Benefícios: " << endl;
    cin >> f.beneficios;
    cout << "Descontos: " << endl;
    cin >> f.descontos;

    // Calculo do salário líquido
    f.salLiquido = (f.salBase + f.beneficios) - f.descontos;
    }
// Função Imprimir todos os funcionários cadastrados
void Impressao(Funcionario f[], int total)
    {
    for (int i = 0; i < total; i++)
        {
        cout << "\nFuncionário " << i + 1 << ":" << endl;
        cout << "Nome: " << f[i].nome << endl;
        cout << "Cargo: " << f[i].cargo << endl;
        cout << "Salário Base: " << f[i].salBase << endl;
        cout << "Benefícios: " << f[i].beneficios << endl;
        cout << "Descontos: " << f[i].descontos << endl;
        cout << "Salário Líquido: " << f[i].salLiquido << endl;
        }
    }

// Função Média Salarial

void Media(Funcionario f[], int total)
    {
    float somaSal = 0;
    for (int i = 0; i < total; i++)
        {
        somaSal += f[i].salLiquido; // Soma os salários líquidos
        }

    float media = somaSal / total; // Calcula a média
    cout << "A média salarial é: " << media << endl;
    }
// Função maior salário

void MaiorSalario(Funcionario f[], int total)
    {
    int iMaior = 0;


    for (int i = 1; i < total; i++)
        {
        if (f[i].salLiquido > f[iMaior].salLiquido)
        {
            iMaior = i; // Atualiza o índice do funcionário com maior salário
        }
        }

    // Imprime o funcionário com o maior salário
    cout << "Funcionário com o maior salário:\n";
    cout << "Nome: " << f[iMaior].nome << endl;
    cout << "Salário Líquido: " << f[iMaior].salLiquido << endl;
    }
int main() {
    Funcionario f[10]; // Máximo de 10 funcionários
    int total = 0;
    int opcao;

    do
        {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Cadastrar funcionário" << endl;
        cout << "2. Mostrar funcionários" << endl;
        cout << "3. Calcular média salarial" << endl;
        cout << "4. Exibir funcionário com maior salário" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch(opcao)
        {
            case 1:
                if (total < 10)
                    {
                    Cadastro(f[total]);
                    total++;
                    } else
                    {
                    cout << "Limite de funcionários atingido!" << endl;
                    }
                break;
            case 2:
                Impressao(f, total);
                break;
            case 3:
                Media(f, total);
                break;
            case 4:
                MaiorSalario(f, total);
                break;
            case 5:
                cout << "Encerrado" << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
        } while (opcao != 5);

    return 0;
}

