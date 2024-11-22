#include <iostream>
#include <vector>
using namespace std;
int main() {
    int size;
    cin >> size;
    // ?}?C?j?p

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // ?M?w??ơB????
    int type;
    cin >> type;
    for (int i = arr.size() - (((arr[arr.size() - 1]) % 2 + type % 2)) % 2 - 1;
         i >= 0; i -= 2) {
        cout << arr[i] << " ";
    }
}
