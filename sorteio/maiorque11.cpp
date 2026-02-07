#include <iostream>
using namespace std;


int main() {
    int n;
cin >> n;

int anterior, atual = 1, maior = 1;
cin >> anterior;

for (int i = 1; i < n; i++) {
    int x;
    cin >> x;

    if (x > anterior) {
        atual++;
    } else {
        atual = 1;
    }

    if (atual > maior) {
        maior = atual;
    }

    anterior = x;
}

cout << maior << endl;

}