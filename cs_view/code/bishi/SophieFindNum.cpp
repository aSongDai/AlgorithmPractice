#include <vector>	
#include <unordered_map>

class Solution
{
public:
	std::vector<unsigned int> find_nums(const std::vector<unsigned int>& nums)
	{
		std::vector<unsigned int> result;
		std::unordered_map<unsigned int, int> record;
		int minNum = INT_MAX;

		// 
		for (const auto num : nums)
		{
			++record[num];
		}
		// find the min value.
		for (const auto [key, value] : record)		// C++17 structured binding
		{
			if (value < minNum)
			{
				minNum = value;
			}
		}
		// insert the key while value equal minNum
		for (const auto [key, value] : record)
		{
			if (value == minNum)
			{
				result.push_back(key);
			}
		}
		return result;
	}
};