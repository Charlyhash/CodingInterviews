/*
剑指offer-顺时针打印矩阵

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 
1 2 3 4 
5 6 7 8 
9 10 11 12
13 14 15 16 
则依次打印出数字
1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

解题思路：一圈一圈打印该矩阵即可。
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();

		vector<int> ret;
		PrintCircle(matrix, ret, 0, 0, rows - 1, cols - 1);

		return ret;
	}

private:
	 void PrintCircle(const vector<vector<int>>& m, vector<int>& ret, int a, int b, int c, int d)
	{
		 if (a > c || b > d)
			 return;
		 int i;
		 for (i = b; i <= d; ++i)
			 ret.push_back(m[a][i]);
		 for (i = a + 1; i <= c; ++i)
			 ret.push_back(m[i][d]);
		 for (i = d - 1; i >= b && c > a; --i)
			 ret.push_back(m[c][i]);
		 for (i = c - 1; i > a && d > b; --i)
			 ret.push_back(m[i][b]);

		 PrintCircle(m, ret, a + 1, b + 1, c - 1, d - 1);
	}
};

int main()
{
	vector<vector<int>> m{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	vector<vector<int>> m1{ { 1 },{ 2 },{ 3 },{ 4 },{ 5 } };
	vector<vector<int>> m2{ {1,2,3,4,5} };
	Solution sol;
	vector<int> ret = sol.printMatrix(m1);
	for (auto i : ret)
		cout << i << " ";
	cout << endl;
} 