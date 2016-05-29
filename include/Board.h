#ifndef BOARD_H
#define BOARD_H

#include "global.h"
#include "TerminalSet.h"

class Board
{
public:
	int height, width;
	Vector<TerminalSet *> terminalSets;
	Matrix<int> map;
	Vector<Point> blocks;
	~Board();
	void input(int mode=0, IStream &ifs=cin);
	void output(int mode=0, OStream &ofs=cout) const;
};

#endif