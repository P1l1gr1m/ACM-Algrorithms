#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int number, s;
	cin >> s;
	cin >> number;
	vector<int> volume;
	volume.push_back(number);
	int help = 0;
	while (!cin.eof()) {
		cin >> number;
		if (help % 2 == 0) {
			volume.push_back(number);
		}
		++help;
	}
	long long int** matrix = new long long int* [s + 1];
	for (int i = 0; i < s + 1; ++i) {
		matrix[i] = new long long int[s + 1];
	}
	for (int i = 1; i <= s; ++i) {
		matrix[i][i] = 0;
	}
	for (int n = 2; n <= s; ++n) {
		for (int i = 1; i <= s + 1 - n; ++i) {
			int j = i + n - 1;
			matrix[i][j] = LONG_MAX;
			for (int l = i; l <= j - 1; ++l) {
				matrix[i][j] = min(matrix[i][j], matrix[i][l] + matrix[l + 1][j] + volume[i - 1] * volume[j]);
			}
		}
	}
	cout << matrix[1][s];
}