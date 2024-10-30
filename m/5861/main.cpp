#include <iostream>
using namespace std;

// 3-6 ?O???? //

int Fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fib(n - 2) + Fib(n - 1);
}

int main(int argc, char* argv[]) {
    int input;
    cin >> input;

    cout << Fib(input);
}