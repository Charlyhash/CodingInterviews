/*
��Ŀ������
ţţ������һ��n������ɵ�����,ţţ������ȡһ��������������,������������л����������:
���ֻ�ı�һ����,�Ϳ���ʹ�������������������һ���ϸ�������������,ţţ��֪�����������
������ĳ����Ƕ��١�

��������:
�����������,��һ�а���һ������n(1 �� n �� 10^5),�����еĳ���;
�ڶ���n������a_i, ��ʾ�����е�ÿ����(1 �� a_i �� 10^9),�Կո�ָ


�������:
���һ������,��ʾ��ĳ��ȡ�

��������:
6
7 2 3 1 5 6

�������:
5
����˼·:
��̬�滮+�жϡ�
��v[i]��ʼ�������������dp1, v[i]<v[i+1]ʱ��dp1[i] = dp1[i+1]+1;����dp1[i]=1;
��v[i]��β�������������dp2, v[i]>v[i-1]ʱ��dp2[i] = dp2[i-1]+1;����dp2[i]=1;
����ÿһ��λ��i
i=0ʱ��maxLen=dp1[1]+1
i=n-1ʱ��maxLen = dp2[n-2]+1
����:
v[i-1]+1 < v[i+1], maxLen = dp1[i+1]+dp2[i-1]+1����
maxLen = max(dp1[i+1],dp2[i-1])+1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		if (n == 0 || n == 1)
		{
			cout << n << endl;
			continue;
		}
		vector<int> dp1( n, 0 ); //dp1[i]����v[i]��ʼ�������������
		vector<int> dp2( n, 0 ); //dp2[i]����v[i]��β�������������

		dp1[n - 1] = 1;
		for (int i = n - 2; i >= 0; --i)
		{
			if (v[i] < v[i + 1])
				dp1[i] = dp1[i + 1] + 1;
			else
				dp1[i] = 1;
		}

		dp2[0] = 1;
		for (int i = 1; i < n - 1; ++i)
		{
			if (v[i] > v[i - 1])
				dp2[i] = dp2[i - 1] + 1;
			else
				dp2[i] = 1;
		}

		int ret = 1;
		int m = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			if (i == 0)
				m = dp1[i + 1] + 1;
			else if (i == n - 1)
				m = dp2[i - 1] + 1;
			else if (v[i - 1] + 1 < v[i + 1])
				m = dp1[i + 1] + dp2[i - 1] + 1;
			else
				m = max(dp1[i + 1], dp2[i - 1]) + 1;
			if (m > ret)
				ret = m;
		}

		cout << ret << endl;
	}

}