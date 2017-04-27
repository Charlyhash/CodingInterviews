/*
剑指offer-变态跳台阶

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。

解题思路：
f(n) = 2^(n-1)
*/

#include <iostream>
#include <algorithm>

class Solution {
public:
	int jumpFloorII(int number) {
		return pow(2, number - 1);
	}
};

void test()
{

}

int main()
{
	test();

	return 0;
}