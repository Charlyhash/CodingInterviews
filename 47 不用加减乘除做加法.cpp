/*
剑指offer 不用加减乘除做加法

题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

解题思路：
使用二进制来思考：
两位数相加，1+1=10,0+1=1,1+0=1，0+0=0
不考虑进位，就是a^b,进位是a&b<<1
*/
#include<iostream>
using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		int sum = 0, carry = 0;
		do {
			sum = (num1 ^ num2);
			carry = (num1 & num2)<<1;

			num1 = sum;
			num2 = carry;
		} while (num2 != 0);

		return num1;
	}
};

int main()
{
	Solution sol;
	cout << sol.Add(5, 9) << endl;

	return 0;
}