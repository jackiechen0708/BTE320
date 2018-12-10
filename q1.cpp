// 1.(a) following functions get the binary representation of a positive integer or zero
// and the decimal representation of a negative integer

// 1.(b) whoknows(2) = 10
//       whoknows(15) = 1111
//       whoknows(-3) = -3
#include <iostream>

using namespace std;
// 1.(c)

void digitize(int x, bool reverse) {
    // if x < 0 then make it positive
    if (x < 0) {
        x = -x;
    }
    // not reverse case
    if (!reverse) {
        // keep getting the last digits
        while (x > 0) {
            cout << x % 10 << endl;
            x /= 10;
        }
    }
    // reverse case
    else {
        // first get the reverse number
        int num = 0;
        while (x > 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        // keep getting the last digits
        while (num > 0) {
            cout << num % 10 << endl;
            num /= 10;
        }
    }
}

// 1.(d)
void reverse(int x) {
    // if x < 0 then make it positive
    if (x < 0) {
        x = -x;
    }
    // base case, if x < 10 then the reverse number is itself
    if (x < 10) {
        cout << x;
    }
    // otherwise the reverse number is the "last digit" + reverse of the former digits
    else {
        cout << x % 10;
        reverse(x / 10);
    }
}

//int main() {
//    reverse(12345);
//    return 0;
//}

