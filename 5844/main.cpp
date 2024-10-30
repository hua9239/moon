#include <iostream>
using namespace std;

// 2-5 三維陣列-計算總成績

int main(int argc, char* argv[]) {
    int Score[3][4][5];
    for (int k = 0; k < 3; k++)
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 5; j++)
                cin >> Score[k][i][j];

    int student[4] = {}, subject[5] = {};
    for (int k = 0; k < 3; k++)
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 5; j++) {
                student[i] += Score[k][i][j];
                subject[j] += Score[k][i][j];
            }

    cout << "同學總成績：";
    for (int i = 0; i < 4; i++)
        cout << student[i] << " ";

    cout << "科目總成績：";
    for (int i = 0; i < 5; i++)
        cout << subject[i] << " ";
}