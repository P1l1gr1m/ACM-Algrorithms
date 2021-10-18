#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getPalindrome(string str, int size) {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int** mas = new int* [size];
	for (int i = 0; i < size; i++) {
		mas[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mas[i][j] = 0;
		}
		mas[i][i] = 1;
	}
	for (int q = 1; q < size; q++) {
		for (int i = 0; i < size - q; i++) {
			int j = i + q;
			if (str[i] == str[j]) {
				mas[i][j] = mas[i + 1][j - 1] + 2;
			}
			else {
				if (mas[i + 1][j] > mas[i][j - 1]) mas[i][j] = mas[i + 1][j];
				else mas[i][j] = mas[i][j - 1];
			}
		}
	}
	int l = 0, r = size - 1;
	string result;
	int palR = mas[0][size - 1] - 1, palL = 0;
	result.resize(palR + 1);
	while (l <= r) {
		if (l == r && mas[l][r] == 1) result[palL++] = str[l++];
		else {
			if (str[l] == str[r]) {
				result[palL++] = str[l++];
				result[palR--] = str[r--];
			}
			else {
				if (mas[l + 1][r] >= mas[l][r - 1]) l++;
				else r--;
			}
		}
	}

	fout << mas[0][size - 1] << endl;
	fout << result;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string word;
	fin >> word;
	getPalindrome(word, word.size());
	return 0;
}