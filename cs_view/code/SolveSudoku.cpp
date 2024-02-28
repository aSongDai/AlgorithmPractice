#include <vector>	

class Solution
{
public:
	void solveSudoku(std::vector<std::vector<char>>& board)
	{
		std::memset(line, false, sizeof line);
		std::memset(column, false, sizeof column);
		std::memset(block, false, sizeof block);
		valid = false;

		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.')
				{
					// 
					spaces.push_back({i, j});
				}
				else
				{
					int digit = board[i][j] - '0';
					line[i][digit - 1] = column[digit - 1][j] = block[i / 3][j / 3][digit - 1] = true;
				}
			}
		}

		dfs(board, 0);
	}

	void dfs(std::vector<std::vector<char>>& board, int pos)
	{
		if (pos == spaces.size())
		{
			valid = true;
			return;
		}

		auto [i, j] = spaces[pos];					// struct bind (c++17)
		for (int digit = 0; digit < 9 && !valid; ++digit)
		{
			if (!line[i][digit] && !column[digit][j] && !block[i/3][j/3][digit])
			{
				line[i][digit] = column[digit][j] = block[i/3][j/3][digit] = true;
				board[i][j] = digit + '0' + 1;
				dfs(board, pos + 1);
				line[i][digit] = column[digit][j] = block[i/3][j/3][digit] = false;
			}
		}
	}

private:
	bool line[9][9];
	bool column[9][9];
	bool block[3][3][9];
	bool valid;
	std::vector<std::pair<int, int>> spaces;		// ¼ÇÂ¼ÔÚÄÄ¶ù»ØËİ
};