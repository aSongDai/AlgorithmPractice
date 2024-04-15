#include <string>	
#include <vector>	
#include <queue>

class Solution
{
public:

	/*
	// ���� ʱ�䳬��
	std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
	{
		std::vector<int> result;

		int lenNum = nums.size();

		// ʱ�临�Ӷ� O(n * k)
		for (int i = 0; i < lenNum - k; ++i)
		{
			int max = INT_MIN;
			for (int j = 0; j < k; ++j)
			{
				if (nums[i + j] > max)
				{
					max = nums[i + j];
				}
			}
			result.push_back(max);
		}

		return result;
	}
	*/

	std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
	{
		std::priority_queue<std::pair<int, int>> q;

		for (int i = 0; i < k; ++i)
		{
			q.push({ nums[i], i });
		}

		std::vector<int> result = { q.top().first };

		for (int i = k; i < nums.size(); ++i)
		{
			q.push({ nums[i], i });
			while (q.top().second <= i - k)
			{
				q.pop();
			}
			result.push_back(q.top().first);
		}

		return result;
	}
};