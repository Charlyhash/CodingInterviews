/*
��ָoffer ��ΪS��������������

��Ŀ������
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,
���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ�
���ҳ����к�ΪS��������������? Good Luck!

���������
������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��

����˼·��������ָ��samll��big�ֱ�ָ����������֣�smallӦ��С��(sum+1)/2�����������������
һ�������sum.�����ǰ�ĺʹ���sum������small++,���С��sum����big++,�����Ⱦ��ҵ���һ��
����ע�⣺�����������������������ÿ�ı�smll��bigʱ�����£��������Է������curSum.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> ret;
		if (sum < 3)
			return ret;
		vector<int> tmp;
		int mid = (sum + 1) / 2;
		int small = 1, big = 2;
		int curSum = big + small;
		tmp.push_back(small); tmp.push_back(big);
		while (small < mid)
		{
			if (curSum == sum)
			{
				ret.push_back(tmp);
				tmp.erase(tmp.begin());
				curSum -= small;
				small++;
				//break;
			}
			while (curSum > sum)
			{
				curSum -= small;
				small++;
				tmp.erase(tmp.begin());
				if (curSum == sum)
				{
					ret.push_back(tmp);
					tmp.erase(tmp.begin());
					curSum -= small;
					small++;
					break;
				}
			}
			++big;
			tmp.push_back(big);
			curSum += big;
		}

		return ret;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> ret;
	ret = sol.FindContinuousSequence(15);
	for (auto v : ret)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}