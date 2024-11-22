#include <iostream>
using namespace std;

const int a_rows = 4;
const int a_columns = 3;
const int b_rows = 100;
const int b_columns = 3;

int b_count = 0;
void compress_print(int b[][b_columns]) {
    for (int i = 0; i < b_count; i++) {
        for (int j = 0; j < b_columns; j++) {
            cout << b[i][j] << " ";
        }
    }
}

void compress_process(int a[][a_columns], int b[][b_columns]) {
    b[b_count][0] = a_rows;
    b[b_count][1] = a_columns;
    for (int i = 0; i < a_rows; i++)
        for (int j = 0; j < a_columns; j++) {
            if (a[i][j] != 0) {
                b[++b_count][0] = i;
                b[b_count][1] = j;
                b[b_count][2] = a[i][j];
            }
        }
    b[0][2] = b_count++;
}

void compress_init(int a[][a_columns]) {
    for (int i = 0; i < a_rows; i++)
        for (int j = 0; j < a_columns; j++)
            cin >> a[i][j];
}

int main(int argc, char* argv[]) {
    int A[a_rows][a_columns], B[b_rows][b_columns];
    compress_init(A);
    compress_process(A, B);
    compress_print(B);
}
