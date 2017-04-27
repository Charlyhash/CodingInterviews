/*
剑指offer-09斐波那契数列

大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列
的第n项。n<=39

解题思路：
递归
*/

#include <iostream>

using namespace std;

class Solution {
public:
	//TLE
	int Fibonacci_TLE(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return Fibonacci_TLE(n - 1) + Fibonacci_TLE(n - 2);
	}

	int Fibonacci(int n)
	{
		long long pre = 0;
		long long cur = 1;
		long long ret;
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;

		for (int i = 2; i <= n; ++i)
		{
			ret = pre + cur;
			pre = cur;
			cur = ret;
		}

		return ret;
	}
};

void test()
{
	Solution sol;
	cout << sol.Fibonacci_TLE(30) << endl;
	cout << sol.Fibonacci(30) << endl;
}

int main()
{
	test();

	return 0;
}