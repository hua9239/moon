#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char* argv[]) {
    // ???Z?h??
    int size;
    cin >> size;

    vector<int> score(size);
    for (int i = 0; i < score.size(); i++) {
        cin >> score[i];
    }

    int max = score[0], min = score[0];
    for (int i = 0; i < score.size(); i++) {
        if (max < score[i])
            max = score[i];
        if (min > score[i])
            min = score[i];
    }
    cout << max << " " << min << endl;
}
