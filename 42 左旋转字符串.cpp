/*
��ָoffer ����ת�ַ���

��Ŀ����
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ��
���ָ���������������һ���������ַ�����S���������ѭ������Kλ���������������磬
�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�
OK���㶨����

����˼·�������巭ת��Ȼ���ٸ������Ƶ�λ����ת
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