#include <iostream>
#include <string>
#include <limits>  // Para limpar o buffer de entrada
using namespace std;

// Classe que contém as funções relacionadas à verificação da letra 'a'
class LetterChecker {
public:
    // Função que verifica se a letra 'a' (maiúscula ou minúscula) existe na string
    bool hasLetterA(const string& str) {
        for (char ch : str) {
            if (ch == 'a' || ch == 'A') {
                return true;
            }
        }
        return false;
    }

    // Função que conta quantas vezes a letra 'a' (maiúscula ou minúscula) aparece na string
    int countLetterA(const string& str) {
        int count = 0;
        for (char ch : str) {
            if (ch == 'a' || ch == 'A') {
                count++;
            }
        }
        return count;
    }

    // Função para exibir o resultado da verificação e contagem
    void checkAndDisplay(const string& str) {
        if (hasLetterA(str)) {
            int count = countLetterA(str);
            cout << "A string contém a letra 'a' ou 'A'." << endl;
            cout << "Ela aparece " << count << " vez(es) na string." << endl;
        } else {
            cout << "A string NÃO contém a letra 'a' ou 'A'." << endl;
        }
    }
};

// Classe que contém funções para validação de entrada
class InputValidator {
public:
    // Função para capturar uma string válida
    string getValidString() {
        string input;
        cout << "Informe uma string (ou digite 'sair' para encerrar): ";
        getline(cin, input);  // Captura a string do usuário corretamente
        return input;
    }
};

// Função principal
int main() {
    LetterChecker letterChecker;
    InputValidator validator;

    string input;

    // Loop para verificar várias strings até o usuário digitar 'sair'
    while (true) {
        // Obtém uma string válida do usuário
        input = validator.getValidString();

        // Verifica se o usuário digitou 'sair' para encerrar o programa
        if (input == "sair") {
            cout << "Encerrando o programa..." << endl;
            break;
        }

        // Verifica se a string contém a letra 'a' ou 'A' e exibe o resultado
        letterChecker.checkAndDisplay(input);
    }

    return 0;
}
