#include <iostream>
using namespace std;

int main() {
    int Array_Data[15];
    for (int i = 0; i < 15; i++)
        cin >> Array_Data[i];

    int Array_Ans[3][5];
    for (int i = 0; i < 15; i++) {
        Array_Ans[i / 5][i % 5] = Array_Data[i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++)
            cout << Array_Ans[i][j] << " ";
        cout << endl;
    }
}