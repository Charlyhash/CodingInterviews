/*
剑指offer
题目大意：在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

分析：从右上角的数字开始比较，如果等于这个数，那么直接返回；如果大于这个数，
那么一定在这一行左边；如果小于这个数，一定在这一列下面。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int>> array)
	{
		if (array.size() == 0)
			return false;
		int row = array.size();
		int col = array[0].size();
		int res = false;
		int j = col - 1; 
		int i = 0;
		while(i >= 0 && i < row && j >= 0 && j < col)
		{
			if (target == array[i][j])
				return true;
			else if (target < array[i][j])
				--j;
			else
				++i;
		}

		return res;
	}
};

void TEST()
{
	Solution sol;
	vector<vector<int>> array = { {1,2,8,9},{2,4,9,12},{4,7,10,13}};
	cout << sol.Find(7, array) << endl;
	cout << sol.Find(3, array) << endl;
	cout << sol.Find(20, array) << endl;
}

int main()
{
	TEST();

	return 0;

}