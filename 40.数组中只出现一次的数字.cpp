/*
剑指offer：数组中只出现一次的数字
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次
的数字。

解题思路：
1. 用set存放，遍历数组，如果不在set中，就加入，否则从set中删除这个数
2. 把所有的数字或运算，结果为一个数，找到这个数为1的最低位，根据其他的数该位是否为1,
将数组分为两组。这时分得的两组都都只有一个不一样的数了。
现在这两组数分别或运算，那么求得的结果就是这两个不同的数了。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if (data.size() < 2)
			return;
		int orRes = 0;
		for (size_t i = 0; i < data.size(); ++i)
			orRes ^= data[i];
		int oneIndex = firstOfOne(orRes);
		*num1 = *num2 = 0;
		for (size_t i = 0; i < data.size(); ++i)
		{
			if (isBitOne(data[i], oneIndex))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}

	}
private:
	int firstOfOne(int num)
	{
		if (num == 0)
			return -1;
		int index = 0;
		while ((num & 1) == 0)
		{
			num = num >> 1;
			++index;
		}

		return index;	
	}

	bool isBitOne(int num, int index)
	{
		num = num >> index;
		return num & 1;
	}
};

int main()
{
	Solution sol;
	vector<int> v{ 2,4,3,6,3,2 };
	int num1 = 0, num2 = 0;
	sol.FindNumsAppearOnce(v, &num1, &num2);

	cout << num1 << " " << num2 << endl;

	return 0;
}