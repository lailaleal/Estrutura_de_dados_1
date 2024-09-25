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

// Fun��o cadastrar funcion�rio

void Cadastro(Funcionario &f)
    {
    cout << "Nome: " << endl;
    cin.ignore(); // Limpa o buffer de entrada do cin
    getline(cin, f.nome); // Permite que o nome tenha espa�os, evitando looping
    cout << "Cargo: ";
    getline(cin, f.cargo); // Permite que o cargo tenha espa�os, evitando looping
    cout << "Sal�rio Base: " << endl;
    cin >> f.salBase;
    cout << "Benef�cios: " << endl;
    cin >> f.beneficios;
    cout << "Descontos: " << endl;
    cin >> f.descontos;

    // Calculo do sal�rio l�quido
    f.salLiquido = (f.salBase + f.beneficios) - f.descontos;
    }
// Fun��o Imprimir todos os funcion�rios cadastrados
void Impressao(Funcionario f[], int total)
    {
    for (int i = 0; i < total; i++)
        {
        cout << "\nFuncion�rio " << i + 1 << ":" << endl;
        cout << "Nome: " << f[i].nome << endl;
        cout << "Cargo: " << f[i].cargo << endl;
        cout << "Sal�rio Base: " << f[i].salBase << endl;
        cout << "Benef�cios: " << f[i].beneficios << endl;
        cout << "Descontos: " << f[i].descontos << endl;
        cout << "Sal�rio L�quido: " << f[i].salLiquido << endl;
        }
    }

// Fun��o M�dia Salarial

void Media(Funcionario f[], int total)
    {
    float somaSal = 0;
    for (int i = 0; i < total; i++)
        {
        somaSal += f[i].salLiquido; // Soma os sal�rios l�quidos
        }

    float media = somaSal / total; // Calcula a m�dia
    cout << "A m�dia salarial �: " << media << endl;
    }
// Fun��o maior sal�rio

void MaiorSalario(Funcionario f[], int total)
    {
    int iMaior = 0;


    for (int i = 1; i < total; i++)
        {
        if (f[i].salLiquido > f[iMaior].salLiquido)
        {
            iMaior = i; // Atualiza o �ndice do funcion�rio com maior sal�rio
        }
        }

    // Imprime o funcion�rio com o maior sal�rio
    cout << "Funcion�rio com o maior sal�rio:\n";
    cout << "Nome: " << f[iMaior].nome << endl;
    cout << "Sal�rio L�quido: " << f[iMaior].salLiquido << endl;
    }
int main() {
    Funcionario f[10]; // M�ximo de 10 funcion�rios
    int total = 0;
    int opcao;

    do
        {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Cadastrar funcion�rio" << endl;
        cout << "2. Mostrar funcion�rios" << endl;
        cout << "3. Calcular m�dia salarial" << endl;
        cout << "4. Exibir funcion�rio com maior sal�rio" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma op��o: ";
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
                    cout << "Limite de funcion�rios atingido!" << endl;
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
                cout << "Op��o inv�lida!" << endl;
        }
        } while (opcao != 5);

    return 0;
}

