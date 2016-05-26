#include "../include/Board.h"
#include "../include/TerminalSet.h"

void Board::input(int mode, IStream & ifs)
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
	for (int i = 1;i < (int)terminalSets.size(); ++i)
		terminalSets[i] = new TerminalSet(i,this);
	for (int i = 0;i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			if (map[i][j] == -1) block.push_back(Point(i,j));
			else if (map[i][j] > 0)
			terminalSets[map[i][j]]->AddPoint(Point(i,j));
		}	}
	else
	{
		int id;
		while (ifs>>id)
		{
			if (id == EOF) break;
			int x,y;
			int n;
			ifs>>n;
			if (id > 0)
			{
				TerminalSet *terminal = new TerminalSet(id,this);
				for (int i = 1;i <= n; ++i)
				{
					ifs>>x>>y;
					terminal->AddPoint(Point(x,y));
					map[x][y] = id;
				}
				terminalSets.push_back(terminal);
			}
			else if (id == -1)
			{
				for (int i = 1;i <=n; ++i)
				{
					ifs>>x>>y;
					block.push_back(Point(x,y));
					map[x][y] = -1;
				}
			}
				
		}
	}
}

void Board::output(int mode, OStream &ofs)
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
			ofs<<i<<' '<<terminalSets[i]->points.size()<<'\n';
			for (int j = 0;j < (int)terminalSets[i]->points.size(); ++j)
				ofs<<terminalSets[i]->points[j].x<<' '<<terminalSets[i]->points[j].y<<' '<<'\n';
		}
		ofs<<-1<<' '<<block.size()<<'\n';
		for (int i = 0;i < (int)block.size(); ++i)
			ofs<<block[i].x<<' '<<block[i].y<<'\n';
	}
}