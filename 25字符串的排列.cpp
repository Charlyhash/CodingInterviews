/*
��ָoffer-�ַ���������

����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���
abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��
cba��
��������:
����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��


����˼·���ݹ�
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> ret;
		if (str.size() == 0)
			return ret;
		DFS(ret, 0, str);

		return ret;
	}

	void DFS(vector<string>& ret, int k, string str)
	{
		if (k == str.size() - 1) //�˳�����
			ret.push_back(str);
		unordered_set<char> uset;//��Ҫ�ظ�
		sort(str.begin() + k, str.end());//����
		for (int i = k; i < str.size(); ++i)
		{
			if (uset.find(str[i]) == uset.end())
			{
				uset.insert(str[i]);
				swap(str[i], str[k]);
				DFS(ret, k + 1, str);
				swap(str[i], str[k]);//��λ
			}
		}
	}
};

int main()
{
	Solution sol;
	vector<string> ret = sol.Permutation("aba");

	for (auto str : ret)
		cout << str << endl;
	return 0;
}