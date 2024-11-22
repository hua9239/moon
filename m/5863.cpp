#include <iostream>
using namespace std;

void Towers(int n, char a, char b, char c) {
    if (n == 1)
        cout << "Move disk " << n << " from " << a << " to " << c << endl;
    else {
        Towers(n - 1, a, c, b);
        cout << "Move disk " << n << " from " << a << " to " << c << endl;
        Towers(n - 1, b, a, c);
    }
}

int main(int argc, char* argv[]) {
    int disk;
    cin >> disk;

    Towers(disk, 'A', 'B', 'C');
}
