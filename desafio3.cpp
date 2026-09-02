#include <iostream>
using namespace std;

int main(int n) {
    cin >> n;
    int total = 0;

    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            total += i;
        }
    }
/*
    while (n > 0) {
        if (n % 2 == 0) {
            total += n;
        }
        n--;
    }
*/  
    cout << total << endl;
    return 0;
}