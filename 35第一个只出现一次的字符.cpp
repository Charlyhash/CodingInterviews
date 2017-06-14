/*
��ָoffer-��һ��ֻ����һ�ε��ַ�
��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,
����������λ�á�����ַ���Ϊ��,����-1

����˼·�������һ�������¼ÿ���ַ����ֵĴ�����Ȼ�����str�������ǰ�ַ���
�ִ���Ϊ1,�������index

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