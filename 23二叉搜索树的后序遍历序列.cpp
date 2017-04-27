/*
��ָoffer-�����������ĺ����������

����һ���������飬�жϸ������ǲ���ĳ�����������ĺ��������
���������������Yes,�������No������������������������
���ֶ�������ͬ��

����˼·�����ڶ������������������������һ��Ԫ��Ϊ���ڵ㡣
��˿���ͨ���ݹ�ķ����������Ϊ�����֣������ݹ顣���зֵ�
��������һ��ȫ��С�ڸ��ڵ㣬һ��ȫ�����ڸ��ڵ㡣
*/

#include <iostream>
#include <vector>
#include "TreeInclude.h"

using namespace std;

class Solution {
private:
	bool Help(vector<int>& sequence, int l, int r)
	{
		if (l >= r)
			return true;
		int i = l;
		while (sequence[i] < sequence[r] && i < r)
			++i;
		for (int j = i; j < r; ++j)
			if (sequence[j] < sequence[r])
				return false;

		return Help(sequence, l, i - 1) && Help(sequence, i, r-1);
	}
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
			return false;

		return Help(sequence, 0, sequence.size() - 1);
	}
};

int main()
{
	vector<int> s{ 4,8,6,12,16,14,10 };
	Solution sol;
	cout << sol.VerifySquenceOfBST(s) << endl;

	return 0;
}