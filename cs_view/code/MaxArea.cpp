#include <vector>
#include <math.h>


class Solution
{
public:
	/*
		给定一个长度为 n 的证书数组 height ， 有 n 条垂线， 
		第 i 条线的两个端点是 (i,0) 和 (i,height[i])
		找出其中的两条线， 使得他们与 x 轴共同构成的容器可以容纳最多的水

		返回容器可以储存的最大水量
	*/
	int maxArea(std::vector<int>& height)
	{
		if (height.size() < 2)	return 0;
		int head = 0, tail = height.size() - 1;
		int answer = (tail - head) * (height[head] > height[tail] ? height[tail] : height[head]);
		while (head != tail)
		{
			if (height[head] > height[tail])
			{
				// move tail
				--tail;
			}
			else
			{
				// move head
				++head;
			}
			int temp = calculateWater((height[head] > height[tail] ? height[tail] : height[head]), tail - head);
			if (temp > answer) answer = temp;
			else continue;
		}
		

		return answer;
	}

	int calculateWater(int minHeight, int distance)
	{
		return minHeight * distance;
	}
};