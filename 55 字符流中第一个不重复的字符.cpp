/*
��ָoffer �ַ����е�һ�����ظ����ַ�
��Ŀ������
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ����
�ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"ʱ��
��һ��ֻ����һ�ε��ַ���"l"��
�������:
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���

����˼·��

*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution
{

public:
	Solution():index(0)
	{
		v.resize(255, -1);
	}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (v[ch] == -1)
			v[ch] = index;
		else if (v[ch] >= 0)
			v[ch] = -2;

		++index;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int minIndex = 0x7fffff;
		char ch = '\0';
		for (size_t i = 0; i < v.size(); ++i)
		{
			if (v[i] >= 0 && v[i] < minIndex)
			{
				ch = (char)i;
				minIndex = v[i];
			}
		}
		if (minIndex == 0x7fffff)
			ch = '#';
		return ch;
	}

private:
	vector<int> v;
	int index;
};

int main()
{
	Solution sol;
	string str("google");
	for (auto ch : str)
	{
		sol.Insert(ch);
		cout << sol.FirstAppearingOnce();
	}
	cout << endl;

	return 0;
}