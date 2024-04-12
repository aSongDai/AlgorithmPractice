#include <string>	

class Solution
{
public:
	std::string addBinary(const std::string& a, const std::string& b)
	{
		std::string result;

		int lenA = a.size(), lenB = b.size();
		int count = 0;

		int n = lenA < lenB ? lenA : lenB;
		auto ap = a.end() - 1, bp = b.end() - 1;
		while (n--)
		{
			int temp = *ap - '0' + *bp - '0' + count;
			if (temp > 1)
			{
				count = 1;
				result.push_back(temp % 2 + '0');
			}
			else
			{
				count = 0;
				result.push_back(temp + '0');
			}
		}
		if (ap == a.begin())
		{
			// bp
			while (bp != b.begin())
			{

			}
		}
		else
		{
			// ap
			while (ap != a.begin())
			{

			}
		}

		std::reverse(result.begin(), result.end());

		return result;
	}
};