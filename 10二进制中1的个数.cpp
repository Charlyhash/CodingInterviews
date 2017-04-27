/*
剑指offer-二进制中1的个数

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

解题思路：
1. 使用flag去测试每一位的是否为1，然后把flag左移一位
2. 利用：n和n-1&，会让最后一位的1变为0
*/


#include <iostream>

using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int ret = 0;
		unsigned int flag = 1;
		while (flag)
		{
			if (n & flag)
				++ret;
			flag = flag << 1;
		}

		return ret;
	}

	int  NumberOf2(int n)
	{
		int ret = 0;
		while (n)
		{
			++ret;
			n = (n - 1)&n;
		}

		return ret;
	}
};

int main()
{
	Solution sol;

	cout << sol.NumberOf1(16) << endl;
	cout << sol.NumberOf1(-1) << endl;
}