/*
剑指offer 左旋转字符串

题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟
这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，
字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？
OK，搞定它！

解题思路：先整体翻转，然后再根据左移的位数翻转
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n) 
	{
		if (str.size() < 2)
			return str;
		int len = str.size();
		n %= len;

		reverse(str.begin(), str.end());
		int pos = len - n;
		reverse(str.begin(), str.begin() + pos);
		reverse(str.begin() + pos, str.end());

		return str;
	}
};

int main()
{
	string s("abcXYZdef");
	Solution sol;
	s = sol.LeftRotateString(s, 3);
	cout << s << endl;

	return 0;
}