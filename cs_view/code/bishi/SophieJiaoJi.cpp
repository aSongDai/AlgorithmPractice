

class Solution
{
public:
	// �������� arrA�� arrB ʵ���������еĽ����� �н�������true�� �޷���false
	bool combine(const int* arrA, int lenA, const int* arrB, int lenB, int*& buf, int& buf_len)
	{
		// ʱ�临�Ӷ� O(lenA * lenB)  �ռ临�Ӷ�O(1)
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