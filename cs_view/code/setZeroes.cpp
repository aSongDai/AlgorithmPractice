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
				flag_col0 = true;
				break;
			}
		}

		for (int i = 0; i < colNum; ++i)
		{
			if (!matrix[0][i])
			{
				flag_row0 = true;
				break;
			}
		}

		// 将 0 元素置换到 第一行或者第一列
		for (int i = 1; i < rowNum; ++i)
		{
			for (int j = 1; j < colNum; ++j)
			{
				if (!matrix[i][j])
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		/*
			将 中间的元素 置为0
		*/
		for (int i = 1; i < rowNum; ++i)
		{
			for (int j = 1; j < colNum; ++j)
			{
				if (!matrix[i][0] || !matrix[0][j])
					matrix[i][j] = 0;
			}
		}


		if (flag_col0)
		{
			for (int i = 0; i < rowNum; ++i)
			{
				matrix[i][0] = 0;
			}
		}

		if (flag_row0)
		{
			for (int i = 0; i < colNum; ++i)
			{
				matrix[0][i] = 0;
			}
		}


	}
};