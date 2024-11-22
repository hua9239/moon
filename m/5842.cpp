#include <iostream>
using namespace std;

// 2-3 ?G???}?C-?p??C??ǥͪ????????Z

int main(int argc, char* argv[]) {
    int Score[4][5];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            cin >> Score[i][j];

    float ans[4] = {};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            ans[i] += Score[i][j];

    for (int i = 0; i < 4; i++)
        cout << ans[i] / 5 << " ";
}
