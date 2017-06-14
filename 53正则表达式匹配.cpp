/*
��ָoffer ������ʽƥ��

��Ŀ����
��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ���
��'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� �ڱ����У�ƥ����ָ�ַ�����������
��ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"
����ƥ��
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
				//�ƶ�����һ��״̬���Ե�*str,ƥ�����Ĳ���
				return matchHelp(str + 1, pattern + 2)
				//�����ڵ�ǰ״̬���Ե�*str
				|| matchHelp(str + 1, pattern)
				//����*
				|| matchHelp(str, pattern + 2);
			else
				//�����,����*
				return matchHelp(str, pattern + 2);
		}
		//��ȾͳԵ�*str,����ƥ������Ĳ���
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
			return matchHelp(str + 1, pattern + 1);
		
		//���������˵����ƥ��
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