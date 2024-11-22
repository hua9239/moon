#include <iostream>
using namespace std;

// 2-6-1 ?G???}?C??@???}?C(?H?C???D)

int main(int argc, char* argv[]) {
    int Array_Data[3][5];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            cin >> Array_Data[i][j];

    int Array_Ans[15];
    for (int i = 0; i < 15; i++) {
        Array_Ans[i] = Array_Data[i / 5][i % 5];
    }

    for (int i = 0; i < 15; i++) {
        cout << Array_Ans[i] << " ";
    }
}
