/*
剑指offer-数组中的逆序对

题目大意:在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个
逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输
出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5


输入例子:
1,2,3,4,5,6,7,0

输出例子:
7

解题思路：逆序数对求法
1. 归并排序。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	long InversePairsCore(vector<int> &data, vector<int> &copy, long start, long end) {
		if (start == end)  // copy: 辅助数组
		{
			return 0;  // 递归终止条件
		}

		long mid = (start + end) / 2;
		long left = InversePairsCore(copy, data, start, mid); // 递归，归并排序，并计算本次逆序对数
		long right = InversePairsCore(copy, data, mid + 1, end);
		long crossCount = 0;       // 记录交叉的逆序对数
		long i = mid, j = end, temp = end;  //i：前半部分的下标，j：后半部分的下标，temp：辅助数组的下标

		while (i >= start && j >= mid + 1) {   // 存在交叉的逆序对，先统计一下，然后依次将较大值放进辅助数组
			if (data[i] > data[j]) {
				copy[temp--] = data[i--];
				crossCount += j - start - (mid - start);
			}
			else {
				copy[temp--] = data[j--];   // 不存在交叉的逆序对，依次将较大值放进辅助数组
			}
		}
		while (i >= start) {
			copy[temp--] = data[i--];
		}
		while (j >= mid + 1) {
			copy[temp--] = data[j--];
		}
		return (left + right + crossCount) % 1000000007; //数值过大时求余, 防止溢出
	}
	int InversePairs(vector<int> &data) {
		if (data.size() <= 1) return data.size();
		else {
			vector<int> copy(data);
			return InversePairsCore(copy, data, 0, data.size() - 1);
		}
	}
};

int main()
{
	Solution sol;
	vector<int> v{ 364,637,341,406,747,995,234,971,571,219,993,407,416,366,
		315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,
		588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,
		256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,
		259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,
		848,38,811,267,575 };
	cout << sol.InversePairs(v) << endl;

	return 0;
}
