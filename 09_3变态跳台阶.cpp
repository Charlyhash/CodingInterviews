/*
��ָoffer-��̬��̨��

һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������

����˼·��
f(n) = 2^(n-1)
*/

#include <iostream>
#include <algorithm>

class Solution {
public:
	int jumpFloorII(int number) {
		return pow(2, number - 1);
	}
};

void test()
{

}

int main()
{
	test();

	return 0;
}