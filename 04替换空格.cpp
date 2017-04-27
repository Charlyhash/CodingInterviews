/*
��ָoffer
��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.
�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

����˼·��˫ָ��
�ȱ���һ�ο��ַ����еĿո�����Ȼ����ݵõ��Ŀո��������µ��ַ���ĩβλ��
���Ӻ���ǰ�����ַ��������ո��滻Ϊ%20
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