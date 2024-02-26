#include <vector>	
#include <algorithm>


class Solution
{
public:
	/*
		给一个长度为 n 的整数数组 nums 和一个目标值 target 请你从 nums 中选出三个整数， 使得和最接近 target

		返回三个数的和
	*/
	int threeSumClosest(std::vector<int>& nums, int target)
	{
		// 如果使用 0 来初始化， 可能会导致差值不够大， 而更新不了
		int answer = 1e7, length = nums.size();
		// sort
		std::sort(nums.begin(), nums.end());

		// function
		auto update = [&](int current)
			{
				if (abs(current - target) < abs(answer - target))
				{
					answer = current;
				}
			};
		

		for (int i = 0; i < length; ++i)
		{
			// 
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			int a = nums[i];
			int pb = i + 1, pc = length - 1;
			while (pb < pc)
			{
				int b = nums[pb], c = nums[pc];
				int sum = a + b + c;
				if (sum == target)	return target;
				update(sum);
				
				// 
				if (sum >= target)
				{
					// --pc
					int pt = pc - 1;
					while (pb < pt && nums[pt] == nums[pc])
					{
						--pt;
					}
					pc = pt;
				}
				else
				{
					// ++pb
					int pt = pb + 1;
					while (pc > pt && nums[pt] == nums[pb])
					{
						++pt;
					}
					pb = pt;
				}
			}
		}
		return answer;

	}


	
};