#ifndef TERMIANLSET_H
#define TERMINALSET_H

#include "global.h"

class TerminalSet
{
private:
	Vector<Point> points;
	const Board* board;
	int id;
public:
	TerminalSet(int,int);
	inline void AddPoint(Point point)
	{
		points.push_back(point);
	}
};

#endif