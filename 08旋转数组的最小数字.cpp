/*
��ָoffer-��ת�������С����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

��Ŀ���⣺����һ�����飬������ʱ��һ���������һ����ת��������������
�������Сֵ��
����˼·��
1. ûʲô˼·��ֱ�ӱ���һ��O(n)
2. ������ָ�룬�ֱ�ָ��ǰ������Ԫ��p1=0,p2=4,mid=(p1+p2)/2
Ȼ��Ƚ�p1,mid,p2�Ĵ�С�����A[p1]<=A[mid],˵��mid�����������p1=mid��
���A[p2]>=A[mid],˵��mid���ұߵ�������p2=mid.����ʱ�临�Ӷ�Ϊlgn��
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