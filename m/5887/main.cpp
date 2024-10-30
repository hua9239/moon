#include <iostream>
#include<vector>
using namespace std;

void rescuing_wizard_bear(vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        for (int j = 0; j < arr[i].size(); ++j)
            cout << arr[i][j] << " ";
}

void information_gathering(vector<vector<int>>& a, vector<vector<int>>& b) {
    int count = 0;
    b[count][0] = a.size();
    b[count][1] = a[0].size();
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[0].size(); ++j) {
            if (a[i][j] != 0) {
                b.push_back(vector<int>(3));
                b[++count][0] = i;
                b[count][1] = j;
                b[count][2] = a[i][j];
            }
        }
    b[0][2] = count;
}

void compress_init(vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        for (int j = 0; j < arr[i].size(); ++j)
            cin >> arr[i][j];
}

int main(int argc, char* argv[]) {
    int space_r, space_c;
    cin >> space_r >> space_c;
    vector<vector<int>> space(space_r, vector<int>(space_c, 0));

    //---changeable---//
    vector<vector<int>> tuple3(1, vector<int>(3));

    compress_init(space);
    information_gathering(space, tuple3);
    rescuing_wizard_bear(tuple3);
}