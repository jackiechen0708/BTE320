#include <iostream>
using namespace std;
void printZeros(int n){
    // base case return
    if (n == 0){
        return ;
    }
    // print one 0
    cout<<0;
    // print n-1 0
    printZeros(n-1);
}

void printZPattern(int n){
    // base case return
    if(n==0){
        return;
    }
    // print one row 0s
    printZeros(n);
    cout<<endl;
    // print n-1 row 0s
    printZPattern(n-1);
}

void printZPattern2(int n){
    // base case print 1 zero
    if(n==1){
        printZeros(n);
        return;
    }
    // print n zeros in one row
    printZeros(n);
    cout<<endl;
    // print ZPattern2
    printZPattern2(n-1);
    cout<<endl;
    // print n zeros in one row
    printZeros(n);
}

//int main(){
////    printZeros(4);
////    printZPattern(4);
////    printZPattern2(3);
//}