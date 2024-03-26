#include <string>	
#include <iostream>

class Solution
{
public:
	int lengthOfLastWord(const std::string& s)
	{
		int result = 0;
		int findEnd = false;

		std::string::const_iterator charEnd, charBeg = s.begin() , sEnd = s.end();

		for (auto it = sEnd; it != s.begin(); --it)
		{
			if (!findEnd)
			{
				if (*it-1 != ' ')
				{
					charEnd = it;
					findEnd = true;
					std::cout << "CharEnd: " << *it << std::endl;
				}
			}
			else
			{
				if (*it-1 == ' ')
				{
					charBeg = it;
					break;
				}
			}
		}
		
		for (charBeg; charBeg != charEnd; ++charBeg)
		{
			++result;
		}
		
		return result;
	}
};