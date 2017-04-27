/*
剑指offer-栈的压入、弹出序列
输入两个整数序列，第一个序列表示栈的压入顺序，
请判断第二个序列是否为该栈的弹出顺序。假设压入
栈的所有数字均不相等。例如序列1,2,3,4,5是某栈
的压入顺序，序列4，5,3,2,1是该压栈序列对应的一
个弹出序列，但4,3,5,1,2就不可能是该压栈序列的
弹出序列。（注意：这两个序列的长度是相等的）

解题思路：先入栈，然后看栈顶元素与压出序列访问位置
的数是否相等，不相等就继续入栈，相等的话，就弹出，
再处理后续的序列。
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool IsPopOrder1(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int p1 = 0;
		int p2 = 0;
		while (p2 < popV.size())
		{
			if (s.empty())
			{
				if (p1 >= pushV.size())
					break;
				s.push(pushV[p1++]);
			}
			else
			{
				if (s.top() == popV[p2])
				{
					s.pop();
					p2++;
				}
				else
				{
					if (p1 >= pushV.size())
						break;
					s.push(pushV[p1++]);
				}
			}
		}
		
		return (p1 == pushV.size() && p2 == popV.size());
	}

	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() == 0)
			return false;
		vector<int> stack;
		for (int i = 0, j = 0; i < pushV.size();)
		{
			stack.push_back(pushV[i++]);
			while (j < popV.size() && stack.back() == popV[j])
			{
				++j;
				stack.pop_back();
			}
		}

		return stack.empty();
	}
};

int main()
{
	vector<int> v1{ 1,2,3,4,5 };
	vector<int> v2{ 4,5,2,3,1 };
	Solution sol;
	cout << sol.IsPopOrder(v1, v2) << endl;
}

