#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;

void magic_init(vector<vector<double>>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        for (int j = 0; j < arr[i].size(); ++j)
            cin >> arr[i][j];
}

// Function to perform Doolittle's LU decomposition
void luDecomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    //init_U
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            U[i][j] = A[i][j];

    for (int i = 0; i < n; ++i) {
        //check and switch U_rows&L_columns
        if (U[i][i] == 0) {
            for (int j = i + 1; j < n; ++j) {
                if (U[j][i] != 0) {
                    for (int k = i; k < n; ++k)
                        swap(U[i][k], U[j][k]);
                    for (int k = 0; k < i; ++k)
                        swap(L[i][k], L[j][k]);
                    break;
                }
            }
        }
        if (U[i][i] == 0) {
            continue;
        }

        // L matrix
        for (int j = i; j < n; ++j) {
            if (i == j) {
                L[i][i] = 1.0;
            }
            else {
                L[j][i] = U[j][i] / U[i][i];
            }
        }

        // U matrix
        for (int j = i + 1; j < n; ++j) {
            for (int k = i; k < n; ++k) {
                U[j][k] -= (U[i][k] * L[j][i]);
            }
        }
    }
}

void printArray(vector<vector<double>>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            cout << fixed << setprecision(2) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void isInvertible(vector<vector<double>>& arr) {
    int determinant = 1;
    for (int i = 0; i < arr.size(); ++i)
        determinant *= arr[i][i];

    if (determinant == 0) cout << "Non-invertible magic";
    else cout << "Invertible magic";
}

int main() {
    int magic_size;
    cin >> magic_size;
    vector<vector<double>> magic(magic_size, vector<double>(magic_size)),
        L(magic.size(), vector<double>(magic.size())),
        U(magic.size(), vector<double>(magic.size()));
    magic_init(magic);

    luDecomposition(magic, L, U);
    printArray(L);
    printArray(U);
    isInvertible(U);
}
