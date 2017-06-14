/*
剑指offer 和为S的连续正数序列

题目描述：
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,
他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快
的找出所有和为S的连续正数序列? Good Luck!

输出描述：
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

解题思路：用两个指针samll和big分别指向遍历的数字，small应该小于(sum+1)/2否则至少两个数相加
一定会大于sum.如果当前的和大于sum，就让small++,如果小于sum就让big++,如果相等就找到了一组
数。注意：由于求和是连续的数，可以每改变smll或big时都更新，这样可以方便计算curSum.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> ret;
		if (sum < 3)
			return ret;
		vector<int> tmp;
		int mid = (sum + 1) / 2;
		int small = 1, big = 2;
		int curSum = big + small;
		tmp.push_back(small); tmp.push_back(big);
		while (small < mid)
		{
			if (curSum == sum)
			{
				ret.push_back(tmp);
				tmp.erase(tmp.begin());
				curSum -= small;
				small++;
				//break;
			}
			while (curSum > sum)
			{
				curSum -= small;
				small++;
				tmp.erase(tmp.begin());
				if (curSum == sum)
				{
					ret.push_back(tmp);
					tmp.erase(tmp.begin());
					curSum -= small;
					small++;
					break;
				}
			}
			++big;
			tmp.push_back(big);
			curSum += big;
		}

		return ret;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> ret;
	ret = sol.FindContinuousSequence(15);
	for (auto v : ret)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}