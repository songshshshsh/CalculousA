#include "../include/Board.h"

void Board::input(int mode, ifstream & ifs)
{
	if (mode == 0)
	{
		//input the size of the board
		ifs>>height>>width;
		map.resize(height,width);
		//input every element of the board
		int maxindex = 0;
		for (int i = 0;i < height; ++i)
			for (int j = 0; j < width; ++j)
			{
				ifs>>map[i][j];
				maxindex = max(maxindex,map[i][j]);
			}
	terminalSets.resize(maxindex+1);
	for (int i = 0;i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			if (map[i][j] == -1) block.push_back(Point(x,y));
			else if (map[i][j] > 0)
			terminalSets[map[i][j]]->AddPoint(i,j);
		}
		for (int i = 1;i < (int)terminalSets.size(); ++i)
		{
			terminalSets[i]->id = i;
			terminalSets[i]->board = this;
		}
	}
	else
	{
		int id;
		while (ifs>>id)
		{
			if (id == EOF) break;
			int x,y;
			if (id > 0)
			{
				int n;
				ifs>>n;
				Terminal *terminal = new TerminalSets(id,n);
				for (int i = 0;i < n; ++i)
				{
					ifs>>x>>y;
					terminal.AddPoint(x,y);
					map[x][y] = id;
				}
				terminalSets.push_back(terminal);
			}
			else if (id == -1)
			{
				ifs>>n;
				for (int i = 0;i < n; ++i)
				{
					ifs>>x>>y;
					blocks.push_back(Point(x,y));
					map[x][y] = -1;
				}
			}
				
		}
	}
}

void Board::output(int mode, ofstream &ofs)
{
	if (mode == 0)
	{
		ofs<<height<<' '<<width<<'\n';
		for (int i = 0;i < height; ++i)
		{
			for (int j = 0;j < width; ++j)
				ofs<<map[i][j]<<' ';
			ofs<<'\n';
		}
	}
	else
	{
		for (int i = 1;i < (int)terminalSets.size(); ++i)
		{
			ofs<<i<<'\n';
			for (int j = 0;j < terminalSets[i].size(); ++j)
				ofs<<x<<' '<<y<<' '<<'\n';
		}
	}
}