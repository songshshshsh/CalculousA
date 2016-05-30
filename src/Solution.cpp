#include "../include/Solution.h"

OStream &operator <<(OStream &ost, const Solution &solution)
{
	ost << "Solution\n";
	// for(auto &row: solution.map)
	// {
		// for(auto col: row)
			// ost << col << " ";
		// ost << "\n";
	// }
	int n = solution.board->height, m = solution.board->width;
	const Matrix<int> &map = solution.board->map;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(solution.map[i][j] == -1)
				ost << " X ";
			else if(solution.map[i][j] == 0)
				ost << "   ";
			else if(map[i][j])
				ost << "[" << solution.map[i][j] - 1 << "]";
			else
				ost << " " << solution.map[i][j] - 1 << " ";
		}
		ost << "\n";
	}
	return ost;
}

void Solution::computeMap()
{
	map.resize(board->height,board->width);
	for (int i = 1;i < (int) trees.size(); ++i)
	{
		if (trees[i] != NULL)
		{
			for (int j = 0;j < board->height; ++j)
				for (int k = 0;k < board->width; ++k)
					map[j][k] += trees[i]->map.get(j,k) * i;
		}
	}
	for(auto block: board->blocks)
		map[block] = -1;
	// for (int i = 0;i < (int)board->blocks.size(); ++i)
		// map[board->blocks[i].x][board->blocks[i].y] = -1;
}