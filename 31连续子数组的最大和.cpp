/*
剑指offer-连续子数组的最大和

题目描述:HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又
发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,
问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它
呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你
会不会被他忽悠住？(子向量的长度至少是1)

解题思路：记住前的最大值pre和当前最大值cur。如果下一个数是负数，那么前一个最大值

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
		int curSum = 0;//当前最大值
		int maxSum = -0x3f3f3f3f;//全局最大值
		for (int i = 0; i < len; ++i)
		{
			if (curSum <= 0)
				curSum = array[i];//如果以i-1结尾的最大值为负数，那么当前最大值位array[i]
			else
				curSum += array[i];
			maxSum = max(maxSum, curSum);//更新全局最大值
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