#include <iomanip>
#include <iostream>
using namespace std;

// ??????A-1 ?G???}?C Two-Dimensional Array //

int main() {
    // 6 * 5 ???ǥ͸????
    int Score[6][5] = {};

    float TotalSub[5] = {};            // ????`??
    float Total_StudentScore[6] = {};  //?ǥͤ????`??

    // ??J
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 5; j++)
            cin >> Score[i][j];

    // ?N???ƥ[?`
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 5; j++)
            TotalSub[j] += Score[i][j];

    cout << fixed << setprecision(1);

    // ?`???????H??
    for (int i = 0; i < 5; i++)
        cout << TotalSub[i] / 6 << " ";
    cout << endl;

    // ??M?ǥͳ̤j????????
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 5; j++)
            Total_StudentScore[i] += Score[i][j];

    int max_StudentScore = Total_StudentScore[0];
    for (int i = 0; i < 6; i++)
        if (max_StudentScore < Total_StudentScore[i])
            max_StudentScore = Total_StudentScore[i];

    cout << max_StudentScore / 5;
}

/*

65 85 78 75 69
66 55 52 92 47
75 99 63 73 86
77 88 99 91 100
85 87 90 94 63
91 62 64 78 86

*/