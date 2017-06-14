/*
��ָoffer:��ΪS����������

��Ŀ����
����һ����������������һ������S���������в������������ǵ����ǵĺ�������S��
����ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
�������:
��Ӧÿ�����԰����������������С���������

����˼·��Ҫ��������������������С��ֻ��Ҫ��������������������������飬Ȼ��
������ָ��ɨ�����飬�������sum���ô������С�����С��sum,����С��������ֱ��
��Ϊsum.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> ret;
		sort(array.begin(), array.end());
		int bigIndex = array.size() - 1;
		int smallIndex = 0;
		while (smallIndex < bigIndex)
		{
			if (array[smallIndex] + array[bigIndex] == sum)
			{
				ret.push_back(array[smallIndex]);
				ret.push_back(array[bigIndex]);
				break;
			}
			else if (array[smallIndex] + array[bigIndex] < sum)
				++smallIndex;
			else
				--bigIndex;

		}
		
		return ret;
	}
};

int main()
{
	vector<int> array{1, 2, 4, 11, 15, 7};
	Solution sol;
	vector<int> ret;
	ret = sol.FindNumbersWithSum(array, 15);
	for (auto i : ret)
		cout << i << " ";
	cout << endl;

	return 0;
}
