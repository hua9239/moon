#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, H;
    cin >> N >> H;
    vector<vector<int> > Narray(N);  // ??N?j?p???}?C

    int current_size;  // ?{?b???j?p
    for (int i = 0; i < Narray.size(); i++) {
        cin >> current_size;
        Narray[i].resize(current_size);
        for (int j = 0; j < Narray[i].size(); j++) {
            cin >> Narray[i][j];
        }  // for_j_end
    }      // for_i_end

    vector<int> ans(H);
    for (int i = 0; i < ans.size(); i++) {
        int a, b;
        cin >> a >> b;
        ans[i] = Narray[a][b];
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}