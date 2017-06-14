/*
剑指offer 字符流中第一个不重复的字符
题目描述：
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个
字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，
第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。

解题思路：

*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution
{

public:
	Solution():index(0)
	{
		v.resize(255, -1);
	}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (v[ch] == -1)
			v[ch] = index;
		else if (v[ch] >= 0)
			v[ch] = -2;

		++index;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int minIndex = 0x7fffff;
		char ch = '\0';
		for (size_t i = 0; i < v.size(); ++i)
		{
			if (v[i] >= 0 && v[i] < minIndex)
			{
				ch = (char)i;
				minIndex = v[i];
			}
		}
		if (minIndex == 0x7fffff)
			ch = '#';
		return ch;
	}

private:
	vector<int> v;
	int index;
};

int main()
{
	Solution sol;
	string str("google");
	for (auto ch : str)
	{
		sol.Insert(ch);
		cout << sol.FirstAppearingOnce();
	}
	cout << endl;

	return 0;
}