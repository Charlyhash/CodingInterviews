/*
剑指offer：最小的K个数

题目大意：输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，
则最小的4个数字是1,2,3,4,。

解题思路：
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct cmp
{
	bool operator()(const int& lhs, const int& rhs) const
	{
		return lhs > rhs;
	}
};

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		vector<int> ret;
		int len = input.size();
		if (k == 0 || k > len)
			return ret;
		//multiset<int, cmp> ms;
		multiset<int, cmp> ms;
		ms.insert(input.begin(), input.begin() + k);
		for (int i = k; i < len; ++i)
		{
			if (input[i] < *ms.begin())
			{
				ms.erase(ms.begin());
				ms.insert(input[i]);
			}
		}

		ret = vector<int>(ms.begin(), ms.end());

		return ret;
	}
};

int main()
{
	vector<int> v{ 4,5,1,6,2,7,3,8 };
	int k = 4;
	Solution sol;
	vector<int> ret = sol.GetLeastNumbers_Solution(v, k);
	
	for_each(ret.begin(), ret.end(), [](int x) {cout << x << " "; });
	cout << endl << endl;

	return 0;
}