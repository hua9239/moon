#include <iostream>
using namespace std;

const int a_rows = 2;
const int a_columns = 3;
const int b_rows = 3;
const int b_columns = 2;

void matrix_mul(int a[][a_columns], int b[][b_columns], int c[][b_columns]) {
    for (int i = 0; i < a_rows; i++)
        for (int j = 0; j < b_columns; j++)
            c[i][j] = 0;

    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < b_columns; j++) {
            for (int k = 0; k < b_rows; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void matrix_print(int arr[a_rows][b_columns]) {
    for (int i = 0; i < a_rows; i++)
        for (int j = 0; j < b_columns; j++)
            cout << arr[i][j] << " ";
}

void matrix_init(int a[][a_columns], int b[][b_columns]) {
    for (int i = 0; i < a_rows; i++)
        for (int j = 0; j < a_columns; j++)
            cin >> a[i][j];
    for (int i = 0; i < b_rows; i++)
        for (int j = 0; j < b_columns; j++)
            cin >> b[i][j];
}

int main(int argc, char* argv[]) {
    int A[a_rows][a_columns], B[b_rows][b_columns], C[a_rows][b_columns];
    matrix_init(A, B);
    matrix_mul(A, B, C);
    matrix_print(C);
}