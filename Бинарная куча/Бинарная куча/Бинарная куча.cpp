#include <iostream>
#include <fstream>

using namespace std;


int main() {
	int n = 0;
	int x = 0;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n;
	int* mass = new int[n];
	for (int i = 0; i < n; ++i) {
		fin >> x;
		mass[i] = x;
	}
	bool c = true;
	for (int i = 1; i < n; ++i) {
		if (mass[i] < mass[(i - 1) / 2]) {
			c = false;
		}
	}
	if (c == true) {
		fout << "Yes";
	}
	else {
		fout << "No";
	}
}