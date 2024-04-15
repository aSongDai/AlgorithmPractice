#include <string>	

class Solution
{
public:
	std::string addBinary(std::string a, std::string b)
	{
		std::string result;

		int lenA = a.size(), lenB = b.size();
		int carry = 0;
		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), b.end());
		int n = std::max(lenA, lenB);
		for (int i = 0; i < n; ++i)
		{
			carry += i < lenA ? (a.at(i) == '1') : 0;
			carry += i < lenB ? (b.at(i) == '1') : 0;
			result.push_back((carry % 2) ? '1' : '0');
			carry /= 2;
		}
		if (carry)	result.push_back('1');
		std::reverse(result.begin(), result.end());

		return result;
	}
};