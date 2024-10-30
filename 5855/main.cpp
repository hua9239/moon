#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ??P????????
    int row, column;
    cin >> row >> column;

    // ?إ߰}?C
    vector<vector<int> > arr(row, vector<int>(column));

    // ?C?@?ƭȪ???J
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cin >> arr[i][j];

    // ??X?쥻??
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    // ½??A?W?U?洫
    for (int i = 0, j = row - 1; i < row / 2; i++, j--)
        for (int k = 0; k < column; k++) {
            int temp = arr[i][k];
            arr[i][k] = arr[j][k];
            arr[j][k] = temp;
        }

    //??X½??᪺???A
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    // ??g?A???k?洫
    for (int i = 0, j = column - 1; i < column / 2; i++, j--)
        for (int k = 0; k < row; k++) {
            int temp = arr[k][i];
            arr[k][i] = arr[k][j];
            arr[k][j] = temp;
        }

    //??X??g?᪺???A
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}