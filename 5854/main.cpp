#include <iostream>
using namespace std;

// 2-12-2 ?W?T???x?}?]?H?欰?D?^

int main(int argc, char* argv[]) {
    int Array_Data[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> Array_Data[i][j];

    int Array_Ans[15] = {};
    int count = -1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j <= i; j++)
            Array_Ans[++count] = Array_Data[j][i];

    for (int i = 0; i < 15; i++)
        cout << Array_Ans[i] << " ";
}