/*
剑指offer-第一个只出现一次的字符
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置。如果字符串为空,返回-1

解题思路：打表，用一个数组记录每个字符出现的次数。然后遍历str，如果当前字符出
现次数为1,则输出该index

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		vector<char> v(128);
		for (auto ch : str)
			++v[ch];
		for (int i = 0; i < str.size(); ++i)
			if (v[str[i]] == 1)
				return i;

		return -1;
	}
};

int main()
{
	Solution sol;
	cout << sol.FirstNotRepeatingChar("abaccdeff") << endl;


	return 0;
}