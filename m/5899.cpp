#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int n;
    cin >> n;

    int Polynomial[151] = {};

    // 碰到0就結束
    while (n != 0) {
        for (int i = 0; i < n / 2; i++) {
            int ai, bi;
            cin >> ai >> bi;

            Polynomial[ai] += bi;
        }

        cin >> n;
    }

    bool first = false;
    for (int i = 150; i >= 0; i--) {
        if (Polynomial[i] != 0) {
            if (Polynomial[i] > 0 && first == true)
                cout << "+";

            first = true;
            if (i == 0)
                cout << Polynomial[i];
            else if (Polynomial[i] == 1)
                cout << "x^" << i;
            else if (Polynomial[i] == -1)
                cout << "-x^" << i;
            else {
                if (i != 1)
                    cout << Polynomial[i] << "x^" << i;
                else
                    cout << Polynomial[i] << "x";
            }
        }
    }
}
