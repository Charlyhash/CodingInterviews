/*
��ָoffer-���������������

��Ŀ����:HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,����
������:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,
����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ���
�أ�����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����
�᲻�ᱻ������ס��(�������ĳ���������1)

����˼·����סǰ�����ֵpre�͵�ǰ���ֵcur�������һ�����Ǹ�������ôǰһ�����ֵ

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) 
	{
		int len = array.size();
		if (len == 0)
			return 0;
		vector<int> dp(len, 0);
		dp[0] = array[0];
		for (int i = 1; i < len; ++i)
		{
			if (dp[i - 1] > 0)
				dp[i] = array[i] + dp[i - 1];
			else
				dp[i] = array[i];
			//cout << dp[i] << endl;
		}

		return *max_element(dp.begin(), dp.end());
	}

	int FindGreatestSumOfSubArray2(vector<int> array)
	{
		int len = array.size();
		if (len == 0)
			return 0;
		int curSum = 0;//��ǰ���ֵ
		int maxSum = -0x3f3f3f3f;//ȫ�����ֵ
		for (int i = 0; i < len; ++i)
		{
			if (curSum <= 0)
				curSum = array[i];//�����i-1��β�����ֵΪ��������ô��ǰ���ֵλarray[i]
			else
				curSum += array[i];
			maxSum = max(maxSum, curSum);//����ȫ�����ֵ
		}

		return maxSum;
	}
};

int main()
{
	Solution sol;
	vector<int> array{1,-2,3,10,-4,7,2,-5};
	//cout << sol.FindGreatestSumOfSubArray(array) << endl;
	cout << sol.FindGreatestSumOfSubArray2(array) << endl;
	return 0;
}