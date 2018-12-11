#include <iostream>

using namespace std;

void printdivisors(int x) {
    // visit each possible divisors and test them
    for (int i = 1; i * 2 <= x; i++) {
        // if true print
        if (x % i == 0) {
            cout << i << ",";
        }
    }
}

int sumdivisors(int x) {
    int result = 0;
    // visit each possible divisors and test them
    for (int i = 1; i * 2 <= x; i++) {
        // if true add to result
        if (x % i == 0) {
            result += i;
        }
    }
    return result;
}

void allperfects(int low, int high) {
    // from low to hight
    for(int i=low;i<=high;i++){
        // if sum of divisors equal to itself
        if(sumdivisors(i) == i){
            cout << i << endl;
        }
    }
}

int main(){
    int n;
    cout <<"please input a number n:";
    cin >> n;
    cout <<"divisors:";
    printdivisors(n);
    cout << endl  <<"sum of divisors:"<<sumdivisors(n)<<endl;
    cout <<"please input lower number an upper number:";
    int lower,upper;
    cin>>lower>>upper;
    cout << "perfect numbers:"<<endl;
    allperfects(lower,upper);
}
