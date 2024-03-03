#include <vector>	

class Solution
{
public:
	// 
	/*
	int jump(std::vector<int>& nums)
	{
		int n = nums.size();
		std::vector<int> dp(n, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 1; j <= nums[i] && i+j<n; ++j)
			{
				dp[i + j] = dp[i + j] == 0 ? dp[i] + 1 : dp[i + j];
			}
		}
		return dp[n - 1];
	}
	*/

	int jump(std::vector<int>& nums)
	{
		// tan xin
		int n = nums.size(), maxPos = 0, step = 0, end=0;
		for (int i = 0; i < n - 1; ++i)
		{
			maxPos = std::max(maxPos, i + nums[i]);
			if (i == end)
			{
				// 
				end = maxPos;
				++step;
			}
		}
		return step;
	}
};