#include <iostream>
using namespace std;

int main() {
    // Crio as variáveis que irão protagonizar o programa, inicializando apenas a meddia que será somado os valores de todos os itens do array. 
    int valores[5];
    int maior;
    int menor;
    int media = 0;

    // crio o loop para adicionar os valores do array.

    for (int i = 0; i < 5; i++) {
        cin >> valores[i];
    }

    // crio o primeiro loop para encontrar a média.

    for (int i = 0; i < 5; i++) {
        media += valores[i];
    }

    // agora o loop duplo para encontrar o menor valor.

    for (int i = 0; i < 5; i++) {
        bool controle = false;
        for (int x = 0; x < 5; x++) {
            if (valores[i] <= valores[x]) {
                controle = true;
                continue;
            } else {
                controle = false;
                break;
            }
        }
        if (controle) {
            menor = valores[i];
            break;
        }
    }

    // agora o loop duplo para encontrar o maior valor.

    for (int i = 0; i < 5; i++) {
        bool controle = false;
        for (int x = 0; x < 5; x++) {
            if (valores[i] >= valores[x]) {
                controle = true;
                continue;
            } else {
                controle = false;
                break;
            }
        }
        if (controle) {
            maior = valores[i];
            break;
        }
    }

    // por fim as saídas pedidas:

    cout << maior << endl << menor << endl << media/5 << endl;

    return 0;
}