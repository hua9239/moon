#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<vector<int>> getPasswordTable(int number) {
	srand(number);
	vector<vector<int>> PasswordTable(10, vector<int>(10));
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			PasswordTable[i][j] = rand() % 100;
		}
	}

	return PasswordTable;
}

vector<int> getCipertext(int HTCode, vector<vector<int>> PasswordTable) {
	vector<int> ans, tempArr;
	while (HTCode > 0) {
		int temp = HTCode % 10;
		tempArr.push_back(temp);
		HTCode /= 10;
	}
	if (tempArr.size() % 2 == 1) {
		tempArr.push_back(0);
	}
	for (int i = 0; i < tempArr.size(); i += 2) {
		ans.push_back(PasswordTable[tempArr[i]][tempArr[i + 1]]);
	}
	return ans;
}

void HanoiTowerCode(int n, int& k, int& total) {
	if (n == 1) {
		total += (++k);
	}
	else {
		HanoiTowerCode(n - 1, k, total);
		total += (++k);
		HanoiTowerCode(n - 1, k, total);
	}
}

int main() {
	int Plaintext, k, total = 0;
	cin >> Plaintext;
	//write here//
	Plaintext += 2;
	k = 1;
	//write here//
	HanoiTowerCode(Plaintext, k, total);

	vector<vector<int>> PasswordTable = getPasswordTable(total);

	vector<int> ans = getCipertext(total, PasswordTable);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i];
	}
}
