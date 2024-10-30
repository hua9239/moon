#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    vector<int> ans;
    while (!ss.eof()) {
        int num;
        char symbol;
        ss >> num >> symbol;
        ans.push_back(num);
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}