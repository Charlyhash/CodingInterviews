/*
剑指offer 正则表达式匹配

题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字
符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"
均不匹配
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == NULL || pattern == NULL)
			return false;

		return matchHelp(str, pattern);
	}
private:
	bool matchHelp(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*str != '\0' && *pattern == '\0')
			return false;
		if (*(pattern + 1) == '*')
		{
			if (*pattern == *str || *pattern == '.' && *str != '\0')
				//移动到下一个状态，吃掉*str,匹配后面的部分
				return matchHelp(str + 1, pattern + 2)
				//保持在当前状态，吃掉*str
				|| matchHelp(str + 1, pattern)
				//忽略*
				|| matchHelp(str, pattern + 2);
			else
				//不相等,忽略*
				return matchHelp(str, pattern + 2);
		}
		//相等就吃掉*str,继续匹配下面的部分
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
			return matchHelp(str + 1, pattern + 1);
		
		//其他情况，说明不匹配
		return false;
	}
};

int main()
{
	Solution sol;
	char* str = "aaa";
	char* pattern1 = "ab*ac*a";
	char* pattern2 = "a.a";
	char* pattern3 = "aa.a";
	char* pattern4= "ab*a";
	cout << sol.match(str, pattern1) << endl;
	cout << sol.match(str, pattern2) << endl;
	cout << sol.match(str, pattern3) << endl;
	cout << sol.match(str, pattern4) << endl;

	return 0;
}