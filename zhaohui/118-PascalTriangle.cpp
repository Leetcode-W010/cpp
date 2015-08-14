#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> pascal;
		for (int i = 0; i<numRows; i++) {
			vector<int> nLine(i + 1, 1);
			for (int j = 1; j<i; j++) {
				nLine[j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
			}
			pascal.push_back(nLine);
		}
		return pascal;
	}
	//�ݹ���õĽⷨ
	vector<vector<int>> generate1(int numRows) {
		if (numRows == 0) {
			vector<vector<int>> pascal;
			return pascal;
		}
		if (numRows == 1) {
			vector<int> pLine(1, 1);
			vector<vector<int>> pascal;
			pascal.push_back(pLine);
			return pascal;
		}
		vector<vector<int>> pascal = generate1(numRows-1);
		vector<int> nLine(numRows, 1);
		for (int i = 1; i < numRows - 1; i++) {
			nLine[i] = pascal[numRows - 2][i - 1] + pascal[numRows - 2][i];
		}
		pascal.push_back(nLine);
		return pascal;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> pascal = solution.generate(5);
	for (int i = 0; i<pascal.size(); i++) {
		for (int j = 0; j<pascal[i].size(); j++) {
			cout << pascal[i][j] << " ";
		}
		cout << endl;
	}
}