/*
剑指offer-包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

解题思路：
用两个栈，一个维护原始栈，一个维护原始栈中当前最小元素，这个辅助栈在push时，
需要将当前栈中最小的元素压入栈。
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	void push(int value) {
		stk.push(value);
		if (stk_min.empty())
			stk_min.push(value);
		else
		{
			int tmp = stk_min.top();
			if (value > tmp)
				stk_min.push(tmp);
			else
				stk_min.push(value);
		}
	}
	void pop() {
		stk.pop();
		stk_min.pop();
	}
	int top() {
		return stk.top();
	}
	int min() {
		return stk_min.top();
	}

private:
	stack<int> stk;
	stack<int> stk_min;
};

int main()
{
	Solution sol;
	sol.push(3);
	sol.push(2);
	sol.push(4);
	cout << sol.min() << endl;
	sol.pop();
	cout << sol.min() << endl;
	sol.push(5);
	cout << sol.min() << endl;
	sol.pop();
	sol.pop();
	cout << sol.min() << endl;
}