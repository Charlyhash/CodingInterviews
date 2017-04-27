/*
剑指offer-旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

题目大意：给定一个数组，该数组时另一有序数组的一个旋转，请输出这个有序
数组的最小值。
解题思路：
1. 没什么思路，直接遍历一遍O(n)
2. 用两个指针，分别指向前后两个元素p1=0,p2=4,mid=(p1+p2)/2
然后比较p1,mid,p2的大小，如果A[p1]<=A[mid],说明mid在左边数组中p1=mid，
如果A[p2]>=A[mid],说明mid在右边的数组中p2=mid.这样时间复杂度为lgn。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int minNumberInRotateArray1(vector<int> rotateArray)
	{
		int len = rotateArray.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return rotateArray[0];
		for (int i = 1; i < len; ++i)
			if (rotateArray[i] < rotateArray[i - 1])
				return rotateArray[i];

		return 0;
	}

	int minNumberInRotateArray(vector<int> rotateArray)
	{
		int len = rotateArray.size();
		if (len == 0)
			return 0;
		int p1 = 0;
		int ret;
		int p2 = len - 1;
		
		while (rotateArray[p1] >= rotateArray[p2])
		{
			if (p2 - p1 == 1)
			{
				ret = rotateArray[p2];
				break;
			}
			int mid = (p2 + p1) / 2;
			if (rotateArray[p1] == rotateArray[p2] && rotateArray[p1]
				== rotateArray[mid])
				return  minNumberInRotateArray(rotateArray);
			if (rotateArray[p1] <= rotateArray[mid])
				p1 = mid;
			else if (rotateArray[p2] >= rotateArray[mid])
				p2 = mid;
		}

		return ret;
	}
};

void test()
{
	vector<int> v{ 6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,
		9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,
		1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,
		5142,5437,5448,5668,5706,5725,6300,6335 };
	Solution sol;
	cout << sol.minNumberInRotateArray(v) << endl;
}

int main()
{
	test();

	return 0;
}