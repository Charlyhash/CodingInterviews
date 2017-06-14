/*
剑指offer 矩阵中的路径
题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径
可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个
格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 
a b c e
s f c s
a d e e 
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个
字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

解题思路：
回溯法
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
			return false;
		vector<bool> visited(rows*cols, 0);
		int pathLength = 0;

		for (int row = 0; row < rows; ++row)
		{
			for (int col = 0; col < cols; ++col)
			{
				if (hasPathCore(matrix, rows, cols, str, row, col, pathLength, visited))
					return true;
			}
		}

		return false;
	}

	bool hasPathCore(char* matrix, int rows, int cols, char* str, int row, int col,
		int& pathLength, vector<bool>& visited)
	{
		if (str[pathLength] == '\0')
			return true;
		bool hasPath = false;
		if (row >= 0 && row < rows && col >= 0 && col <= cols &&
			matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col])
		{
			++pathLength;
			visited[row*cols + col] = true;
			hasPath = hasPathCore(matrix, rows, cols, str, row, col - 1, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, str, row - 1, col, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, str, row, col + 1, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, str, row + 1, col, pathLength, visited);

			if (!hasPath)
			{
				--pathLength;
				visited[row*cols + col] = false;
			}

		}

		return hasPath;
	}
};

int main()
{
	Solution sol;
	char* matrix = "abcesfcsadee";
	char* str = "bcced";
	cout << sol.hasPath(matrix, 3, 4, str) << endl;

	return 0;
}