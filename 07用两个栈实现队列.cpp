/*
剑指offer-用两个栈来实现一个队列

用两个栈来实现一个队列,完成队列的Push和Pop操作。 队列中的元素为int类型。

解题思路：push操作只需把push的元素放到第一个栈中，pop操作需要判断第二个
栈是不是空，如果不为空，那么直接pop记为需要pop的元素，如果为空，则把第一个
栈所有元素全部入栈到第二个栈中。
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int ret;
		if (!stack2.empty())
		{
			ret = stack2.top();
			stack2.pop();
		}
		else
		{
			int tmp;
			while (!stack1.empty())
			{
				tmp = stack1.top(); stack1.pop();
				stack2.push(tmp);
			}
			ret = stack2.top(); stack2.pop();
		}

		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

void TEST()
{
	Solution sol;
	sol.push(1); sol.push(2);
	cout << sol.pop() << endl;
	sol.push(3); sol.push(4);
	cout << sol.pop() << endl;
	cout << sol.pop() << endl;
	cout << sol.pop() << endl;
}

int main()
{
	TEST();

	return 0;
}