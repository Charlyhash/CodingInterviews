/*
��ָoffer �����е�·��
��Ŀ����
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·��
���ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ��
���ӡ����һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� ���� 
a b c e
s f c s
a d e e 
�����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ��
�ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�

����˼·��
���ݷ�
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