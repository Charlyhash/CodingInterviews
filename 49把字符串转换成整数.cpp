/*
剑指offer 把字符串转换成整数

题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空

输出描述:
如果是合法的数值表达则返回该数字，否则返回0

输入例子:
+2147483647
1a33

输出例子:
2147483647
0

解题思路：
先要排除错误的情况，转换时只需要每一位乘以权重相加即可
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) 
	{
		int flag = 0;
		int ret = 0;
		int len = str.size();
		if (len == 0)
			return 0;
		int idx = 0;
		if (str[0] == '+')
			idx++;
		else if (str[0] == '-')
		{
			idx++;
			flag = 1;
		}
		while (idx < len)
		{
			if (str[idx] < '0' || str[idx] > '9')
				return 0;
			ret = ret * 10 + str[idx] - '0';
			++idx;
		}
		if (flag == 1)
			ret *= -1;
		return ret;
	}
};

int main()
{
	string str;
	Solution sol;
	while (cin >> str)
	{
		cout << sol.StrToInt(str) << endl;
	}

	return 0;
}

