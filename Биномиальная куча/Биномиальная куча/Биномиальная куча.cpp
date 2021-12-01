#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	long long N;
	fin >> N;
	int count = 0;
	while (N > 0) {
		if (N % 2 == 1)
		fout << count << endl;
		N = N / 2;
		count++;
	}
}