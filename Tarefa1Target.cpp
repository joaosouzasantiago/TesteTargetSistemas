#include <iostream>
#include <limits>  // Para limpar o buffer de entrada
using namespace std;

// Classe que contém as funções relacionadas à sequência de Fibonacci
class Fibonacci {
public:
    // Função que verifica se um número pertence à sequência de Fibonacci
    bool isFibonacci(int number) {
        int a = 0, b = 1, next = 0;

        // Se o número for 0 ou 1, já pertence à sequência de Fibonacci
        if (number == 0 || number == 1) {
            return true;
        }

        // Gera a sequência até que o próximo número ultrapasse o valor informado
        while (next < number) {
            next = a + b;
            a = b;
            b = next;
            if (next == number) {
                return true;
            }
        }

        // Se sair do laço, o número não pertence à sequência
        return false;
    }

    // Função para exibir o resultado da verificação
    void checkAndDisplay(int number) {
        if (isFibonacci(number)) {
            cout << "O número " << number << " pertence à sequência de Fibonacci." << endl;
        } else {
            cout << "O número " << number << " NÃO pertence à sequência de Fibonacci." << endl;
        }
    }
};

// Classe que contém funções para validação de entrada
class InputValidator {
public:
    // Função para capturar uma entrada de número válida
    int getValidNumber() {
        int num;
        cout << "Informe um número (-99 para encerrar): ";

        // Verifica se a entrada é válida (um número inteiro)
        while (!(cin >> num)) {
            // Limpa o erro e o buffer de entrada
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Informa ao usuário que a entrada foi inválida
            cout << "Entrada inválida! Por favor, insira um número válido (-99 para encerrar): ";
        }
        return num;
    }
};

// Função principal
int main() {
    Fibonacci fibonacci;
    InputValidator validator;

    int num = 0;

    // Loop para verificar vários números até o usuário digitar -99
    while (num != -99) {
        // Obtém um número válido do usuário
        num = validator.getValidNumber();

        // Verifica se o número é -99 para encerrar o programa
        if (num == -99) {
            cout << "Encerrando o programa..." << endl;
            break;
        }

        // Verifica se o número pertence à sequência de Fibonacci
        fibonacci.checkAndDisplay(num);
    }

    return 0;
}
