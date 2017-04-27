/*
��ָoffer-��̨��
һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж�����������
*/

#include <iostream>

using namespace std;

class Solution {
public:
	int jumpFloor(int number) {
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;

		int cur = 2; int pre = 1; int ret;
		for (int i = 3; i <= number; ++i)
		{
			ret = cur + pre;
			pre = cur;
			cur = ret;
		}

		return ret;
	}
};

void test()
{
	Solution sol;
	cout << sol.jumpFloor(10) << endl;
}

int main()
{
	test();

	return 0;
}