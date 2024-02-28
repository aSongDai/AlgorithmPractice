#include <vector>


class Solution
{
public:
	int firstMissingPositive(std::vector<int>& nums)
	{
		// time O(n)  space O(1)

		// change nums
		int n = nums.size();
		for (auto& num : nums)
		{
			if (num <= 0)
			{
				num = n + 1;
			}
		}

		for (const auto& num : nums)
		{
			// 这里由于会被修改， 所以如果不求绝对值， 会出现 num[-1] 的这种情况， 所以要求绝对值
			int no = abs(num);	
			if (no <= n)
			{
				nums[no - 1] = -nums[no - 1];
			}
		}

		for (int i = 0 ; i < n ; ++i)
		{
			if (nums[i] > 0)
				return i + 1;
		}

		return n + 1;
	}
};