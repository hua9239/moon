#include <iostream>
using namespace std;

const int rows = 4;
const int columns = 4;

// ??m
void matrix_transpose(int arr[][columns]) {
    int temp[rows][columns] = {};
    for (int i = 0; i < rows; i++)
        for (int j = i; j < columns; j++)
            swap(arr[i][j], arr[j][i]);
}

// ??X
void matrix_print(int arr[][columns]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cout << arr[i][j] << " ";
}

// ??J
void matrix_init(int arr[][columns]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> arr[i][j];
}

int main(int argc, char* argv[]) {
    int A[rows][columns];
    matrix_init(A);
    matrix_transpose(A);
    matrix_print(A);
}
