#include <vector>	
#include <algorithm>


class Solution
{
public:
	/*
		��һ������Ϊ n ���������� nums ��һ��Ŀ��ֵ target ����� nums ��ѡ������������ ʹ�ú���ӽ� target

		�����������ĺ�
	*/
	int threeSumClosest(std::vector<int>& nums, int target)
	{
		// ���ʹ�� 0 ����ʼ���� ���ܻᵼ�²�ֵ������ �����²���
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