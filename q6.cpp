#include <iostream>

using namespace std;
int array[10];

int search(int n) {
    int result = 0;
    for (int i = 0; i < 10; i++) {
        if (array[i] == n) {
            //cout << "Position:" << i << " occurs " << n << endl;
            result += 1;
        }
    }
    return result;
}

int main() {

    int tmp;
    cout <<"Please input 10 numbers:"<<endl;
    for (int i = 0; i < 10; i++) {
        cin >> tmp;
        array[i] = tmp;
    }
    cout <<"Please input the number to search"<<endl;
    cin >> tmp;
    cout <<"number " << tmp <<" occurs "<<search(tmp)<<" times"<<endl;
}
