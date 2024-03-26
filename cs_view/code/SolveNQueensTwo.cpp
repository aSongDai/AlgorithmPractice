#include <vector>	
#include <string>
#include <unordered_set>


class Solution
{
public:
	int totalNQueens(int n)
	{
		int result;

		std::vector<int> queensRowInd(n, -1);
		std::unordered_set<int> column;
		std::unordered_set<int> slash;
		std::unordered_set<int> backSlash;

		backTrace(result, queensRowInd, n, 0, column, slash, backSlash); 

		return result;
	}

	void backTrace(int& result, std::vector<int>& queenRowInd, int queenNum, int row, std::unordered_set<int>& column,
		std::unordered_set<int>& slash, std::unordered_set<int>& backSlash)
	{
		if (queenNum == row)
		{
			++result;
		}
		else
		{
			for (int i = 0; i < queenNum; ++i)
			{
				if (column.find(i) != column.end())
				{
					continue;
				}
				int slashSum = row - i;
				if (slash.find(slashSum) != slash.end())
				{
					continue;
				}
				int backSlashSum = row + i;
				if (backSlash.find(backSlashSum) != backSlash.end())
				{
					continue;
				}

				queenRowInd[row] = i;
				column.insert(i);
				slash.insert(slashSum);
				backSlash.insert(backSlashSum);
				backTrace(result, queenRowInd, queenNum, row + 1, column, slash, backSlash);
				queenRowInd[row] = -1;
				column.erase(i);
				slash.erase(slashSum);
				backSlash.erase(backSlashSum);
			}
		}
	}
};