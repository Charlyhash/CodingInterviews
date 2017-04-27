/*
剑指offer-跳台阶
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

#include <iostream>

using namespace std;

class Solution {
public:
	int jumpFloor(int number) {
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
	cout << sol.jumpFloor(10) << endl;
}

int main()
{
	test();

	return 0;
}