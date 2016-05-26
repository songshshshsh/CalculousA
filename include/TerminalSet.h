#ifndef TERMIANLSET_H
#define TERMINALSET_H

#include "global.h"
#include "Board.h"

class TerminalSet
{	
private:
	const Board* board;
	const int id;
	TerminalSet &operator =(const TerminalSet &);
public:
	Vector<Point> points;
	TerminalSet(int id_,const Board* board_):id(id_)
	{
		board = board_;
	}
	inline void AddPoint(Point point)
	{	
		points.push_back(point);
	}
};

#endif