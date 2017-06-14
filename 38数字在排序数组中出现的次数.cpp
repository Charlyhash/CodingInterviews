/*
剑指offer 38.数字在排序数组中出现的次数

题目描述
统计一个数字在排序数组中出现的次数。

解题思路：
1. 直接遍历?时间复杂度为O(n)
2. 二分查找，找到第一个k和最后一个k的位置。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) 
	{
		int ret = 0;
		if (data.size() > 0)
		{
			int firstK = getFirstOfk(data, k, 0, data.size() - 1);
			int lastK = getLastOfk(data, k, 0, data.size() - 1);

			if (firstK > -1 && lastK > -1)
				ret = lastK - firstK + 1;
		}

		return ret;
	}

private:
	int getFirstOfk(vector<int>& data, int k, int start, int end)
	{
		if (start > end)
			return -1;
		int mid = (start + end) / 2;
		if (data[mid] == k)
		{
			if ((mid > 1 && data[mid - 1] != k) || mid == 0)
				return mid;
			else
				return getFirstOfk(data, k, start, mid - 1);
		}
		else if (data[mid] < k)
		{//find in [mid+1, end] 
			return getFirstOfk(data, k, mid + 1, end);
		}
		else
		{//find in [start, mid -1]
			return getFirstOfk(data, k, start, mid - 1);
		}
	}

	int getLastOfk(vector<int>& data, int k, int start, int end)
	{
		if (start > end)
			return -1;
		int mid = (start + end) / 2;
		if (data[mid] == k)
		{
			if ((mid < data.size()-1 && data[mid + 1] != k) || mid == data.size() - 1)
				return mid;
			else
				return getLastOfk(data, k, mid+1, end);
		}
		else if (data[mid] < k)
		{//find in [mid+1, end] 
			return getLastOfk(data, k, mid + 1, end);
		}
		else
		{//find in [start, mid -1]
			return getLastOfk(data, k, start, mid - 1);
		}
	}
};

int main()
{
	Solution sol;
	vector<int> data{1,2,3,3,3,3,4,5};
	cout << sol.GetNumberOfK(data, 3) << endl;

	return 0;
}