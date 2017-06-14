/*
剑指offer:和为S的两个数字

题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。

解题思路：要想求其中这两个数积最小，只需要这两个数差最大，这样先排序数组，然后
用两个指针扫描数组，如果大于sum就让大的数减小，如果小于sum,就让小的数增大，直到
和为sum.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> ret;
		sort(array.begin(), array.end());
		int bigIndex = array.size() - 1;
		int smallIndex = 0;
		while (smallIndex < bigIndex)
		{
			if (array[smallIndex] + array[bigIndex] == sum)
			{
				ret.push_back(array[smallIndex]);
				ret.push_back(array[bigIndex]);
				break;
			}
			else if (array[smallIndex] + array[bigIndex] < sum)
				++smallIndex;
			else
				--bigIndex;

		}
		
		return ret;
	}
};

int main()
{
	vector<int> array{1, 2, 4, 11, 15, 7};
	Solution sol;
	vector<int> ret;
	ret = sol.FindNumbersWithSum(array, 15);
	for (auto i : ret)
		cout << i << " ";
	cout << endl;

	return 0;
}
