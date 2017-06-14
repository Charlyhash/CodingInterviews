/*
��ָoffer-������1���ֵĴ�������1��n������1���ֵĴ�����

��Ŀ����
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��
1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�
ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�����

����˼·��

There are three cases:
Case 1: UVW0XYZ
count = count
e.g., 109: (10+1)*1 + 0*10 + (9+1)
Case 2: UVW1XYZ
count += XYZ + 1
e.g., 1456: (145+1)*1 + (14+1)*10 + (1+1)*100 + (456+1)
Case 3: UVW?XYZ (? >= 2)
count += (UVW + 1) * 1000        (1000 is determined by the digit of ?)
e.g., 229: (22+1)*1 + (2+1)*10 + (0+1)*100

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int res = 0; int a = 1; int b = 1;
		while (n > 0)
		{
			cout << (n + 8) / 10 * a << "," << (n % 10 == 1)*b << endl;
			//(n + 8) / 10��ʾҪ�����>=2����ô����(��ߵ���+1)*1 ��
			//(n % 10 == 1)*b��ʾ��һλ���Ϊ1����ô��һλ�ϵĸ������м��ϣ��ұߵ���+1��
			//�����������һλΪ0����ô�Ͳ���������һλΪ1
			res += (n + 8) / 10 * a + (n % 10 == 1)*b;
			b += n % 10 * a;//�ۼƵ��ұߵ���
			a *= 10;//�ۼƵ���ߵ���
			n /= 10;
		}

		return res;
	}
};

int main()
{
	Solution sol;
	cout << sol.NumberOf1Between1AndN_Solution(10) << endl;

	return 0;
}