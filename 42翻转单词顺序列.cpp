/*
��ָoffer : ��ת����˳����
��Ŀ���⣺ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼�����磬
��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ����
��I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��

����˼·��
������reverse��Ȼ���ҵ��ո�Ȼ��reverse.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		if (str.size() < 2)
			return str;
		reverse(str.begin(), str.end());

		int p1 = 0, p2 = 0;
		while (p2 < str.size())
		{
			while (str[p2] != ' ' && p2 < str.size())
				++p2;
			reverse(str.begin() + p1, str.begin() + p2);
			p1 = p2 + 1;
			p2 = p1;
		}

		return str;
	}
};

int main()
{
	string s("student. a am I");
	Solution sol;
	string str = sol.ReverseSentence(s);
	cout << str << endl;

	return 0;
}
