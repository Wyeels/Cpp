#include <iostream>
using namespace std;

int main(int nota) {
    cin >> nota;
    // Sei que não seria necessario colocar esse cin já que o código já vai esperar um parâmetro "nota", mas mesmo assim resolvi colocar pra variar. Sei que normalmente ao usar parâmetros em funções, é porque ela será usada outras vezes, e que eu também poderia criar a variável normalmente no código, mas novamente, quis deixar claro que sei a diferença entre a variável como parâmetro de função (onde eu não preciso adicionar uma entrada já que ela vem de outra parte do código ou é chamada para realizar determinada tarefa), e uma variável local que só irá servir para aquela função em específico.
    if (nota >= 7) {
        cout << "Aprovado" << endl;
    } else if (nota > 5) {
        cout << "Recuperação" << endl;
    } else {
        cout << "Reprovado" << endl;
    }

    return 0;
}