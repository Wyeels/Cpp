#include <iostream>
using namespace std;

int main() {
    // aqui já crio as variáveis principais, bool praa definir se é primo ou não, e inteiro pra receber o valor.
    bool eOuNao = false;
    int primoOuNao;
    // receber o valor.
    cin >> primoOuNao;

    // aqui entramos em um dos códigos mais diferentes que você ja pode ter visto relacionado a esse tipo de dasafio, dos 5 que você me passou esse foi o mais complicado, e essa foi a única maneira que achei pra responder a tudo isso. Irei explicar com detalhes: Primeiramente, esse loop a seguir é o único e o principal loop do código, porque através dele que eu vou verificar se o número é primo ou não. 

    // Um número primo é um valor que só pode ser dividido por ele mesmo e por 1, a lógica do loop é exatamente essa: testar se o valor é divisível por algum número entre 2 e 9 (já que 1 tem que ser divisível obrigatoriamente, começamos pelo 2). Pra iniciar, como não existem números primos menores que 2, eu já faço essa verificação no inicio do loop, se o valor for menor que 2, ele já quebra o loop na hora e retorna false.
    
    // Se ele for divisivel (de maneira perfeita, resto da divisão == 0) por qualquer valor entre 2 e 9, e for diferente de algum desses valores, ele retorna true, caso contrário ele retorna false e já quebra o loop, confirmando que o número é primo. Caso ele resulte em true, o loop continua e na próxima vez que o loop rodar ele vai verificar que o valor de primo está como true, então ele é divisível por outros valores além dele mesmo e de 1, então ele seta o valor booleano como falso e quebra o loop. 

    for (int i = 2; i <= 9; i++) {
        if (primoOuNao < 2) {
            break;
        }

        if (primoOuNao % i == 0 && primoOuNao != i) {
            if (eOuNao) {
                eOuNao = false;
                break;
            }
            eOuNao = false;
            break;
        } else {
            eOuNao = true;
        }
    }

    // por fim, apenas a condição para mostrar na tela se o valor é primo ou não.

    if (eOuNao) {
        cout << "É primo" << endl;
    } else {
        cout << "Não é primo" << endl;
    }

    return 0;
}