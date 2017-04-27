/*
剑指offer-矩形覆盖

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的
小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

解题思路：
f(n)为覆盖的种数:如果竖直放置，那么有f(n-1)种，如果横放有f(n-2)种
f(n)=f(n-2)+f(n-1)
*/

#include <iostream>

using namespace std;

class Solution {
public:
	int rectCover(int number) {
		if (number == 0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;

		int cur = 2; int pre = 1; int ret;
		for (int i = 3; i <= number; ++i)
		{
			ret = cur + pre;
			pre = cur;
			cur = ret;
		}

		return ret;
	}
};

void test()
{
	Solution sol;
	cout << sol.rectCover(10) << endl;
	cout << endl;
}

int main()
{
	test();

	return 0;
}