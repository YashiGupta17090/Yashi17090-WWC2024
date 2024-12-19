//WAP on sum of natural number upto N
#include <iostream>
using namespace std;

int main() {
    int N, sum = 0;

    cout << "Enter a positive integer: ";
    cin >> N;

    if (N < 1) {
        cout << "Please enter a positive integer greater than 0.";
        return 1;
    }

    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    cout << "The sum of natural numbers up to " << N << " is: " << sum << endl;

    return 0;
}
