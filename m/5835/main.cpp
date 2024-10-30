#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char* argv[]) {
    // 成績多寡
    int size;
    cin >> size;

    vector<int> score(size);
    float average = 0;
    for (int i = 0; i < score.size(); i++) {
        cin >> score[i];
        average += score[i];
    }
    average /= score.size();
    (average >= 60) ? (cout << "及格") : (cout << "不及格");

    /*
    if (average >= 60)
        cout << "及格";
    else
        cout << "不及格";
    */

    return 0;
}