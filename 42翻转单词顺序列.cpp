/*
剑指offer : 翻转单词顺序列
题目大意：牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，
“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是
“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

解题思路：
先整体reverse。然后找到空格，然后reverse.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		if (str.size() < 2)
			return str;
		reverse(str.begin(), str.end());

		int p1 = 0, p2 = 0;
		while (p2 < str.size())
		{
			while (str[p2] != ' ' && p2 < str.size())
				++p2;
			reverse(str.begin() + p1, str.begin() + p2);
			p1 = p2 + 1;
			p2 = p1;
		}

		return str;
	}
};

int main()
{
	string s("student. a am I");
	Solution sol;
	string str = sol.ReverseSentence(s);
	cout << str << endl;

	return 0;
}
