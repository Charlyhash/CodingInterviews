/*
��ָoffer-���θ���

���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��
С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

����˼·��
f(n)Ϊ���ǵ�����:�����ֱ���ã���ô��f(n-1)�֣���������f(n-2)��
f(n)=f(n-2)+f(n-1)
*/

#include <iostream>

using namespace std;

class Solution {
public:
	int rectCover(int number) {
		if (number == 0)
			return 0;
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
	cout << sol.rectCover(10) << endl;
	cout << endl;
}

int main()
{
	test();

	return 0;
}