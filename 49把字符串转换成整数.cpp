/*
��ָoffer ���ַ���ת��������

��Ŀ����
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
��������:
����һ���ַ���,����������ĸ����,����Ϊ��

�������:
����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0

��������:
+2147483647
1a33

�������:
2147483647
0

����˼·��
��Ҫ�ų�����������ת��ʱֻ��Ҫÿһλ����Ȩ����Ӽ���
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) 
	{
		int flag = 0;
		int ret = 0;
		int len = str.size();
		if (len == 0)
			return 0;
		int idx = 0;
		if (str[0] == '+')
			idx++;
		else if (str[0] == '-')
		{
			idx++;
			flag = 1;
		}
		while (idx < len)
		{
			if (str[idx] < '0' || str[idx] > '9')
				return 0;
			ret = ret * 10 + str[idx] - '0';
			++idx;
		}
		if (flag == 1)
			ret *= -1;
		return ret;
	}
};

int main()
{
	string str;
	Solution sol;
	while (cin >> str)
	{
		cout << sol.StrToInt(str) << endl;
	}

	return 0;
}

