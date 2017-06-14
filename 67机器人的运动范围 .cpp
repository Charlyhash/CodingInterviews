/*
剑指offer 机器人的运动范围

题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下
四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，
机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

解题思路：
回溯法
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<bool> visited(rows*cols, false);

		return movingCountCore(threshold, rows, cols, 0, 0, visited);
	}

private:
	int movingCountCore(int threshold, int rows, int cols, int row, int col, vector<bool>& visited)
	{
		int count = 0;
		if (vailedPos(threshold, rows, cols, row, col, visited))
		{
			visited[row*cols + col] = true;
			count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited) +
				movingCountCore(threshold, rows, cols, row, col - 1, visited) +
				movingCountCore(threshold, rows, cols, row + 1, col, visited) +
				movingCountCore(threshold, rows, cols, row, col + 1, visited);
		}

		return count;
	}

	bool vailedPos(int threshold, int rows, int cols, int row, int col, vector<bool>& visited)
	{
		if (row >= 0 && row < rows && col >= 0 && col < cols &&
			getDigitSum(row) + getDigitSum(col) <= threshold &&
			!visited[row*cols + col])
			return true;
		return false;
	}

	//计算各个数位的和
	int getDigitSum(int num)
	{
		int ret = 0;
		while (num > 0)
		{
			ret += num % 10;
			num /= 10;
		}

		return ret;
	}
};

int main()
{
	Solution sol;
	cout << sol.movingCount(18, 100, 100) << endl;

	return 0;
}

