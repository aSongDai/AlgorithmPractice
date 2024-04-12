#include <vector>

class Solution
{
public:
	/*
		原地算法：
			使用少量或者不适用额外的内存空间来完成算法的设计
	*/
	void setZeroes(std::vector<std::vector<int>>& matrix)
	{
		int rowNum = matrix.size();
		int colNum = matrix[0].size();
		int flag_row0 = false, flag_col0 = false;

		for (int i = 0; i < rowNum; ++i)
		{
			if (!matrix[i][0])
			{
				flag_row0 = true;
				break;
			}
		}

		for (int i = 0; i < colNum; ++i)
		{
			if (!matrix[0][i])
			{
				flag_col0 = true;
				break;
			}
		}


	}
};