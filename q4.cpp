#include <iostream>

using namespace std;

int myfib(const int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return myfib(n - 1) + myfib(n - 2);
}

void myfibseries(int n) {
    if (n == -1){
        return ;
    }

    myfibseries(n-1);
    cout<<myfib(n)<<",";
}

void myfibseriesR(int n) {
    if (n == -1){
        return ;
    }
    cout<<myfib(n)<<",";
    myfibseriesR(n-1);
}

int myfibsum(int n) {
    if (n==0){
        return myfib(n);
    }
    return myfibsum(n-1)+myfib(n);
}

int main(){
    cout <<"Please input a number:";
    int n;
    cin >> n;
    cout <<"myfibseries"<<endl;
    myfibseries(n);
    cout << endl;
    cout <<"myfibseriesR"<<endl;
    myfibseriesR(n);
    cout << endl;
    cout <<"myfibsum"<<endl;
    cout<<myfibsum(n);
    cout << endl;
}
