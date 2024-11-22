#include <iostream>
using namespace std;

const int rows = 2;
const int columns = 3;

void matrix_add(int a[][columns], int b[][columns], int c[][columns]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void matrix_print(int arr[][columns]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cout << arr[i][j] << " ";
}

void matrix_init(int a[][columns], int b[][columns]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> a[i][j];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> b[i][j];
}

int main(int argc, char* argv[]) {
    int A[rows][columns], B[rows][columns], C[rows][columns];
    matrix_init(A, B);
    matrix_add(A, B, C);
    matrix_print(C);
}
