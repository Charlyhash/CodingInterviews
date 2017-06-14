/*
��ָoffer ��ʾ��ֵ���ַ���
��Ŀ������
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬�ַ���"+100","5e2",
"-123","3.1416"��"-1E-16"����ʾ��ֵ�� ����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"
�����ǡ�

����˼·����ȥ���ո�Ȼ����e�ֳ���������,ǰһ���ֿ���ΪС������һ���ֲ�����ΪС����
1. �ж��ǲ���һ����������(�Ѿ���ȥ+/-),�ҵ�С���㣬�������С�����λ���⣬��Ӧ��������

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isNumeric(char* string)
	{
		std::string str(string);
		int pos = 0;
		if (str[pos] == '+' || str[pos] == '-')
		{
			++pos;
			if (pos == str.size())
				return false;
		}
		
		int posE = str.find_first_of('e') + 1 + str.find_first_of('E');
		if (posE != -1)
		{
			//����e,���ж�ǰһ����
			if (!isExponential(str, pos, posE - 1) || posE+1 > str.size()-1)
				return false;
			//��ȥ����λ
			if (str[posE + 1] == '-' || str[posE+1] == '+')
			{
				++posE;
				if (posE > str.size() - 1)
					return false;
			}
			//����Ϊ����
			std::string curStr = str.substr(posE);
			int pos = curStr.find_first_of('.');
			if (pos != -1)
				return false;
			return isExponential(str, posE + 1, str.size() - 1);
		}
		else
			return isExponential(str, pos, str.size() - 1);
	}

private:
	//�ж�һ�����ǲ���С��
	bool isExponential(string str, int pos1, int pos2)
	{
		if (pos1 > pos2)
			return false;
		string curStr = str.substr(pos1, pos2 - pos1 + 1);
		int pos = curStr.find_first_of('.');
		if (pos == curStr.size() - 1)
			return false;
		for (int i = 0; i < curStr.size(); ++i)
			if (i!=pos && !isdigit(curStr[i]))
				return false;
		return true;	
	}
};

int main()
{
	Solution sol;
	cout  << sol.isNumeric("1.2.3") << endl;
	vector<string> v{ "+100","5e2","-123","3.1416","-1E-16",
		"12e","1a3.14","1.2.3","+-5","12e+4.3" };
	for (auto str : v)
	{
		cout << str << ":" << sol.isNumeric(const_cast<char*>(str.c_str())) << endl;
	}

	return 0;
}

