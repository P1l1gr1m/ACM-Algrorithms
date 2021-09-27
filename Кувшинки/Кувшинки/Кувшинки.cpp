#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	int mas1[1001];
	int mas2[1001];
	for (int i = 0; i < n; ++i)
		fin >> mas1[i];
		mas2[0] = mas1[0];
		mas2[1] = -1;
		mas2[2] = mas1[0] + mas1[2];
		mas2[3] = mas1[0] + mas1[3];
		mas2[4] = mas1[4] + mas2[2];

	for (int i = 5; i < n; i++) {
		mas2[i] = mas1[i] + max(mas2[i - 2], mas2[i - 3]);
	}
		
	fout << mas2[n - 1];
	return 0;
}
