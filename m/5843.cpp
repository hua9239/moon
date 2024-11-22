#include <iostream>
using namespace std;

// 2-4 �G���}�C-�p��C�@��ت���������

int main(int argc, char* argv[]) {
    int Score[4][5];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            cin >> Score[i][j];

    float ans[5] = {};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            ans[j] += Score[i][j];

    for (int i = 0; i < 5; i++)
        cout << ans[i] / 4 << " ";
}
