/*
��ָoffer-��������1�ĸ���

����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��

����˼·��
1. ʹ��flagȥ����ÿһλ���Ƿ�Ϊ1��Ȼ���flag����һλ
2. ���ã�n��n-1&���������һλ��1��Ϊ0
*/


#include <iostream>

using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int ret = 0;
		unsigned int flag = 1;
		while (flag)
		{
			if (n & flag)
				++ret;
			flag = flag << 1;
		}

		return ret;
	}

	int  NumberOf2(int n)
	{
		int ret = 0;
		while (n)
		{
			++ret;
			n = (n - 1)&n;
		}

		return ret;
	}
};

int main()
{
	Solution sol;

	cout << sol.NumberOf1(16) << endl;
	cout << sol.NumberOf1(-1) << endl;
}