#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    int Score[6], total = 0;
    for (int i = 0; i < 6; i++) {
        cin >> Score[i];
        total += Score[i];
    }
    cout << total;
}
