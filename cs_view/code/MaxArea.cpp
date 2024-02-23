#include <vector>
#include <math.h>


class Solution
{
public:
	/*
		����һ������Ϊ n ��֤������ height �� �� n �����ߣ� 
		�� i ���ߵ������˵��� (i,0) �� (i,height[i])
		�ҳ����е������ߣ� ʹ�������� x �Ṳͬ���ɵ�����������������ˮ

		�����������Դ�������ˮ��
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