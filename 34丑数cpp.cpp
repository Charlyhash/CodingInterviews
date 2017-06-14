/*
��ָoffer-����
��ֻ����������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ�
��Ϊ����������7�� ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������

����˼·��

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {

		if (index == 0)
			return 0;
		if (index == 1)
			return 1;
		vector<int> ugly(index, 0);
		ugly[0] = 1;

		int nextIndex = 1;
		int index2 = 0;
		int index3 = 0;
		int index5 = 0;
		while (nextIndex < index)
		{
			ugly[nextIndex] = min(min(ugly[index2] * 2, ugly[index3] * 3), ugly[index5] * 5);
			
			if (ugly[index2] * 2 <= ugly[nextIndex])
				++index2;
			if (ugly[index3] * 3 <= ugly[nextIndex])
				++index3;
			if (ugly[index5] * 5 <= ugly[nextIndex])
				++index5;

			++nextIndex;
		}

		return ugly[index - 1];
	}

};

int main()
{
	Solution sol;

	cout << sol.GetUglyNumber_Solution(500) << endl;
}



