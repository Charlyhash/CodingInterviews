/*
剑指offer 表示数值的字符串
题目描述：
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2",
"-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"
都不是。

解题思路：先去掉空格，然后用e分成两个部分,前一部分可以为小数，后一部分不可以为小数。
1. 判断是不是一个正常的数(已经出去+/-),找到小数点，除了这个小数点的位以外，都应该是数字

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
			//包含e,先判断前一部分
			if (!isExponential(str, pos, posE - 1) || posE+1 > str.size()-1)
				return false;
			//出去符号位
			if (str[posE + 1] == '-' || str[posE+1] == '+')
			{
				++posE;
				if (posE > str.size() - 1)
					return false;
			}
			//必须为整数
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
	//判断一个数是不是小数
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

