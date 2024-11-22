#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int A[100], B[100];
    int a_top = -1, b_top = -1;

    int N;
    cin >> N;  // 代表多少個指令

    for (int n = 0; n < N; n++) {
        int order;
        cin >> order;

        if (order == 1) {
            int X, Y;
            cin >> X >> Y;
            switch (X) {
                case 1:
                    A[++a_top] = Y;
                    break;
                case 2:
                    B[++b_top] = Y;
                    break;
            }
        }  // oreder = 1

        else if (order == 2) {
            int X;
            cin >> X;
            switch (X) {
                case 1:
                    a_top--;
                    break;
                case 2:
                    b_top--;
                    break;
            }
        }  // order = 2

        else if (order == 3) {
            int X;
            cin >> X;
            switch (X) {
                case 1:
                    cout << "A ";
                    for (int i = 0; i <= a_top; i++)
                        cout << A[i] << " ";
                    cout << endl;
                    break;
                case 2:
                    cout << "B ";
                    for (int i = 0; i <= b_top; i++)
                        cout << B[i] << " ";
                    cout << endl;
                    break;
            }
        }
    }
}
