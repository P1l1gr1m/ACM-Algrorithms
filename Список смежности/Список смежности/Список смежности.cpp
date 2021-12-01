#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m;
	fin >> n >> m;
	vector<vector<int>> graph(n);
	int u, v;
	for (int i = 0; i < m; ++i) {
		fin >> u >> v;
		graph[u - 1].push_back(v);
		graph[v - 1].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		fout << graph[i].size() << " ";
		for (int j = 0; j < graph[i].size(); ++j) fout << graph[i][j] << " ";
			fout << endl;
	}
	return 0;
}