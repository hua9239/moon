#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ??J?}?C?j?p
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    for (int i = arr.size() - 1; i >= 0; i--)
        cout << arr[i] << " ";

    return 0;
}

/*
int main() {
    // ??J?}?C?j?p
    int size;
    cin >> size;

    int arr[500];  //?Фj?p??size???}?C 1~500 ?j?p
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for (int i = size - 1; i >= 0; i--)
        cout << arr[i] << " ";

    return 0;
}
*/
