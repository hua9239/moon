#include <iostream>
using namespace std;

//  3-5 ???j?禡?p?ⶥ?? //

int fact(int n) {
    if (n >= 1)
        return fact(n - 1) * n;
    else
        return 1;
}

int main(int argc, char* argv[]) {
    int input;
    cin >> input;

    cout << fact(input);
}