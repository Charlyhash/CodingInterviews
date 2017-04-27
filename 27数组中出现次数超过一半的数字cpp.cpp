/*
��ָoffer �����г��ִ�������һ������֡�

��Ŀ���⣺��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������
һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤��
��һ�룬������2����������������0��

����˼·�����ڳ��ֵĴ����ǳ��������ģ���ô�������飬��ס��ǰ��cur�Գ��ֵĴ���count�Ϳ���
��target.�����������Ϊ�����֣���count+1������count-1.���countΪ0,���ñ�������Ϊcur.
��������cur���ǳ��ִ�������һ�����
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)
			return 0;
		int cur = numbers[0];
		int count = 1;
		for (int i = 1; i < numbers.size(); ++i)
		{
			if (count == 0)
			{
				cur = numbers[i];
				count = 1;
			}
			else 
			{
				if (cur == numbers[i])
					++count;
				else
					--count;
			}

			//cout << cur << ":" << count << endl;
		}
		//if (count == 0)
		//	return 0;
		int times = 0;
		for (int i = 0; i < numbers.size(); ++i)
			if (cur == numbers[i])
				++times;
		if (2 * times <= numbers.size())
			return 0;

		return cur;
	}
};

int main()
{
	vector<int> v{ 4,2,4,1,4,2 };
	Solution sol;
	cout << sol.MoreThanHalfNum_Solution(v) << endl;
	return 0;
}