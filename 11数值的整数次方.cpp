/*
��ָoffer-��ֵ�������η�

����һ��double���͵ĸ�����base��int���͵�����exponent��
��base��exponent�η���

����˼·������exp������

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool equals(double e1, double e2)
{
	if (abs(e1 - e2) < 0.000001)
		return true;
	else
		return false;
}

class Solution {
public:
	double Power(double base, int exponent) {
		if (equals(base, 0.0) && exponent == 0)
			return 0;
		if (equals(base, 0.0))
			return 0;
		if (exponent == 1)
			return base;
		if (exponent == 0)
			return 1;

		double ret = 1;
		if (exponent > 0)
		{
			while (exponent--)
				ret *= base;
		}
		else
		{
			exponent = -1 * exponent;
			while (exponent--)
			{
				ret *= base;
			}

			ret = 1.0 / ret;
		}

		return ret;
	}
};

int main()
{
	Solution sol;
	cout << sol.Power(1.5, 2) << endl;
	cout << sol.Power(1.5, -2) << endl;
	cout << sol.Power(0, 2) << endl;
	cout << sol.Power(1.5, 0) << endl;
}