#include <vector>	
#include <unordered_map>


class Solution
{
public:



	bool lemonadeChange(std::vector<int>& bills)
	{
		std::unordered_map<int, int> have;

		for (const int bill : bills)
		{
			if (bill == 5)
			{
				++have[5];
				continue;
			}
			else if (bill == 10)
			{
				if (!have[5])
				{
					return false;
				}
				else
				{
					++have[10];
					--have[5];
				}
			}
			else if (bill == 20)
			{
				if (have[5] && have[10])
				{
					--have[5];
					--have[10];
				}
				else if (have[5] > 3)
				{
					have[5] -= 3;
				}
				else return false;
			}


		}
		return true;
	}
};