

class Solution
{
public:
	// 无序序列 arrA， arrB 实现两个序列的交集， 有交集返回true， 无返回false
	bool combine(const int* arrA, int lenA, const int* arrB, int lenB, int*& buf, int& buf_len)
	{
		// 时间复杂度 O(lenA * lenB)  空间复杂度O(1)
		bool result = false;
		for (int i = 0; i < lenA; ++i)
		{
			int current = arrA[i];
			for (int j = 0; j < lenB; ++j)
			{
				if (current == arrB[j])
				{
					buf[buf_len] = current;
					++buf_len;
					result = true;
					break;
				}
			}
		}
		return result;
	}
};