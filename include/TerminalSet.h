#ifndef TERMIANLSET_H
#define TERMINALSET_H

#include "global.h"
class Board;
// #include "Board.h"

class TerminalSet
{	
private:
	TerminalSet &operator =(const TerminalSet &);
public:
	const Board* board;
	Vector<Point> points;
	const int id;
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