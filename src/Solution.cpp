#include "../include/Solution.h"

OStream &operator <<(OStream &ost, const Solution &solution)
{
	ost << "Solution\n";
	for(auto &row: solution.map)
	{
		for(auto col: row)
			ost << col << " ";
		ost << "\n";
	}
	return ost;
}

void Solution::computeMap()
{
	map.resize(board->height,board->weight);
	for (int i = 1;i < trees.size(); ++i)
	{
		if (trees[i] != NULL)
		{
			for (int j = 0;j < board->height; ++j)
				for (int k = 0;k < board->weight; ++k)
					map[j][k] += trees[i]->map.get(j,k) * i;
		}
	}
	for (int i = 0;i < board->block.size(); ++i)
		map[block[i].x][block[i].y] = -1;
}