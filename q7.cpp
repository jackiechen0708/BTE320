#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int random_in_range(int min, int max) //range : [min, max]
{
    static bool first = true;
    if (first) {
        srand((int) time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (max - min);
}

int main() {
    int min, max;
    cout << "Enter min of range" << endl;
    cin >> min;
    cout << "Enter max of range" << endl;
    cin >> max;
    int to_guess = random_in_range(min, max);
    int guess_times = 0;
    cout << "Guess a number between " << min << " and " << max << endl;
    int guessed;
    while (guess_times < 3) {
        cout << "Guess a Number:" << endl;
        cin >> guessed;
        if (guessed < to_guess) {
            cout << "You went too low" << endl;
        } else if (guessed > to_guess) {
            cout << "You went too high" << endl;
        } else {
            cout << "You got it!" << endl;
            break;
        }
        guess_times += 1;
    }
}
