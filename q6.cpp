#include <iostream>

using namespace std;
int array[10];

void search(int n) {
    for (int i = 0; i < 10; i++) {
        if (array[i] == n) {
            cout << "Position:" << i << " occurs " << n << endl;
        }
    }
}

int main() {

    int tmp;
    for (int i = 0; i < 10; i++) {
        cin >> tmp;
        array[i] = tmp;
    }
    search(2);
}