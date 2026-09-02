// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int>list1(2);
    vector<int>list2(2);
    for (int i = 0; i < 2; i++) {
      cin >> list1[i];
    }
    for (int i = 0; i < 2; i++) {
      cin >> list2[i];
    }

    
    vector<int>final(50);
    for (int i = 0; i < 50; i++) {
      for (int c = 0; c < 50; c++) {
        if (list1[i] == c || list2[i] == c) {
        final[c] = i;
        }
      }
  }

  for (int i = 0; i < 4; i++) {
    cout << final[i] << endl;
  }
        
  return 0;
}