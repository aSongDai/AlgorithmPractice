#include <vector>	

class Solution
{
public:
	int trap(std::vector<int>& height)
	{
		// no limits
		// 
		int result = 0;
		int n = height.size();
		std::vector<int> maxLeft(n, 0), maxRight(n, 0);
		maxLeft[0] = height[0];
		maxRight[n - 1] = height[n - 1];
		
		for (int i = 1; i < n; ++i)
		{
			// update maxLeft
			maxLeft[i] = std::max(maxLeft[i - 1], height[i]);
		}

		for (int i = n - 2; i >= 0; --i)
		{
			// update maxRight
			maxRight[i] = std::max(maxRight[i + 1], height[i]);
		}

		for (int i = 0; i < n; ++i)
		{
			result += std::min(maxLeft[i], maxRight[i]) - height[i];
		}

		return result;
	}
};