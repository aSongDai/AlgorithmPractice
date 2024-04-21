#include <string>
#include <iostream>

class Solution
{
public:
	int minAddToMakeValid(const std::string& s)
	{
		int result = 0;
		int leftCount = 0;
		for (const auto ch : s)
		{
			if (ch == '(')
			{
				++leftCount;
			}
			else
			{
				if (leftCount)
				{
					--leftCount;
				}
				else
				{
					++result;
				}
			}
		}
		result += leftCount;
		return result;
	}
};