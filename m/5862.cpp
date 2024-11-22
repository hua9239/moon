#include <iostream>
using namespace std;

// 3-7 ?̤j???]?? //

int GCD(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return GCD(b, a % b);
}

int main(int argc, char* argv[]) {
    int a, b;
    cin >> a >> b;

    cout << GCD(a, b);
}
