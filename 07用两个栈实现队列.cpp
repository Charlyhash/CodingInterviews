/*
��ָoffer-������ջ��ʵ��һ������

������ջ��ʵ��һ������,��ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�

����˼·��push����ֻ���push��Ԫ�طŵ���һ��ջ�У�pop������Ҫ�жϵڶ���
ջ�ǲ��ǿգ������Ϊ�գ���ôֱ��pop��Ϊ��Ҫpop��Ԫ�أ����Ϊ�գ���ѵ�һ��
ջ����Ԫ��ȫ����ջ���ڶ���ջ�С�
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