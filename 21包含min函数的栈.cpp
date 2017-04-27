/*
��ָoffer-����min������ջ

����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������

����˼·��
������ջ��һ��ά��ԭʼջ��һ��ά��ԭʼջ�е�ǰ��СԪ�أ��������ջ��pushʱ��
��Ҫ����ǰջ����С��Ԫ��ѹ��ջ��
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