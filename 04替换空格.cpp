/*
剑指offer
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.
则经过替换之后的字符串为We%20Are%20Happy。

解题思路：双指针
先遍历一次看字符串中的空格数，然后根据得到的空格数计算新的字符串末尾位置
最后从后向前复制字符，遇到空格替换为%20
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL)
			return;
		int blank_count = 0;
		int oldlen = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			++oldlen;
			if (str[i] == ' ')
				++blank_count;
			++i;
		}
		
		int len = oldlen + blank_count*2;
		if (len > length)
			return;
		int pre = oldlen;
		int last = len;
		while (pre >= 0 && last > pre)
		{
			if (str[pre] != ' ')
			{
				str[last--] = str[pre];
			}
			else
			{
				str[last--] = '0';
				str[last--] = '2';
				str[last--] = '%';
			}
			--pre;
		}

		//printf("%s\n", str);
	}
};

void TEST()
{
	Solution sol;
	char str[1024] = "we are happy!";
	sol.replaceSpace(str, 1024);

	char str1[1024] = " ";
	sol.replaceSpace(str1, 1024);

	char str2[1024] = "    ";
	sol.replaceSpace(str2, 1024);
}

int main()
{

	TEST();

	return 0;
}