/*
��ָoffer ���üӼ��˳����ӷ�

��Ŀ����
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�

����˼·��
ʹ�ö�������˼����
��λ����ӣ�1+1=10,0+1=1,1+0=1��0+0=0
�����ǽ�λ������a^b,��λ��a&b<<1
*/
#include<iostream>
using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		int sum = 0, carry = 0;
		do {
			sum = (num1 ^ num2);
			carry = (num1 & num2)<<1;

			num1 = sum;
			num2 = carry;
		} while (num2 != 0);

		return num1;
	}
};

int main()
{
	Solution sol;
	cout << sol.Add(5, 9) << endl;

	return 0;
}