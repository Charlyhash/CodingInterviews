/*
��ָoffer �����˵��˶���Χ

��Ŀ����
������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ���
�ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ��
�������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38����
��Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�

����˼·��
���ݷ�
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

	//���������λ�ĺ�
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

