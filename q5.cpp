//5.(a) (1)first we move the top count-1 disks from needle1 to needle2
//      (2)then we move the last disk from needle1 to needle3
//      (3)finally we move the all count-1 disks from needle2 to needle3
//      notice that step(1) and step(3) are sub problems of hanoi,
//      thus we can solve them recursively using steps (1) ~ (3)


#include <iostream>

using namespace std;

//prototype
void moveDisks(int count, int needle1, int needle3, int needle2, int times);
bool flag = true;
//main
int main() {
    cout << "Moves for 3 disk problem." << endl;
    moveDisks(5, 1, 3, 2, 0);
    return 0;
}

//tower of hanoi
void moveDisks(int count, int needle1, int needle3, int needle2, int times) {
    if (count > 0) {
        times = times * 2 + 1;
        moveDisks(count - 1, needle1, needle2, needle3, times);
        cout << "Move disk " << count << " from " << needle1
             << " to " << needle3 << "." << endl;
        moveDisks(count - 1, needle2, needle3, needle1, times);
    } else {
        if (flag) {
            cout << times << endl;
            flag = false;
        }
    }
}

