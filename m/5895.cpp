#include <iomanip>
#include <iostream>
using namespace std;

// 期中考A-1 二維陣列 Two-Dimensional Array //

int main() {
    // 4 * 5 的學生資料檔
    int Score[4][5] = {};

    float TotalSub[5] = {};            // 科目總分
    float Total_StudentScore[4] = {};  //學生分數總分

    // 輸入
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            cin >> Score[i][j];

    // 將分數加總
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            TotalSub[j] += Score[i][j];

    cout << fixed << setprecision(1);

    // 總分除予人數
    for (int i = 0; i < 5; i++)
        cout << TotalSub[i] / 4 << " ";
    cout << endl;

    // 找尋學生最大平均分數
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            Total_StudentScore[i] += Score[i][j];

    int min_StudentScore = Total_StudentScore[0];
    for (int i = 0; i < 4; i++)
        if (min_StudentScore > Total_StudentScore[i])
            min_StudentScore = Total_StudentScore[i];

    cout << min_StudentScore / 5;
}

/*

65 85 78 75 69
66 55 52 92 47
75 99 63 73 86
77 88 99 91 100
85 87 90 94 63
91 62 64 78 86

*/
