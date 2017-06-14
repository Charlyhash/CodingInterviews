/*
剑指offer-丑数
把只包含素因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，
因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

解题思路：

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



