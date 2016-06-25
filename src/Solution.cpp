#include "../include/Solution.h"
#include "../include/IntArray2bmp.h"
#include "../include/global.h"

Solution::Solution(const Solution& _solution)
{
	for (unsigned i = 0;i < _solution.trees.size();++i)
	{
		if(_solution.trees[i] == NULL)
			this->trees.push_back(NULL);
		else
		{
			Tree* _tree = new Tree();
			_tree->terminalSet = _solution.trees[i]->terminalSet;
			_tree->map = _solution.trees[i]->map;
			_tree->length = _solution.trees[i]->length;
			this->trees.push_back(_tree);
		}
	}
	this->board = _solution.board;
	this->map = _solution.map;
}

Solution::~Solution()
{
	for (unsigned i = 0;i < this->trees.size();++i)
		if (this->trees[i])
		delete this->trees[i];
}

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
			else if(map[i][j] == solution.map[i][j])
				ost << "[" << solution.map[i][j] - 1 << "]";
			else
				ost << " " << solution.map[i][j] - 1 << " ";
		}
		ost << "\n";
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(solution.map[i][j] == -1)
				ost << "-1 ";
			else if(solution.map[i][j] == 0)
				ost << "0 ";
			else if(map[i][j] == solution.map[i][j])
				ost << solution.map[i][j] << " ";
			else
				ost << solution.map[i][j] + 100000 << " ";
		}
		ost << "\n";
	}
	std::set<int> index;
	index.insert(-1);
	int** pic = new int*[n];
	for (int i = 0;i < n; ++i) 
		pic[i] = new int[m];
	for (int i = 0;i < n; ++i)
		for (int j = 0;j < m; ++j)
		{
			int &p = pic[i][j];
			if(solution.map[i][j] == -1)
				p = -1;
			else if(solution.map[i][j] == 0)
				p = 0;
			else if(map[i][j] == solution.map[i][j])
				p = solution.map[i][j];
			else
				p = solution.map[i][j] + 100000;
			index.insert(p);
		}
	for (int i = 0;i < n; ++i)
		for (int j = 0;j < m; ++j)
			pic[i][j] = std::distance(index.begin(),index.find(pic[i][j]));
			// if (pic[i][j] == -1) pic[i][j] = index.size() - 1;
	int min = 0,max = index.size() - 1;
	char fileName[256];
	int len = strftime(fileName, sizeof(fileName), "%Y%m%d%H%M%S", localtime((const time_t *) time(NULL)));
	sprintf(fileName + len, "_%010d", (int) clock());
	if (intarray2bmp::intarray2bmp(fileName,pic,n,m,min,max))
		ost<<"picture saved to " << fileName << "\n";
	for (int i = 0;i < n; ++i) 
		delete[] pic[i];
	delete[] pic;
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