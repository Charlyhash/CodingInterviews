/*
剑指offer 构建乘积数组
题目描述：
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素
B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

解题思路：分为两部分计算：C[i]=A[0]*...*A[i], D[i] = A[i]*...A[n-1]
B[i] = C[i-1]*D[i+1]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		
		int len = A.size();
		vector<int> B(len, 0);
		if (len == 0)
			return B;
		vector<int> C(len, 0);
		vector<int> D(len, 0);
		C[0] = A[0];
		for (int i = 1; i < len; ++i)
			C[i] = C[i - 1] * A[i];
		D[len - 1] = A[len - 1];
		for (int i = len - 2; i >= 0; --i)
			D[i] = D[i + 1] * A[i];
		B[0] = D[1];
		B[len - 1] = C[len - 2];
		for (int i = 1; i < len - 1; ++i)
			B[i] = C[i - 1] * D[i + 1];

		return B;
	}
};

int main()
{
	vector<int> v{ 1,2,3,4,5 };
	Solution sol;
	vector<int> ret = sol.multiply(v);
	for (auto i : ret)
		cout << i << " ";

	cout << endl;
	return 0;
}